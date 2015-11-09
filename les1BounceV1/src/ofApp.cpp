#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    amount = 20;
    
    for (int t=0; t < amount; t++)
    {
        bounceBall newBall;
        newBall.setup();
        Ball.push_back(newBall);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int t=0; t < Ball.size(); t++)
    {
        Ball[t].bounce();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int t=0; t < Ball.size(); t++)
    {
        Ball[t].display();
    }
}
