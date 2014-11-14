#pragma once
#include "ofMain.h"
#include "tile.h"
#include "resourceManager.h"
class tileEditor
{
public:
    tileEditor(std::vector<std::vector<gameTile> >& gts, resourceManager& rcM, const int& tdx);
    std::vector<std::vector<gameTile> > &tiles;
    std::vector<std::string> textures;
    resourceManager& recMan;
    int currentTextureIndex;
    int over, down;//current selected tile vector
    int tileDimX;

    void update(const ofVec2f&, const bool, resourceManager&);
    void draw();
};
