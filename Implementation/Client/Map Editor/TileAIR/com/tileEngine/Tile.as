package com.tileEngine {
	
	import flash.display.Sprite;
	import flash.display.Bitmap;
	import flash.display.MovieClip;
	import flash.events.MouseEvent;
	import flash.events.Event;
	import flash.display.BitmapData;
	
	public class Tile extends MovieClip {
		public static var width:int = 32; //Default width
		public static var height:int = 32; //Default height
		
		public static var tilebmpData:BitmapData = new BitmapData(32,32,false,0x005500);
		private var tileTexture:Bitmap; //Texture data for the tile
		
		private var clickable:Boolean; //Whether or not this tile is clickable
		private var influence:uint; //0 = Neutral, 1 = Chaos, 2 = Divine
		private var ID:uint;
		
		private var xPosition:uint;
		private var yPosition:uint;
		
		public function Tile(xPos:uint, yPos:uint) 
		{
			xPosition = xPos;
			yPosition = yPos;
			this.addEventListener(Event.ADDED, initializeTile);
			this.addEventListener(MouseEvent.MOUSE_OVER, onMouseDown);
			this.addEventListener(MouseEvent.MOUSE_UP, onMouseUp);
			this.addEventListener(MouseEvent.MOUSE_DOWN, onMouseClick);
			
		}
		
		private function initializeTile(e:Event)
		{
			tileTexture = new Bitmap(tilebmpData);
			this.buttonMode = true;
			clickable = false;
			
			this.graphics.lineStyle(1, 0x000000,1.0);
			fillTileWithSelection(tilebmpData);
		}
		
		private function onMouseDown(e:MouseEvent)
		{
			//tilebmpData = new rock;
			if(Layer.mouseDown){
				if(Layer.currentSelectionBMP != null){
					fillTileWithSelection(tilebmpData); //Clear the current tile and set it to the default tile data
					fillTileWithSelection(Layer.currentSelectionBMP); //Sets the current tile to the users selection on the spritesheet
					ID = Layer.currentSelectionID;
					trace(ID);
				}
				else{
					trace("Please Select A Bitmap");
				}
			}
		}
		
		private function onMouseUp(e:MouseEvent)
		{
			
		}
		private function onMouseClick(e:MouseEvent){
				if(Layer.currentSelectionBMP != null){
					fillTileWithSelection(tilebmpData); //Clear the current tile and set it to the default tile data
					fillTileWithSelection(Layer.currentSelectionBMP); //Sets the current tile to the users selection on the spritesheet
					ID = Layer.currentSelectionID;
					trace(ID);
				}
				else{
					trace("Please Select A Bitmap");
				}
		}
		
		private function fillTileWithSelection(bmpData:BitmapData){
			this.graphics.beginBitmapFill(bmpData);
			this.graphics.drawRect(xPosition,yPosition,32,32);
			this.graphics.endFill();
		}
		
	

	}
	
}
