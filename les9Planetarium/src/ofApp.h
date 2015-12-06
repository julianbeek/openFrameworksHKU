#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

    ofxPanel gui;

    ofParameterGroup planetParams;

    Planet planet01;
    Planet planet02;
    Planet planet03;
    Planet planet04;
    ofLight light;

    bool drawGrid;
    bool drawLight;

    ofEasyCam cam;

};
