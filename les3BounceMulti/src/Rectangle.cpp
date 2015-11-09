#include "ofMain.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::display()
{
	ofSetColor(color1-100,color2-100,color3-100);
	ofDrawRectangle(X,Y,radius,radius);
}


