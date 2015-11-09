
#pragma once 

#include "ofMain.h"

class Triangle
{
	public: Triangle();

		void setup();
		void bounce(); 
		void display(); 

		float X; 
		float Y; 
		float speedX;
		float speedY; 
		int	radius; 
		ofColor color; 

	private: 
};