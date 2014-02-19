package com.tileEngine {
	
	import flash.display.Sprite;
	import flash.display.Bitmap;
	import flash.display.MovieClip;
	import flash.events.MouseEvent;
	import flash.events.Event;
	import flash.display.BitmapData;
	import com.tileEngine.LayerEnum;
	import flash.geom.Rectangle;
	
	public class Tile extends MovieClip {
		public static var width:int = 32; //Default width
		public static var height:int = 32; //Default height
		
		public var xPosition:uint;
		public var yPosition:uint;
		public var ID:uint = DEFAULT_ID; //999 by default to avoid problems with spritesheets
		public var clickable:Boolean = true; //Whether or not this tile is clickable
		
		private const DEFAULT_ID:uint = 999;
		private var tilebmpData:BitmapData;
		//private var influence:uint; //0 = Neutral, 1 = Chaos, 2 = Divine
		
		public function Tile(xPos:uint, yPos:uint, bmpData:BitmapData){
			xPosition = xPos;
			yPosition = yPos;
			tilebmpData = bmpData;	
			EventListeners();
		}
		
		//Sets up all of the event listeners for the tile
		private function EventListeners(){
			this.addEventListener(Event.ADDED, initializeTile);
			this.addEventListener(MouseEvent.MOUSE_OVER, onMouseDown);
			this.addEventListener(MouseEvent.MOUSE_DOWN, onLeftClick);
			this.addEventListener(MouseEvent.RIGHT_CLICK, onRightClick);		
		}
		
		//Initialize the tile with these values..
		private function initializeTile(e:Event){
			this.buttonMode = true;
			this.graphics.lineStyle(1, 0x000000,1.0);
			fillTileWithSelection(tilebmpData);
		}
		
		//Mouse Listener Events..
		private function onMouseDown(e:MouseEvent){
			if(Layer.leftDown){
				drawTile();
			}
			else if(Layer.rightDown){
				clearTile();
			}
		}
		private function onLeftClick(e:MouseEvent){
			drawTile();
		}
		private function onRightClick(e:MouseEvent){
			trace(clickable);
			clearTile();
		}
		
		
		//Drawing/Clearing 				
		private function drawTile(){
			if(TileEditor.currentLayer == LayerEnum.ARTBACKGROUND){
				if(Layer.currentSelectionBMP != null){
					ID = Layer.currentSelectionID;
					resetTile();
					fillTileWithSelection(tilebmpData); //Clear the current tile and set it to the default tile data
					fillTileWithSelection(Layer.currentSelectionBMP); //Sets the current tile to the users selection on the spritesheet
				}
				else{
					trace("Please Select A Bitmap");
				}
			}
			else if(TileEditor.currentLayer == LayerEnum.COLLISION){
				if(clickable){
					clickable = false;
					fillTileWithSelection(tilebmpData);
					fillTileWithSelection(new BitmapData(32,32,false,0x990000)); //Different color to indicate that it's now collidable
				}
			}
		}
		private function clearTile(){
			if(TileEditor.currentLayer == LayerEnum.ARTBACKGROUND){
				ID = DEFAULT_ID;
				fillTileWithSelection(Layer.layerBitmapData);
				fillTileWithSelection(tilebmpData);
			}
			else if(TileEditor.currentLayer == LayerEnum.COLLISION){
				if(!clickable){
					this.graphics.clear();
					fillTileWithSelection(tilebmpData);
					clickable = true;
				}
			}
			
			
		}
		
		private function fillTileWithSelection(bmpData:BitmapData){
			this.graphics.beginBitmapFill(bmpData);
			this.graphics.drawRect(xPosition,yPosition,32,32);
			this.graphics.endFill();
		}
		
		private function resetTile(){
			this.graphics.clear();
			this.graphics.lineStyle(1, 0x000000,1.0);
			fillTileWithSelection(tilebmpData);
		}
	

	}
	
}
