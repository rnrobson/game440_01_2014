package  {
	
	import com.tileEngine.*;
	import flash.display.MovieClip;
	
	
	public class main extends MovieClip {
		
		private var layer:Layer;
		private var tileTest:TilePicker;
		public function main() {
			layer = new Layer(20,20,"ARTBACKGROUND");
			tileTest = new TilePicker(32,32);
			tileTest.x += 32*7*3;
			addChild(layer);
			addChild(tileTest);
		}
	}
	
}
