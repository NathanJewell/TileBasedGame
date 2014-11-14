#include "ofApp.h"
#include <iostream>
#include "ofxXMLSettings.h"
void ofApp::saveTiles()
{
    ofxXmlSettings tileSave;
    tileSave.addValue("boardWidth", gameWidth);
    tileSave.addValue("boardHeight", gameHeight);
    tileSave.addValue("tileDimensionsX", tileDimX);
    tileSave.addValue("tileDimensionsY", tileDimY);
    tileSave.addTag("tileArray");
    tileSave.pushTag("tileArray");
    for(int aa = 0; aa < tiles.size(); aa++)
    {
        tileSave.addTag("row");
        tileSave.pushTag("row", aa);
        for(int bb = 0; bb < tiles[aa].size(); bb++)
        {
            tileSave.addTag("tile");
            tileSave.pushTag("tile", bb);
            tileSave.addValue("textureName", tiles[aa][bb].textureName);
            tileSave.popTag();
        }
        tileSave.popTag();
    }
    tileSave.popTag();
    tileSave.saveFile("tileSave.xml");

}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    gameHeight = 10;
    gameWidth = 10;
    tileDimX = 50;

    recManager.addTexture("water", "basicWater.png");
    recManager.addTexture("stone", "basicStone.png");
    recManager.addTexture("grass", "basicGrass.png");

    editor.setup(tiles, recManager, tileDimX);

    for(int aa = 0; aa < gameHeight; aa++)
    {
        y = aa*tileDimX;
        std::vector <gameTile> tilesRow;
        for(int bb = 0; bb < gameWidth; bb++)
        {
            x = bb*tileDimX;
            gameTile tmp;
            tmp.x = x;
            tmp.y = y;
            std::cout << x << ", " << y << std::endl;
            tmp.setTexture(recManager, "water");
            tilesRow.push_back(tmp);

        }
        tiles.push_back(tilesRow);
    }

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
    editor.update(mousePos, mouseClicked, recManager);
    cam.setPosition(x+width/2, y+height/2, cpz);
    mouseClicked = false;
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
    if(key == OF_KEY_F1)
    {
        saveTiles();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos.x = x;
    mousePos.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseClicked = true
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
