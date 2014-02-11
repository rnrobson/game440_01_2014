package com.tileEngine {

	import flash.display.Sprite;
	import flash.geom.Rectangle;
	import flash.display.BitmapData;
	import flash.events.*;
	import flash.geom.Point;
	
	public class TileReference extends Sprite{
		private var myRect:Rectangle;
		private var xPosition:uint;
		private var yPosition:uint;
		private var ID:uint;
		public function TileReference(rect:Rectangle, xPos:uint, yPos:uint, _ID:uint){
			ID = _ID;
			myRect = rect;
			xPosition = xPos;
			yPosition = yPos;
			addEventListener(Event.ADDED, initialize);
		}
		
		private function initialize(e:Event){
			graphics.lineStyle(1.0,0xFFFFFF);
			graphics.beginFill(0x000000, 0.0);
			graphics.drawRect(xPosition, yPosition, 32, 32);
			graphics.endFill();
			addEventListener(MouseEvent.CLICK, tileSelect);
		}
		
		private function tileSelect(e:MouseEvent){	
			Layer.currentSelectionBMP = new BitmapData(32,32);
			Layer.currentSelectionBMP.copyPixels(TilePicker.spriteSheet.bitmapData, myRect, new Point(e.target.x, e.target.y), null, null, false);
			Layer.currentSelectionID = ID;
			e.target.graphics.lineStyle(1.0, 0x000000,1.0);
			trace(ID);
		}

	}
}
