#pragma once
#include "ofMain.h"
#include "resourceManager.h"

class gameTile
{
public:
    ofTexture* texture;
    std::string textureName;
    ofColor cover;
    ofVec2f location;
    bool passable;
    void setTexture(resourceManager*, std::string);
    void update();
    void draw();
};
