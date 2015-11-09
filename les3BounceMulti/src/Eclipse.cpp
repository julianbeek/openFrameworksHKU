#include "ofMain.h"
#include "Eclipse.h"

Eclipse::Eclipse()
{

}

void Eclipse::display()
{
	ofSetColor(color1-50,color2-50,color3-50);
	ofSetCircleResolution(100);
	ofDrawEllipse(X,Y,radius,radius);
}


