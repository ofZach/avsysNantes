#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    myImage.allocate(500, 500, OF_IMAGE_GRAYSCALE);
    
    // detroit:
    
    unsigned char * pixels = myImage.getPixels().getData();
    
    for (int i = 0; i < 500*500; i++){
        pixels[i] = 0;
    }
    
    myImage.update();
    
    
    
    
    // disneyland...
    //ofPixels myPix = myImage.getPixels();
    //myPix.setColor(....);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
//    unsigned char * pixels = myImage.getPixels().getData();
//    
//    for (int i = 0; i < 500*500; i++){
//        pixels[i] = ofRandom(0,255);
//    }
    
    unsigned char * pixels = myImage.getPixels().getData();

//    for (int i = 0; i < 500; i++){
//        for (int j = 0; j < 500; j++){
//            pixels[j*500 + i] = (i % (j+1)) ;
//        }
//    }
    
    
    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 500; j++){
            float distance = ofDist(i,j, mouseX, mouseY);
            
            if (ofGetMousePressed() && distance < 100){
                pixels[j*500 + i] = 255;
            }
            
            //pixels[j*500 + i] -=1;
        }
    }

    
    myImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    myImage.draw(0,0);
    
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
