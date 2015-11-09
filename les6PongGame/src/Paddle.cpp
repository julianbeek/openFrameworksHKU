#include "Paddle.h"

Paddle::Paddle(){
}

void Paddle::setup(){
    
    x = 65;
    y = ofGetHeight() / 2;
    
    speedY = 10;
    
    color.set(0);
    
    width = 20;
    height = 150;
    border = 60;
    
}


void Paddle::update()
{
    
}

void Paddle::draw()
{
    ofDrawRectangle(x, y - (height/2), width, height);
}

void Paddle::up()
{
    if (y - speedY >= height / 2 +border)
    {
        y = y - speedY;
    }
}
    
void Paddle::down(){
    if (y + speedY <= ofGetHeight()-border - (height / 2)) {
        y = y + speedY;
    }
}
