#pragma once
#include "ofMain.h"

class bounceBall {
    public:bounceBall();
    
    void setup();
    void bounce();
    void display();
    
    float X;
    float Y;
    float speedX;
    float speedY;
    int radius;
    ofColor color;
    
private:
};
