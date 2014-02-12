package com.tileEngine {
	import flash.filesystem.*;
	import flash.net.*;
	import flash.events.*;
	import flash.display.Bitmap;
	import flash.display.MovieClip;
	import flash.display.Loader;
	
	public class FileImporter extends MovieClip {
		public static var bitmapArray:Array = new Array();
		private var uploadedFiles:Array = new Array();
		private var f:FileReference;
		private var fileFilter:FileFilter = new FileFilter("*.png","*.gif");
		
		private var tempBMP:Bitmap = new Bitmap();
		public function FileImporter() {
			f = new FileReference();
			f.addEventListener(Event.SELECT, onFileSelected);
			f.browse([fileFilter]);
		}
		
		private function onFileSelected(e:Event){
			f.load();
			f.addEventListener(Event.COMPLETE, onLoaded);
		}
		
		private function onLoaded(e:Event){
			var tempReference:FileReference = FileReference(e.target);
			var loader:Loader = new Loader();
			loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onImageLoad);
			loader.loadBytes(tempReference.data);
		}
		
		private function onImageLoad(e:Event){
			var bitmap:Bitmap = Bitmap(e.target.content);
			bitmap.smoothing = true;
			bitmap.x = 100;
			bitmapArray.push(bitmap);
			addChild(bitmapArray[0]);
		}
		
		public function drawSprites(test:MovieClip){
		}

	}
	
}
