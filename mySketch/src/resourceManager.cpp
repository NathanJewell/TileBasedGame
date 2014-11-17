#include "ofMain.h"
#include "resourceManager.h"

void resourceManager::addTexture(std::string mapName, std::string imagePath)
{
    ofTexture tmp;
    ofLoadImage(tmp, imagePath);
    textures.push_back(tmp);
    mappedTextures[mapName] = (textures.size()-1);
    RmappedTextures[textures.size()-1] = mapName;
}

ofTexture * resourceManager::getTexRef(std::string mapName)
{
    ofTexture *tmp = &textures[mappedTextures[mapName]];
    return tmp;
}

ofTexture * resourceManager::getTexRef(int index)
{
    ofTexture *tmp = &textures[index];

    return tmp;
}
