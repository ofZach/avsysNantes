#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    
    soundBuffer = new float[512];
    
    counter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofFill();
    ofSetColor(255);
    ofRect(200,200,512, 200);
    
    ofNoFill();
    ofSetColor(0);
    ofBeginShape();
    for (int i = 0; i < 512; i++){
        ofVertex(200 + i, 300 + 100 * soundBuffer[i]);
        
    }
    ofEndShape();
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


//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){

	for (int i = 0; i < bufferSize; i++){
        
        
        float sample = sin(counter/10.0); //ofRandom(-1,1);
        
        float volume = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
        
        output[i*nChannels    ] = sample * volume;
        output[i*nChannels + 1] = sample * volume;
        
        soundBuffer[i] = sample * volume;
        
        counter++;
	}
    
    
}
