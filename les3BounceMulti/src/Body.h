#pragma once 

#include "ofMain.h"

class Body
{
public: Body();

	void setup(); 
	void bounce();

	float speedX; 
	float speedY; 

	float color1;
	float color2;
	float color3;

	float X;
	float Y;
	int radius; 
};