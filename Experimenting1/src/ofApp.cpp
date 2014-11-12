#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    cpx = 100;
    cpy = 100;
    cpz = 200;
    moveSpeed = 1;
    x = 100;
    y =100;
    height = 100;
    width = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.setPosition(x+width/2, y+height/2, cpz);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRect(x, y, width, height);
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 97)//a
    {
        x-=moveSpeed;
    }
    else if(key == 100)//d
    {
        x+= moveSpeed;
    }
    if(key == 119)//w
    {
        y += moveSpeed;
    }
    else if(key == 115)//s
    {
        y -= moveSpeed;
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
