#include "Triangle.h"

Triangle :: Triangle(float quickY_, float shape_)
{
    speedY = quickY_;
    radius = shape_;

}

void Triangle::setup(float Quick_)
{
    speedX = Quick_;

	X = ofRandom(0,ofGetWidth());
	Y = ofRandom(0,ofGetHeight()); 
	color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));

}


void Triangle::bounce()
{

	if (X < 0 || X > ofGetWidth())
	{
		color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		
		speedX *= -1;
	}

	if (Y < 0 || Y > ofGetHeight())
	{
		color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));   
		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 
}


void Triangle::display()
{
	ofSetColor(color);
	ofSetCircleResolution(3);
	ofEllipse(X,Y,radius,radius);
}