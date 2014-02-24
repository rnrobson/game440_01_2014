package  {

	import flash.display.MovieClip;
	import flash.events.Event;
	import flash.events.MouseEvent;

	public class Main extends MovieClip {
		public function Main():void {
			MapOuterContainer.gotoAndStop(1);

			TabsOuterContainer.Tab1.addEventListener(MouseEvent.CLICK, tabClicked);
			TabsOuterContainer.Tab2.addEventListener(MouseEvent.CLICK, tabClicked);
			TabsOuterContainer.Tab3.addEventListener(MouseEvent.CLICK, tabClicked);
		}

		public function tabClicked(e:MouseEvent):void {
			switch (e.target.name) {
				case "Tab1":
					MapOuterContainer.gotoAndStop(1);
				break;
				case "Tab2":
					MapOuterContainer.gotoAndStop(2);
				break;
				case "Tab3":
					MapOuterContainer.gotoAndStop(3);
				break;
			}
		}
	}
}
 
