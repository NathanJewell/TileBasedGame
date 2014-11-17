#pragma once
#include "ofMain.h"
#include <vector>
#include <map>
#include <string.h>
class resourceManager
{
public:
    std::map<std::string, int> mappedTextures;
    std::map<int, std::string> RmappedTextures;
    std::vector<ofTexture> textures;
    void addTexture(std::string, std::string);
    ofTexture * getTexRef(std::string);
    ofTexture * getTexRef(int index);

};
