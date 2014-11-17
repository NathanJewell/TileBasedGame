#include "ofMain.h"
#include "gameTile.h"
#include "resourceManager.h"
#include <iostream>

void gameTile::setTexture(resourceManager* recMan, std::string texString)
{
    textureName = texString;
    texture = recMan->getTexRef(texString);
}

void gameTile::update()
{

}

void gameTile::draw()
{
    ofSetColor(255, 255,255, 255);
    texture->draw(location.x, location.y);
    //ofRect(x, y, 50, 50);
}
