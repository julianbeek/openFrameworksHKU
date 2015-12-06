#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);

    ofBackground(30,30,30);

    drawGrid = false;
    drawLight = false;

    planet01.setup("Sun");
    planetParams.add(planet01.planetParamGroup);

    planet02.setup("Earth");
    planetParams.add(planet02.planetParamGroup);
    
    planet03.setup("Mars");
    planetParams.add(planet03.planetParamGroup);
    
    planet04.setup("Jupiter");
    planetParams.add(planet04.planetParamGroup);

    gui.setup(planetParams);
    image1.load("earth.jpg");
    image2.load("jupiter.jpg");
    image3.load("mars.jpg");
    image4.load("sun.jpg");

    // plaats een light in de 3d ruimte
    light.setPointLight();
    light.setPosition(200,200,200);
    
    ofEnableDepthTest();
}

void ofApp::update(){
    planet01.update();
    planet02.update();
    planet03.update();
    planet04.update();
}

void ofApp::draw(){
    // dit zorgt er voor dat de texture passend gescaled wordt
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    
    ofScale(image1.getWidth(),image1.getHeight());
    ofScale(image2.getWidth(),image2.getHeight());
    ofScale(image3.getWidth(),image3.getHeight());
    ofScale(image4.getWidth(),image4.getHeight());
    glMatrixMode(GL_MODELVIEW);

    light.enable();
    gui.draw();
    light.disable();

    // zorg ervoor dat OF rekening houdt met de 'diepte' (z-coord) van alle objecten

    // start de camera
    cam.begin();
        ofEnableDepthTest();

    // als je een camera gebruikt, hoef je geen translate te doen
    // om het 0-punt naar het midden van 't scherm te verplaatsen

    if (drawGrid) ofDrawGrid(200);
    if (drawLight) light.draw();
    
    light.enable();
    //light.enable();
    // teken eerste planeet
    image4.bind();
    planet01.draw();
    image4.unbind();
    
    // verplaats het 0-punt naar de positie van de 1e planeet...
    ofTranslate(planet01.distance,100);
    image1.bind();
    planet02.draw();
    image1.unbind();
    
    ofTranslate(planet01.distance, 130);
    image3.bind();
    planet03.draw();
    image3.unbind();
    
    ofTranslate(planet01.distance, 150);
    image2.bind();
    planet04.draw();
    image2.unbind();
    light.disable();

    
        ofDisableDepthTest();
    // eindig het camera blok
    cam.end();
    // schakel de diepte-test weer uit
    
    // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    

}

void ofApp::keyPressed(int key) {
    if (key=='g') {
        drawGrid = !drawGrid;
    } else if (key=='l') {
        drawLight = !drawLight;
    }
}
