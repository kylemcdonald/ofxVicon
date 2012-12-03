#pragma once

#include "ofMain.h"
#include "ofxVicon.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofxVicon vicon;
};
