#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    soundBuffer = new float[512];
    
    
    sinWave.setup(44100);
    sinWave.setFrequency(800);
    sinWave.setVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){
     sinWave.setFrequency( max(1,mouseX) );  // don't want to give a negative frequency...
    
   // sinWave.setVolume( ofMap(mouseY, 0, ofGetHeight(), 0,1, true));
    
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
    
    
    ofDrawBitmapStringHighlight("frequency:  " + ofToString(sinWave.frequency), ofPoint(200,50));
    
    string type;
    if (sinWave.type == 0) type = "sine wave";
    if (sinWave.type == 1) type = "square wave";
    if (sinWave.type == 2) type = "triangle wave";
    if (sinWave.type == 3) type = "saw tooth wave";
    if (sinWave.type == 4) type = "reverse saw tooth wave";
    
    ofDrawBitmapStringHighlight("type:  " + type, ofPoint(200,100));

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    sinWave.type++;
    sinWave.type %= 5;
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
        
        float sample = sinWave.getSample(); //ofRandom(-1,1);
        
        output[i*nChannels    ] = sample;
        output[i*nChannels + 1] = sample;
        
        soundBuffer[i] = sample;
	}
    
    
}
