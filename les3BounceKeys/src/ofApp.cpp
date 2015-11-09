#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	amount = 1;
	addOne = 0;

	for (int i = 0; i < amount; i++)
	{
		Triangle newTriangleA;
		newTriangleA.setup();
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
	if (key == 'c') // create
	{
			addOne += 1;

			for (int i = 0; i < addOne; i++)
			 {
					Triangle newTriangleA;
					newTriangleA.setup();
					TriangleA.push_back(newTriangleA);

					addOne = 0;
			}
	} else if (key == 'd') {  // delete
		
        
    if (TriangleA.size() > 0)
    {
        TriangleA.erase(TriangleA.begin());
			}
	}
}
