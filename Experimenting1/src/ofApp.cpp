#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    gameHeight = 100;
    gameWidth = 100;
    tileDim = 50;
    std::cout << "here2" << std::endl;
    recManager.addTexture("water", "basicWater.png");
    recManager.addTexture("stone", "basicStone.png");
    recManager.addTexture("grass", "basicGrass.png");
    std::cout << "here3" << std::endl;
    for(int aa = 0; aa < gameHeight; aa++)
    {
        y = aa*tileDim;
        std::vector <gameTile> tilesRow;
        for(int bb = 0; bb < gameWidth; bb++)
        {
            x = bb*tileDim;
            gameTile tmp;
            tmp.x = x;
            tmp.y = y;
            tmp.setTexture(recManager, "stone");
            tilesRow.push_back(tmp);

        }
        tiles.push_back(tilesRow);
    }
    std::cout << "here4" << std::endl;

    cpx = 100;
    cpy = 100;
    cpz = 1000;
    moveSpeed = 1;
    x = 100;
    y =100;
    height = 50;
    width = 50;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.setPosition(x+width/2, y+height/2, cpz);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

    for(int aa = 0; aa < gameHeight; aa++)
    {
        for(int bb = 0; bb < gameWidth; bb++)
        {
            tiles[aa][bb].draw();
        }
    }
    ofSetColor(255, 255,255, 100);
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
