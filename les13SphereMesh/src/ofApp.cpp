#include "ofApp.h"

void ofApp::setup() {
    image.load("lighthouse.jpg");

    // definieer grootte en resolutie van sphere
    sphere.setRadius(200);
    sphere.setResolution(MESH_SIZE);

    // maak image passend als texture over de sphere
    sphere.mapTexCoordsFromTexture(image.getTextureReference());

    // bewaar de originele z-coordinaten
    ofMesh& mesh = sphere.getMesh();
    for (int index=0; index<mesh.getNumVertices(); index++) {
        ofPoint vertex = mesh.getVertex(index);
        origZ.push_back(vertex.z);
    }

    // lichtbron, zodat 3d van sphere beter te zien is
    light.setPointLight();
    light.setPosition(400,400,400);
    light.enable();
}

void ofApp::update() {
    ofMesh& mesh = sphere.getMesh();

    // loop door alle vertices heen...
    for (int y=0; y<MESH_SIZE*2; y++) {
        for (int x=0; x<MESH_SIZE; x++) {

	    // bereken de vertex index voor coordinaat (x,y)
            int index = x + MESH_SIZE*y;
            ofPoint vertex = mesh.getVertex(index);

            // varieer de z-coordinaat een beetje
            vertex.z = origZ[index] +
                       ofNoise( x*0.05, y*0.05, ofGetElapsedTimef() * 0.5) * 50 - 25;

            mesh.setVertex(index, vertex);
        }
    }

}

void ofApp::draw() {
    ofBackground(0);

    cam.setVFlip(true);
    cam.begin();
    ofEnableDepthTest();

    // gebruik het image als texture
    image.bind();

    sphere.draw();              // teken hele sphere
    //sphere.drawWireframe();   // teken alleen 't wireframe
    
    image.unbind();

    ofDisableDepthTest();

    cam.end();
}
