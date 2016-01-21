#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    width = 400;
    height = 400;
    
    soundStream.setup(this, 2, 0, 44100, 512, 4);
    pixelBuffer = new unsigned char[ width * height ];

    tex.allocate(width,height, GL_LUMINANCE);
    sampleCount = 0;
    
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    tex.loadData(pixelBuffer, width, height, GL_LUMINANCE);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    tex.draw(0,0);
    
    
    for (int i = 0; i < 512; i++){
        int samples = sampleCount - i;
        if (samples < 0) samples += width*height;
        int x = samples % width;
        int y = samples / width;
        ofSetColor(255,0,0);
        ofRect(x,y, 2,2);
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


    if (key == 'a'){
        float val = ofMap(mouseX, 0, ofGetWidth(), 1, 1000.0, true);
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                int index = i * width + j;
                    pixelBuffer[index] = ofSignedNoise(i/val, j/val, ofGetElapsedTimef()*10.0) * 127 + 127;
            }
        }
    } else if (key == 'b'){
        for (int i = 0; i < width*height; i++){
            if (i % max(mouseX,1) == 0){
                pixelBuffer[i] = 255;
            } else {
                pixelBuffer[i] = 0;
            }
        }
    } else if (key == 'c'){
        float val = ofRandom(0.01, 0.9999);


        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                int index = i * width + j;
                if ( j % (int)(val*100) == 0 || i % (int)(val*100) == 0){
                    pixelBuffer[index] = ofRandom(0,255);
                } else {
                    pixelBuffer[index] = 0;
                }
            }
        }
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

    width = w;
    height = h;
    
    
    delete [] pixelBuffer;
    pixelBuffer = new unsigned char[ width * height ];
    

    
    tex.clear();
    tex.allocate(width,height, GL_LUMINANCE);
    sampleCount = 0;
    
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
        
        float val = ofMap(pixelBuffer[sampleCount],0,255,-1,1);
        output[i*nChannels    ] = val * 0.1;
        output[i*nChannels + 1] = val * 0.1;
        
        
        sampleCount++;
        sampleCount %= width*height;
	}
    
    
}
