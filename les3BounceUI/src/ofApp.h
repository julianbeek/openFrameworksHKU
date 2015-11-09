#pragma once

#include "ofMain.h"
#include "Triangle.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
		
    vector<Triangle>TriangleA;
    int amount;
    int addOne;
    
    ofxPanel gui;
    ofxFloatSlider speedX;
    ofxFloatSlider speedY;
    ofxFloatSlider Shape;
    ofxToggle filled;
};
