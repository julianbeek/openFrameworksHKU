#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofLight light;
    ofEasyCam cam;
    ofImage image;

	ofVideoGrabber grabber;
};
