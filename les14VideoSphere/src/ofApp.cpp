#include "ofApp.h"

void ofApp::setup() {
        // laad video, laat 'm loopen, en zet 'm klaar om af te spelen
    video.load("bendershort.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();

    // definieer de straal van de sphere, en de resolutie van de mesh
    sphere.setRadius(200);
    sphere.setResolution(MESH_SIZE);

    // vouw & schaal de texture zodat 'ie om de sphere heen past
    sphere.mapTexCoordsFromTexture(video.getTexture());

    // bewaar het originele z-coordinaat, zodat we die steeds een beetje aan kunnen passen
    ofMesh& mesh = sphere.getMesh();
    for (int index=0; index<mesh.getNumVertices(); index++) {
        ofPoint vertex = mesh.getVertex( index );
        origZ.push_back(vertex.z);
    }

    // belichting, zodat 't beter te zien is dat de sphere een 3d object is
    light.setPointLight();
    light.setPosition(400,400,400);
    light.enable();
}

void ofApp::update() {
    video.update();

    // als er een nieuw video-frame beschikbaar is, start de berekeningen
    if (video.isFrameNew()) {
        ofMesh& mesh = sphere.getMesh();

        for (int y=0; y<MESH_SIZE*2; y++) { // er zijn 2x zoveel verticale, als horizontale circels in de mesh
            for (int x=0; x<MESH_SIZE; x++) {
                int index = x + MESH_SIZE * y;
                ofPoint vertex = mesh.getVertex(index);
                vertex.z = origZ[index] + ofNoise(x * 0.05, y * 0.05, ofGetElapsedTimef() * 0.5) * 50 - 25;
                mesh.setVertex(index, vertex);
            }
        }
    }
}

void ofApp::draw() {
    ofBackground(0);

    cam.setVFlip(true);
    cam.begin();

    ofEnableDepthTest();

    // gebruik het huidige videobeeld als texture
    video.getTexture().bind();

    sphere.draw();               // teken hele sphere
    //sphere.drawWireframe();    // teken alleen 't mesh

    video.getTexture().unbind();

    ofDisableDepthTest();

    cam.end();
}
