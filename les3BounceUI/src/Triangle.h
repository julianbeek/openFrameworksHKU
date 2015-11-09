#pragma once 

#include "ofMain.h"

class Triangle
{
	public: 
		
		Triangle(float quickY_, float shape_);

		void setup(float Quick_);
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