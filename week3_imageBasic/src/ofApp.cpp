#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    img.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    unsigned char * pixels = img.getPixels();
    
    float pct = ofMap(mouseX, 0, ofGetWidth(), 0, 1, true);     // get the mouse as a pct across the screen
    
    for (int i = 0; i < 640*480; i++){
        pixels[i] = ofRandom(0, 255 * pct);
    }
    
    img.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    img.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
