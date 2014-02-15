package  {
	
	import com.tileEngine.*;
	import flash.display.MovieClip;
	import flash.events.*;
	
	public class main extends MovieClip {
		
		private var tileEditorTest:TileEditor;
		
		public function main() {
			//var fi:FileImporter = new FileImporter();
			tileEditorTest = new TileEditor(20,20,32,32);
			addChild(tileEditorTest);
			//addChild(fi);
		}
	}
	
}
