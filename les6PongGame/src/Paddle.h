#pragma once

#include "ofMain.h"

class Paddle {
    
public:
    
    Paddle();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float x;
    float y;
    float speedY;
    float border;
       
    ofColor color;
    
    int width;
    int height;
    
    void up() ;
    void down (); 
    
    private:
    
};
