package com.tileEngine {
	
	import com.tileEngine.*;
	import flash.display.MovieClip;
	import flash.events.Event;
	import flash.display.BitmapData;
	import flash.display.Bitmap;
	import flash.display.*;
	import flash.geom.Rectangle;
	import flash.geom.Point;
	import flash.events.MouseEvent;
	import flash.events.KeyboardEvent;
	
	
	public class Layer extends MovieClip{
		internal static var leftDown:Boolean;
		internal static var rightDown:Boolean;
		
		public static var currentSelectionBMP:BitmapData;
		public static var currentSelectionID:uint;
		public static var layerBitmapData:BitmapData; //This will be drawn to directly by other classes. This of this as our base canvas.
		
		private var layerBitmap:Bitmap; //Bitmap that houses the above BitmapData and draws it to the screen
		private var layerType:String;
		private var tileArray:Array; //Array of tiles dependent on the parameters passed through in main
		private var tile:Bitmap = new Bitmap(new defaultTile); //Bitmap that changes depending on the layer type. For visual representation.
		private var defaultBMP:BitmapData;		
		private var WIDTH;
		private var HEIGHT;
		
		public function Layer(layerWidth:uint, layerHeight:uint, _layerType:String) {
			WIDTH = layerWidth;
			HEIGHT = layerHeight;
			layerType = _layerType;
			tileArray = new Array(WIDTH*HEIGHT);
			
			//Switch the tile bitmap based on the layer being drawn
			switch(layerType){
				case LayerEnum.ARTBACKGROUND:
					defaultBMP = tile.bitmapData;
				break;
				case LayerEnum.COLLISION:
					defaultBMP = new BitmapData(32,32,true,0x25000090);
				break;
			}
			
			EventListeners();
		}
		
		//Sets up all of the event listeners for the layers
		private function EventListeners(){
			this.addEventListener(Event.ADDED_TO_STAGE, initialSetup);
			this.addEventListener(MouseEvent.MOUSE_DOWN, mouseDownListener);
			this.addEventListener(MouseEvent.MOUSE_UP, mouseUpListener);
			this.addEventListener(MouseEvent.RIGHT_MOUSE_DOWN, rightDownListener);
			this.addEventListener(MouseEvent.RIGHT_MOUSE_UP, rightUpListener);
		}
				
		private function initialSetup(e:Event){
				layerBitmapData = new BitmapData(stage.stageWidth,stage.stageHeight,false,0x999999);
				layerBitmap = new Bitmap(layerBitmapData);
				addChild(layerBitmap);
				drawTilesOnBitmap();			
		}	
		private function drawTilesOnBitmap(){
			var xPos:uint = 0;
			var yPos:uint = 0;
			
			for(var i:int = 0; i < tileArray.length; i++){
				if(i % WIDTH == 0 && i > 0){
					yPos++;
					xPos = 0;
				}
				tileArray[i] = new Tile(xPos*32, yPos*32, defaultBMP);
				addChild(tileArray[i]);
				xPos++;
			}
		}
		private function mouseDownListener(e:MouseEvent){leftDown = true;}
		private function mouseUpListener(e:MouseEvent){leftDown = false;}	
		private function rightDownListener(e:MouseEvent){rightDown = true;}
		private function rightUpListener(e:MouseEvent){rightDown = false;}
	}		
}
