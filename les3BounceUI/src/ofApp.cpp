#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    gui.setup("Settings","setting.xml");
    gui.loadFromFile("setting.xml");
    
    gui.add(filled.setup("fill", true));
    gui.add(speedX.setup("speedX",1,0,5));
    gui.add(speedY.setup("speedY",1,0,5));
    gui.add(Shape.setup("Shape",20,0,200));
        
	amount = 1;
	addOne = 0;

	for (int i = 0; i < amount; i++)
	{
		Triangle newTriangleA(speedY, Shape);
		newTriangleA.setup(speedX);
		TriangleA.push_back(newTriangleA);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < TriangleA.size(); i++)
	{
		TriangleA[i].bounce();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if(filled) {
        ofFill();
    } else {
        ofNoFill();
    }
    
    gui.draw();
    
	for (int i = 0; i < TriangleA.size(); i++)
	{
		TriangleA[i].display();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 32) // spacebar
	{
        Triangle newTriangleA(speedY,Shape);
        newTriangleA.setup(speedX);
        TriangleA.push_back(newTriangleA);
        
			}
	 if (key == 100) {  // d
		 
			if (TriangleA.size() > 0)
			{
				 TriangleA.erase(TriangleA.begin());
			}
	} 
}
