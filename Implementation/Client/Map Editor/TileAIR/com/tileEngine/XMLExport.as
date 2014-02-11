package com.tileEngine  {
	
	import com.tileEngine.Layer;
	import flash.net.FileReference;
	
	public class XMLExport {
		
		private var Map:XML = new XML(<Map tileSize="" layerWidth="" layerHeight="" levelName="" />);
		private var ArtBackground:XML = new XML(<ArtBackground spriteSheet="" rows="" columns="" />);
		private var ArtForeground:XML = new XML(<ArtForeground />);
		
		private var backgroundTileArray:Array = new Array();
		private var collisionTileArray:Array = new Array();
		private var foregroundTileArray:Array = new Array();
		
		private var layerReference:Layer;
		
		private var temporaryNode:XML;
		public function XMLExport(artBackground:Layer, collisionLayer:Layer) {
			//Get a reference of one of the layers. Since they're both of the same dimensions, it doesn't matter which is used.
			layerReference = artBackground;
			backgroundTileArray = artBackground.tileArray;
			collisionTileArray = collisionLayer.tileArray;
			generateXML();
			trace("Export");
		}
		
		
		private function generateXML(){
			//Map Attributes
			Map.@tileSize=32; //Fix this to be dynamic later
			Map.@layerWidth=layerReference.layerWidth;
			Map.@layerHeight=layerReference.layerHeight;
			Map.@levelName="Test";
			
			//ArtBackground Attributes
			ArtBackground.@spriteSheet="ExampleSpriteSheet.jpeg";
			ArtBackground.@rows=layerReference.layerHeight;
			ArtBackground.@columns=layerReference.layerWidth;
			
			
			for(var i:uint = 0; i < backgroundTileArray.length; i++){
				temporaryNode = new XML(<Tile spriteID="" row="" column="" />);
				temporaryNode.@spriteID = backgroundTileArray[i].ID;
				temporaryNode.@row = backgroundTileArray[i].yPosition/32;
				temporaryNode.@column = backgroundTileArray[i].xPosition/32;				
				temporaryNode.appendChild(<xPos> {backgroundTileArray[i].xPosition} </xPos>);
				temporaryNode.appendChild(<yPos> {backgroundTileArray[i].yPosition} </yPos>);
				temporaryNode.appendChild(<clickable> {collisionTileArray[i].clickable} </clickable>);
				ArtBackground.appendChild(temporaryNode);
			}
			Map.appendChild(ArtBackground);
			export();
		}
		
		private function export(){
			var f:FileReference = new FileReference;
			f.save(Map,"TestXML.xml");
		}

	}
	
}
