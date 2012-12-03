#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main(){
	ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 512, 512, OF_WINDOW);
	ofRunApp(new ofApp()); // start the app
}
