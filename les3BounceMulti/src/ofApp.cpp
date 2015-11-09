#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	 amount = 20;

	  for (int t = 0; t < amount; t++)
	  {
		  Triangle newTriangleA;
		  newTriangleA.setup();
		  TriangleA.push_back(newTriangleA);
	  }

	  for (int t = 0; t < amount; t++)
	  {
		  Rectangle newRectangleA;
		  newRectangleA.setup();
		  RectangleA.push_back(newRectangleA);
	  }


	  for (int t = 0; t < amount; t++)
	  {
		  Eclipse newEclipseA;
		  newEclipseA.setup();
		  EclipseA.push_back(newEclipseA);
	  }
}

//--------------------------------------------------------------
void ofApp::update()
{
	 
	  for (int t = 0; t < EclipseA.size(); t++)
	  {
		  TriangleA[t].bounce();
		  RectangleA[t].bounce();
		  EclipseA[t].bounce();
	  }
	  
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
	  for (int t = 0; t < EclipseA.size(); t++)
	  {
		  TriangleA[t].display();
	  }

	   for (int u = 0; u < EclipseA.size(); u++)
	   {
		   RectangleA[u].display();
	   }


	  for (int t = 0; t < EclipseA.size(); t++)
	  {
		   EclipseA[t].display();
	  }
	 	
}