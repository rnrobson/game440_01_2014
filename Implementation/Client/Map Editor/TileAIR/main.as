package  {
	
	import com.tileEngine.*;
	import flash.display.MovieClip;
	import flash.events.*;
	
	public class main extends MovieClip {
		
		private var tileEditorTest:TileEditor;
		
		public function main() {
			tileEditorTest = new TileEditor(20,20,32,32);
			addChild(tileEditorTest);
		}
	}
	
}
