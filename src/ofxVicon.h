#pragma once

#include "ofMain.h"
#include <viconClient.h>

class ofxVicon {
protected:
	viconClient* vicon;
public:
	void setup(string ip);
	int update();
	int getBodyCount() const;
	ofVec3f getBodyTranslation(int i) const;
	ofQuaternion getBodyQuaternion(int i) const;
};