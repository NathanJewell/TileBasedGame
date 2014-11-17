#pragma once
#include "ofMain.h"
#include "resourceManager.h"
#include "gameTile.h"
#include <string.h>

class tileEditor
{
public:
    tileEditor(resourceManager*, std::vector< std::vector<gameTile> >*, int&);

    std::vector< std::vector<gameTile> >* tiles;
    resourceManager* recMan;
    std::vector<std::string> textureStrings;

    int currentTexture;
    std::string currentTextureString;
    int tileDimX;
    ofVec2f arrayPos;
    ofVec2f selection;

    void changeCurrentTexture();
    void update(ofVec2f&, bool&);
    void draw();
};
