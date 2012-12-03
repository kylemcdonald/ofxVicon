#pragma once

#include "ofMain.h"
#include "ofxVicon.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofxVicon vicon;
	ofxOscSender osc;
};
