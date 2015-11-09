#include "Ball.h"

Ball::Ball(){
}

void Ball::setup()
{
    x = ofGetWidth();
    y = ofGetHeight() / 2;

    speedX = 5;
    speedY = 5;
    border = 60;

    radius = 15;
    color.set(255);
}

void Ball::update(){
    if(x < border ){
        x = border;
    } else if(x > ofGetWidth()-border){
        x = ofGetWidth()-border;
        speedX *= -1;
    }

    if(y < border ){
        y = border;
        speedY *= -1;
    } else if(y > ofGetHeight()-border){
        y = ofGetHeight()-border;
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}
