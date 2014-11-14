#pragma once
#include "ofMain.h"
#include "tile.h"
#include "resourceManager.h"
class tileEditor
{
public:
    std::vector<std::vector<gameTile> > &tiles;
    std::vector<std::string> textures;
    resourceManager* recMan;
    int currentTextureIndex;
    int over, down;//current selected tile vector
    int tileDimX;

    void setup(std::vector<std::vector<gameTile> >&, resourceManager&, const int&);
    void update(const ofVec2f&, const bool, resourceManager&);
    void draw();
};
