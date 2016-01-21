#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    img.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    unsigned char * pixels = img.getPixels();
    
    
    // (note: the order of these for loops doesn't matter)
    
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){
            
            // the formula for adressing the 1d pixel via 2d is:
            // pos = y * w + x
            // so for us that's
            // pos = j * 640 + i
            
            float dist = ofDist(mouseX, mouseY, i, j);      // calculate the distance between two 2d points (pythogrean)
            
            if (dist < 100){
                pixels[ j * 640 + i ] = 255;
                //pixels[ j * 640 + i ] = ofMap(dist, 0, 100, 255, 0);      // alternatively let's draw a gradient!
            } else {
                pixels[ j * 640 + i ] = 0;
            }
        }
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
