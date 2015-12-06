#pragma once

#include "ofMain.h"

#define VIDEO_WIDTH 480
#define VIDEO_HEIGHT 350

#define MESH_WIDTH 480
#define MESH_HEIGHT 350
#define MESH_SIZE 50

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	ofEasyCam cam;

	ofVideoPlayer video;
	ofSpherePrimitive sphere;

	vector<int> origZ;

	ofLight light;
};
