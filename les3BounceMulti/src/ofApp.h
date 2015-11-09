#pragma once

#include "ofMain.h"
#include "Body.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Eclipse.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector<Triangle> TriangleA;
		vector<Rectangle> RectangleA;
		vector<Eclipse> EclipseA;

		int amount;
};
