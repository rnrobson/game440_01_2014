package com.tileEngine  {
	
	import com.tileEngine.*;
	import flash.events.*;
	import flash.display.MovieClip;
	
	public class TileEditor extends MovieClip {
		public static var currentLayer:String = LayerEnum.ARTBACKGROUND; 
		
		private var artBackgroundLayer:Layer;
		private var collisionLayer:Layer;
		private var spriteSheet:TilePicker;
		
		public function TileEditor(layerWidth:uint, layerHeight:uint, tileWidth:uint, tileHeight:uint) {
			artBackgroundLayer = new Layer(layerWidth, layerHeight, LayerEnum.ARTBACKGROUND);
			collisionLayer = new Layer(layerWidth, layerHeight, LayerEnum.COLLISION);
			collisionLayer.alpha = 0.3;
			
			spriteSheet = new TilePicker(tileWidth, tileHeight);
			spriteSheet.x = 32*7*3; //Arbitrary value for the placement of the tilepicker
			
			addChildAt(collisionLayer,0);
			addChildAt(artBackgroundLayer,1);
			addChild(spriteSheet);
			
			this.addEventListener(KeyboardEvent.KEY_DOWN, keyboardDown);
		}
		
		private function keyboardDown(e:KeyboardEvent){
			if(e.keyCode == 69){
				switch(currentLayer){
					case LayerEnum.ARTBACKGROUND:
						currentLayer = LayerEnum.COLLISION;
						setChildIndex(collisionLayer,1);
					break;
					case LayerEnum.COLLISION:
						currentLayer = LayerEnum.ARTBACKGROUND;
						setChildIndex(artBackgroundLayer,1);
					break;
				}
			}
			if(e.keyCode == 70){
				var exporter:XMLExport = new XMLExport(artBackgroundLayer, collisionLayer);
			}
			trace(currentLayer);
		}

	}
	
}
