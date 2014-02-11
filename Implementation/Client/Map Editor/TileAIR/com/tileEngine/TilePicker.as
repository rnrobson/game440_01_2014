package com.tileEngine {
	import flash.display.MovieClip;
	import flash.display.Bitmap;
	import flash.display.BitmapData;
	import flash.events.MouseEvent;
	import flash.geom.Rectangle;
	import flash.display.Sprite;
	
	public class TilePicker extends MovieClip {
		
	    public static var spriteSheet:Bitmap = new Bitmap(new forest);
		
		private var spriteSheetSplit:Array = new Array();
		private var tempSprite:TileReference;
		private var xPos:uint;
		private var yPos:uint;
		
		public function TilePicker(tileWidth:uint, tileHeight:uint) {
			this.buttonMode = true;
			addChild(spriteSheet);
			//Get the height and width and divide by the tile size
			var widthInTiles:uint = spriteSheet.width/tileWidth;
			var heightInTiles:uint = spriteSheet.height/tileHeight;
			
			//Create fake tiles on top of the spritesheet to allow us to click and grab the selected position
			for(var i:uint = 0; i < widthInTiles*heightInTiles;i++){
				if(i % widthInTiles == 0 && i > 0){
					yPos++;
					xPos = 0;
				}
				tempSprite = new TileReference(new Rectangle(xPos*32, yPos*32, 32, 32), xPos*32, yPos*32, i);
				spriteSheetSplit[i] = tempSprite;
				addChild(spriteSheetSplit[i]);
				xPos++;				
			}
		
		}
	}
}

