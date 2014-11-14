#pragma once
#include "ofMain.h"
#include "resourceManager.h"
class gameTile
{
public:
    ofTexture* texture;
    ofColor cover;
    float x, y;
    void setTexture(resourceManager&, std::string);
    void update();
    void draw();
};
