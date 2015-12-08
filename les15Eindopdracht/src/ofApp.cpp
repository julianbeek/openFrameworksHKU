#include "ofApp.h"
//int for storing the byte data from Arduino.
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
    //General setup of look of window.
    ofBackground(255);
    font.load("franklinGothic.otf", 24);
    ofSetColor(255);
    //serial port setup. using COM3 for Windows port.
    //Also using baud rate 9600, same in Arduino sketch.
    serial.setup("/dev/tty.usbmodem1431", 9600);
}
//--------------------------------------------------------------
void ofApp::update(){
    //Simple if statement to inform user if Arduino is sending serial messages.
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            //byte data is being writen into byteData as int.
            byteData = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "CM: " + ofToString(byteData);
        }
    }
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    //drawing the string version pf byteData on oF window.
        ofBackground(30);// draw grey background
    
    font.drawString(msg, 50, 50);
    
    //printing byteData into console.
    cout << byteData << endl;
    
    
    ofSetColor(255);// set color drawing color to white
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2); // move initital drawing postion to the center of the screen
    int circle_resolution=1600; // amount of points circle is made of, more points - better quality, but could decrease perfomance
    int radius=150+byteData;
    int smoothing_amount=10;

    int wave_height=30;
    int anim_shape=byteData/21;
    float sine_pct=0.5; // setting in percantage how big is the part
    float speed_increment=ofGetElapsedTimef();
    
    int line_w=7;
    int radius_cos=radius+line_w-1; // let's make it little less then line width, so circles will overlap each other
    int radius_un_cos=radius+(line_w-1)*2;
    
    ofPolyline circle_sin;
    ofPolyline circle_cos;
    ofPolyline circle_un_cos;
    
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle+speed_increment)*radius;
        float y=sin(angle+speed_increment)*radius;
        
        // drawing sine wave only on a part of the circle
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin.addVertex(ofPoint(x,y));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
        circle_cos.addVertex(ofPoint(x,y));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3-speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_un_cos);
        y=sin(angle+speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_un_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_un_cos+raidus_addon);
        }
        
        circle_un_cos.addVertex(ofPoint(x,y));
        
        
    }
    
    ofSetLineWidth(line_w);
    
    ofColor clr=ofColor::fromHex(0x379392);
    ofSetColor(clr);
    circle_sin.close(); // to connect first and last point of our shape we need to use ÔcloseÕ function
    circle_sin= circle_sin.getSmoothed(smoothing_amount);
    circle_sin.draw();
    
    clr=ofColor::fromHex(0x2E4952);
    ofSetColor(clr);
    circle_cos.close();
    circle_cos= circle_cos.getSmoothed(smoothing_amount);
    circle_cos.draw();
    
    
    clr=ofColor::fromHex(0x0BC9C7);
    ofSetColor(clr);
    circle_un_cos.close();
    circle_un_cos= circle_un_cos.getSmoothed(smoothing_amount);
    circle_un_cos.draw();
}