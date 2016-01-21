#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    
    totalSoundBuffer = new float[512];
    
    for (int i = 0; i < 3; i++){
        sinWaves[i].setup(44100);
        sinWaves[i].setFrequency( ofRandom(400,1000));
        sinWaves[i].setVolume(0.1);
        
        soundBuffers[i] = new float[512];
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    // sinWave.setFrequency( max(1,mouseX) );  // don't want to give a negative frequency...

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    for (int i = 0; i < 3; i++){
    
        ofFill();
        ofSetColor(255);
        ofRect(0,0 + i * 300,512, 200);
        
        ofNoFill();
        ofSetColor(0);
        ofBeginShape();
        for (int j = 0; j < 512; j++){
            ofVertex(j, i * 300 + 100 + 100 * soundBuffers[i][j]);
        }
        ofEndShape();

    }
    

    
    ofFill();
    ofSetColor(255);
    ofRect(520,200,512, 200);
    
    ofNoFill();
    ofSetColor(0);
    ofBeginShape();
    for (int i = 0; i < 512; i++){
        ofVertex(520 + i, 300 + 100 * totalSoundBuffer[i]);
    }
    ofEndShape();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
    for (int i = 0; i < 3; i++){
        sinWaves[i].setFrequency( ofRandom(20,1000));
    }
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
        
        
        float sample = 0;
        
        for (int j = 0; j < 3; j++){
            float val = sinWaves[j].getSample();
            soundBuffers[j][i] = val;
            sample += val;
        }
        
        output[i*nChannels    ] = sample;
        output[i*nChannels + 1] = sample;
        
        totalSoundBuffer[i] = sample;
	}
    
    
}
