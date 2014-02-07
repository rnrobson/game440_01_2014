package com.tileEngine {
	
	import com.tileEngine.Tile;
	import flash.display.MovieClip;
	import flash.events.Event;
	import flash.display.BitmapData;
	import flash.display.Bitmap;
	import flash.display.*;
	import flash.geom.Rectangle;
	import flash.geom.Point;
	import flash.events.MouseEvent;
	
	
	public class Layer extends MovieClip{
		internal static var mouseDown:Boolean;
		public static var currentSelectionBMP:BitmapData;
		public static var currentSelectionID:uint;
		
		private var layerBitmapData:BitmapData; //This will be drawn to directly by other classes. This of this as our base canvas.
		private var layerBitmap:Bitmap; //Bitmap that houses the above BitmapData and draws it to the screen
		
		
		private var tileArray:Array; //Array of tiles dependent on the parameters passed through in main
		
		private var xPos:uint = 0; //For use in the forLoop + Sent to the Tile to be stored
		private var yPos:uint = 0; //For use in the forLoop + Sent to the Tile to be stored
		
		private var WIDTH;
		private var HEIGHT;
		
		public function Layer(layerWidth:uint, layerHeight:uint) {
			WIDTH = layerWidth;
			HEIGHT = layerHeight;
			tileArray = new Array(WIDTH*HEIGHT);
			this.addEventListener(Event.ADDED_TO_STAGE, initialSetup);
			this.addEventListener(MouseEvent.MOUSE_DOWN, mouseDownListener);
			this.addEventListener(MouseEvent.MOUSE_UP, mouseUpListener);
		}
				
		private function initialSetup(e:Event){
			layerBitmapData = new BitmapData(stage.stageWidth,stage.stageHeight,false,0xFF0000);
			layerBitmap = new Bitmap(layerBitmapData);
			addChild(layerBitmap);
			drawTilesOnBitmap();
			
		}	
		private function drawTilesOnBitmap(){
			for(var i:int = 0; i < tileArray.length; i++){
				if(i % WIDTH == 0 && i > 0){
					yPos++;
					xPos = 0;
				}
				tileArray[i] = new Tile(xPos*32, yPos*32);
				addChild(tileArray[i]);
				xPos++;
			}
		}
		private function mouseDownListener(e:MouseEvent){
			mouseDown = true;
		}
		private function mouseUpListener(e:MouseEvent){
			mouseDown = false;
		}

	}

		
}
