#include "ofxVicon.h"

void ofxVicon::setup(string ip) {
	vicon = new viconClient(const_cast<char*>(ip.c_str()));
}

int ofxVicon::update() {
	return vicon->readData();
}

int ofxVicon::getBodyCount() const {
	return vicon->getBodyPositions()->size();
}

ofVec3f ofxVicon::getBodyTranslation(int i) const {
	const BodyData& bodyData = vicon->getBodyPositions()->at(i);
	return ofVec3f(bodyData.TX, bodyData.TY, bodyData.TZ);
}

ofQuaternion ofxVicon::getBodyQuaternion(int i) const {
	const BodyData& bodyData = vicon->getBodyPositions()->at(i);
	return ofQuaternion(bodyData.QX, bodyData.QY, bodyData.QZ, bodyData.QW);
}
