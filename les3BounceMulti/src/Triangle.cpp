#include "ofMain.h"
#include "Triangle.h"

Triangle::Triangle()
{

}

void Triangle::display()
{
	ofSetColor(color1-200,color2-200,color3-200);
	ofSetCircleResolution(3);
	ofDrawEllipse(X,Y,radius,radius);
}