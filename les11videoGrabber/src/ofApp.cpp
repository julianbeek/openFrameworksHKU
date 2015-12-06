#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.listDevices();
    
    grabber.setDeviceID(0);
    grabber.setDesiredFrameRate(30);
    grabber.initGrabber(320, 240);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::red);
    grabber.draw(0, 0);
    
    ofSetColor(ofColor::blue);
    grabber.draw(320, 0);
    
    ofSetColor(ofColor::green);
    grabber.draw(0, 240);
    
    ofSetColor(ofColor::yellow);
    grabber.draw(320, 240);
    
}

