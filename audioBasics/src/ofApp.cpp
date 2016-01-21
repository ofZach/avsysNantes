#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    stream.setup(this, 2, 0, 44100, 512, 4);
    
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::audioOut(float * input, int bufferSize, int nChannels){
    
    
    for (int i = 0; i < bufferSize; i++){
        float sample = sin(counter/20.0) * 0.1;
        input[i*2] = sample;
        input[i*2+1] = sample;
        
        counter++;
    }
    
}


//--------------------------------------------------------------
void ofApp::draw(){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
