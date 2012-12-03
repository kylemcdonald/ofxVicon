#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
	vicon.setup("146.87.67.27");
	osc.setup("localhost", 4096); //"146.87.67.71"
}

void ofApp::update(){
	vicon.update();
	for(int i = 0; i < vicon.getBodyCount(); i++) {
		ofxOscMessage msg;
		msg.setAddress("/vicon/body/" + ofToString(i));
		ofVec3f translation = vicon.getBodyTranslation(i);
		msg.addFloatArg(translation.x);
		msg.addFloatArg(translation.y);
		msg.addFloatArg(translation.z);
		osc.sendMessage(msg);
	}
}

void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofDrawBitmapString(ofToString(vicon.getBodyCount()), 10, 40);
	if(vicon.getBodyCount() > 0) {
		ofDrawBitmapString(ofToString(vicon.getBodyTranslation(0)), 10, 60);
		ofDrawBitmapString(ofToString(vicon.getBodyQuaternion(0)), 10, 80);
	}
}
