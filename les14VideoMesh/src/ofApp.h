#pragma once

#include "ofMain.h"

#define MESH_WIDTH 480
#define MESH_HEIGHT 350
#define MESH_SIZE_X 50
#define MESH_SIZE_Y 30

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofEasyCam cam;

    ofVideoPlayer video;
    ofPlanePrimitive plane;
};
