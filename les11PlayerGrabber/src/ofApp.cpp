#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetVerticalSync(true);
    frameByframe = false;
    
    grabber.listDevices();
    
    grabber.setDeviceID(0);
    grabber.setDesiredFrameRate(30);
    grabber.initGrabber(1024, 768);
    
    video.load("Ironman.mp4");
    video.play();
    video.setLoopState(OF_LOOP_NORMAL);
    
    rotate = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    video.update();
    rotate++;

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetHexColor(0xFFFFFF);
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,100);
    grabber.draw(0, 0);
    ofDisableAlphaBlending();
    
    ofSetHexColor(0x000000);
    ofPixels & pixels = grabber.getPixels();
    
    int vidWidth = pixels.getWidth();
    int vidHeight = pixels.getHeight();
    int nChannels = pixels.getNumChannels();
    
    // let's move through the "RGB(A)" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < vidWidth; i+=8){
        for (int j = 4; j < vidHeight; j+=8){
            unsigned char r = pixels[(j * 1024 + i)*nChannels];
            float val = 1 - ((float)r / 255.0f);
            ofDrawCircle(0 + i,0+j,8*val);
        }
    }
    
    ofEnableAlphaBlending();
    ofSetColor(255*2,0,255*2,100);
    ofScale(0.9,0.9,0.9);
    ofTranslate(400, 200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
    ofDisableAlphaBlending();

}

