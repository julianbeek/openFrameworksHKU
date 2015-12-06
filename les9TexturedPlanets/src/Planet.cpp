#include "Planet.h"

Planet::Planet() {
    //ctor
    rotation = 0.5;
}

Planet::~Planet() {
}

void Planet::setup(string name) {
    planetParamGroup.setName(name);
    planetParamGroup.add(rotateSpeed.set("speed",0,0,9.0));
    planetParamGroup.add(distance.set("distance",0,0,900));
}

void Planet::update() {
    rotation++;
}

void Planet::draw() {
    ofRotate(rotation*rotateSpeed);
    ofDrawSphere(distance,0,0,50);
}

