#include "ofApp.h"

void ofApp::setup() {
    // laad video, laat 'm loopen, en zet 'm klaar om af te spelen
    video.load("bendershort.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();

    // stel de afmetingen van 't plane in
    plane.set(MESH_WIDTH, MESH_HEIGHT);
    // mesh wordt MESH_SIZE_X bij MESH_SIZE_Y vertices groot
    plane.setResolution(MESH_SIZE_X, MESH_SIZE_Y);

    // bereken de texture-coordinaten op basis van de afmetingen van de video
    plane.mapTexCoordsFromTexture(video.getTexture());
}

void ofApp::update() {
    video.update();

    // is de video geupdate?
    if (video.isFrameNew()) {

        // haal de mesh uit 't ofPrimitivePlane op
        ofMesh& mesh = plane.getMesh();

        // loop door alle vertices heen
        for (int y=0; y<MESH_SIZE_Y; y++) {
            for (int x=0; x<MESH_SIZE_X; x++) {
                // bereken de vertex-index op basis van de x & y positie in de mesh
                int index = x + MESH_SIZE_X * y;
                ofPoint vertex = mesh.getVertex(index);

                // verstoor de z coordinaat
                vertex.z = ofNoise(x * 0.08, y* 0.08, ofGetElapsedTimef() * 0.8) * 200;
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

    // plane.draw();              // teken het hele videobeeld
    plane.drawWireframe();   // of teken alleen de mesh

    // reset de huidige texture
    video.getTexture().unbind();

    ofDisableDepthTest();

    cam.end();
}
