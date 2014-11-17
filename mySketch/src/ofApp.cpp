#include "ofApp.h"
#include <iostream>
#include "ofxXMLSettings.h"
#include <math.h>
#include "editorGUI.h"
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
    tileSave.saveFile(currentFileName + ".xml");

}

void ofApp::loadTiles()
{
    ofxXmlSettings tileLoad;
    if(tileLoad.loadFile("tileSave.xml"))
    {
        gameWidth = tileLoad.getValue("boardWidth", 0);
        gameHeight = tileLoad.getValue("boardHeight", 0);
        tileDimX = tileLoad.getValue("tileDimensionsX", 0);
        tileDimY = tileLoad.getValue("tileDimensionsY", 0);
        tileLoad.pushTag("tileArray");
        for(int aa = 0; aa < tiles.size(); aa++)
        {
            tileLoad.pushTag("row", aa);
            for(int bb =0; bb < tiles.size(); bb++)
            {
                tileLoad.pushTag("tile", bb);
                tiles[aa][bb].textureName = tileLoad.getValue("textureName", "");
                tiles[aa][bb].setTexture(recMan, tileLoad.getValue("textureName", ""));
                tileLoad.popTag();
            }
            tileLoad.popTag();
        }
    }
}
//--------------------------------------------------------------
void ofApp::setup(){
editorGUI* gui;
    recMan = new resourceManager;

    recMan->addTexture("water", "basicWater.png");
    recMan->addTexture("stone", "basicStone.png");
    recMan->addTexture("grass", "basicGrass.png");
    recMan->addTexture("lava", "basicLava.png");
    recMan->addTexture("oldgrass", "oldGrass.png");
    recMan->addTexture("stone2", "basicStone2.png");

    currentFileName = "tileSave";

    camPosition.x = 100;
    camPosition.y = 100;
    camPosition.z = 1000;
    camMoveSpeed = 15;
    playerPosition = ofVec2f(50, 50);
    gameHeight = 100;
    gameWidth = 100;
    tileDimX = 50;
    ofVec2f tmpLoc;

    for(int aa = 0; aa < gameHeight; aa++)
    {
        tmpLoc.y = aa*tileDimX;
        std::vector<gameTile> tilesRow;
        for(int bb = 0; bb < gameWidth; bb++)
        {
            tmpLoc.x = bb*tileDimX;
            gameTile tmp;
            tmp.location.x = tmpLoc.x;
            tmp.location.y = tmpLoc.y;
            tmp.passable = true;
            if(bb == 0 && aa == 0)
            {
                tmp.setTexture(recMan, "stone");
            }
            else{tmp.setTexture(recMan, "grass");}

            tilesRow.push_back(tmp);

        }
        tiles.push_back(tilesRow);
    }
    loadTiles();

    //TILE_BUFFER.allocate(gameWidth*tileDimX, gameHeight*tileDimX);

    editor = new tileEditor(recMan, &tiles, tileDimX);

    GUI = new editorGUI(*this);
}

//--------------------------------------------------------------
void ofApp::update(){
    GUI->update(*this);

    ofVec2f arrayPosMax, arrayPosMin;

    arrayPosMax.x = ((abs(playerPosition.x)+ofGetScreenWidth())/tileDimX)+1;
    arrayPosMax.y = ((abs(playerPosition.y)+ofGetScreenHeight())/tileDimX)+1;
    arrayPosMin.x = (abs(playerPosition.x)/tileDimX)-1;
    arrayPosMin.y = (abs(playerPosition.y)/tileDimX)-1;
    std::cout << arrayPosMax << ":::" << arrayPosMin << std::endl;
    toUpdate.clear();
    for(int aa = 0; aa < gameHeight; aa++)
    {
        std::vector<bool> tmp;
        for(int bb = 0; bb < gameWidth; bb++)
        {
            if(aa > arrayPosMax.y ||
               aa < arrayPosMin.y ||
               bb > arrayPosMax.x ||
               bb < arrayPosMin.x)t
            {
                tmp.push_back(false);
            }
            else{tmp.push_back(true);}
        }
        toUpdate.push_back(tmp);
    }
    editor->update(realMousePos, mouseClicked);
    mouseClicked = false;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(playerPosition.x, playerPosition.y);
    for(int aa = 0; aa < gameHeight; aa++)
    {
        for(int bb = 0; bb < gameWidth; bb++)
        {
            if(toUpdate[aa][bb] == true)
            {
                tiles[aa][bb].draw();
            }
        }
    }
    ofSetColor(255, 255,255, 100);
    editor->draw();
    ofSetColor(0, 0, 255, 255);
    ofPopMatrix();
    GUI->draw(GUI_BUFFER);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 97)//a
    {
        playerPosition.x-=camMoveSpeed;
    }
    else if(key == 100)//d
    {
        playerPosition.x+= camMoveSpeed;
    }
    if(key == 119)//w
    {
        playerPosition.y += camMoveSpeed;
    }
    else if(key == 115)//s
    {
        playerPosition.y -= camMoveSpeed;
    }
    if(key == OF_KEY_F1)
    {
        saveTiles();
    }
    if(key == OF_KEY_F2)
    {
        loadTiles();
    }
    if(key == OF_KEY_SHIFT)
    {
        editor->changeCurrentTexture();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos.x = x;
    mousePos.y = y;
    realMousePos.x = mousePos.x - playerPosition.x;
    realMousePos.y = mousePos.y - playerPosition.y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mousePos.x = x;
    mousePos.y = y;
    realMousePos.x = mousePos.x - playerPosition.x;
    realMousePos.y = mousePos.y - playerPosition.y;
    mouseClicked = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseClicked = true;
    mousePos.x = x;
    mousePos.y = y;
    realMousePos.x = mousePos.x - playerPosition.x;
    realMousePos.y = mousePos.y - playerPosition.y;
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
