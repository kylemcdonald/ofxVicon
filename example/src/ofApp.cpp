#include "ofApp.h"

void ofApp::setup(){
	vicon.setup("146.87.67.27");
}

void ofApp::update(){
}

void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofDrawBitmapString(ofToString(vicon.update()), 10, 20);
	ofDrawBitmapString(ofToString(vicon.getBodyCount()), 10, 40);
	if(vicon.getBodyCount() > 0) {
		ofDrawBitmapString(ofToString(vicon.getBodyTranslation(0)), 10, 60);
		ofDrawBitmapString(ofToString(vicon.getBodyQuaternion(0)), 10, 80);
	}
}
