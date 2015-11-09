#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Paddle.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

        bool keyup;
        bool keydown;
        bool gameOn;
    
        float border;
    
        Ball ball;
        Paddle player;
};
