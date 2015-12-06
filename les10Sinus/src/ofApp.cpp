#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(34,34,34);
    
    //soundStream.listDevices();
    soundStream.setDeviceID(3);
    soundStream.setup(this, 2, 0, 44100, 512, 4);
    
    phase = 0;

}

void ofApp::audioOut(float* output, int buffersize, int nChannels){
    for (int i = 0; i < buffersize * nChannels; i +=2){
        float sample = sin(phase);
        output[i] = sample;
        output[i+1] = sample;
        phase +=0.05;
    }
}