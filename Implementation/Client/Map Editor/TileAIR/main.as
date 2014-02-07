package  {
	
	import com.tileEngine.*;
	import flash.display.MovieClip;
	
	
	public class main extends MovieClip {
		
		private var layer:Layer;
		private var tileTest:TilePicker;
		public function main() {
			layer = new Layer(20,20);
			tileTest = new TilePicker(32,32,10,10);
			tileTest.x += 32*7*3;
			addChild(layer);
			addChild(tileTest);
		}
	}
	
}
