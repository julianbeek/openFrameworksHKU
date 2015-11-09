#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ard.connect("/dev/cu.usbmodem1431", 57600);
    
    // flag so we setup arduino when its ready, you don't need to touch this :)
	bSetupArduino	= false;							
}

//--------------------------------------------------------------
void testApp::update(){
    
    // setupArduino() is called once in the begining, which is aligned setup() in Arduino code in general.
    // updateArduino() is called repeadedly as Arduino code has loop().
    // You don't need to touch this.
	if ( ard.isArduinoReady()){
		// 1st: setup the arduino if haven't already:
		if (bSetupArduino == false){
			setupArduino();
			bSetupArduino = true;	// only do this once
		}
		// 2nd do the update of the arduino
		updateArduino();
	}
}

//--------------------------------------------------------------
void testApp::setupArduino(){
}

//--------------------------------------------------------------
void testApp::updateArduino(){
    //Get the latest condition of Arduino.
    //You don't need to touch this.
	ard.update();
    
    //Write code here.
}


//--------------------------------------------------------------
void testApp::draw(){
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
