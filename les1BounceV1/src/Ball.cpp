#include <stdio.h>
#include "Ball.h"


bounceBall::bounceBall()
{
    
}

void bounceBall::setup()
{
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);
    
    X = ofRandom(0,ofGetWidth());
    Y = ofRandom(0,ofGetHeight());
    radius = ofRandom(40,60);
    color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
}


void bounceBall::bounce()
{    
    
    if (X < 0 || X > ofGetWidth() || Y < 0 || Y > ofGetHeight())
    {
        color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

        
        speedX *= -1;
        speedY *= -1;
    }
    
    X += speedX;
    Y += speedY;
}


void bounceBall::display()
{
    ofSetColor(color);
    ofEllipse(X,Y,radius,radius);
}
