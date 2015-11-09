#include "ofApp.h"
#include "Ball.h"

Ball ball;

//--------------------------------------------------------------
void ofApp::setup() {
    
    ball.setup();
    player.setup();
    
    keyup = false;
    keydown = false;
    gameOn = true;
    border = 60;
}

//--------------------------------------------------------------
void ofApp::update() {
    ofBackground(0);
    
    if (gameOn)
    {
        ball.update();
        
        if (keyup){
            player.up();
        }
        else if (keydown){
            player.down();
        }
    }
    
    if(ball.x < border ){
        ball.x = border;
        gameOn = false;
    }
    
    if (ball.x < player.x + (player.width))
    {
        if (ball.y > player.y - (player.height/2) && ball.y < player.y + (player.height /  2))
        {
           ball.speedX = - ball.speedX;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
        ofFill();
        ball.draw();
        player.draw();
        ofDrawBitmapString("Pong", ofGetWidth()/2, 50);
        ofSetColor(255,255,255);
    
    if (gameOn == false) {
        ofDrawBitmapString("Game Over", ofGetWidth()/2-20, ofGetHeight()/2);
    }
    
        ofNoFill();
        ofDrawRectangle(border, border, ofGetWidth()-(border+border), ofGetHeight()-(border+border));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_UP){
        keyup = true;
    }
    
    else if (key == OF_KEY_DOWN){
        keydown = true;
    }
    
    else if (key == 'r' && !gameOn) // reset
    {
        gameOn = true;
        ball.setup();
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == OF_KEY_UP){
        keyup = false;
    }
    
    else if (key == OF_KEY_DOWN){
        keydown = false;
    }
}

