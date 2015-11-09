#include "Body.h"

Body::Body()
{
}



void Body::setup()
{
	    speedX = ofRandom(-1,1); 
		speedY = ofRandom(-1,1);

		X = ofRandom(0,ofGetWidth());
		Y = ofRandom(0,ofGetHeight()); 
		radius = ofRandom(40,60); 
		
		color1 = ofRandom(0,255);
		color2 = ofRandom(0,255);
		color3 = ofRandom(0,255);

}



void Body::bounce()
{
	if (X < 0 || X > ofGetWidth())
	{
		//color = (ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
		color1 = ofRandom(0,255);
		color2 = ofRandom(0,255);
		color3 = ofRandom(0,255);

		speedX *= -1;
	}

	if ( Y < 0 || Y > ofGetHeight())
	{
		color1 = ofRandom(0,255);
		color2 = ofRandom(0,255);
		color3 = ofRandom(0,255);

		speedY *= -1;
	}

	X += speedX; 
	Y += speedY; 
}