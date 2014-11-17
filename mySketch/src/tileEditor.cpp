#include "tileEditor.h"

tileEditor::tileEditor(resourceManager* RM, std::vector< std::vector<gameTile> >* t, int& tdx)
{
    tileDimX = tdx;
    recMan = RM;
    tiles = t;
    selection = ofVec2f(1, 1);
    currentTextureString = "stone";
    currentTexture = 1;
}

void tileEditor::changeCurrentTexture()
{
    currentTexture++;
    if(currentTexture >= recMan->textures.size())
    {
        currentTexture = 0;
    }
    currentTextureString = recMan->RmappedTextures[currentTexture];
}

void tileEditor::update(ofVec2f& mousePos, bool& clicked)
{
    for(int aa = 0; aa < tiles->size(); aa++)
    {
        for(int bb = 0; bb < tiles->at(aa).size(); bb++)
        {
            if((*tiles)[aa][bb].location.x > mousePos.x ||
               (*tiles)[aa][bb].location.x+tileDimX < mousePos.x ||
               (*tiles)[aa][bb].location.y > mousePos.y ||
               (*tiles)[aa][bb].location.y+tileDimX < mousePos.y)
            {

            }
            else
            {
                arrayPos.x = aa;
                arrayPos.y = bb;
                if(clicked == true)
                {
                    (*tiles)[aa][bb].setTexture(recMan, currentTextureString);
                }
            }
        }
    }

}

void tileEditor::draw()
{
    ofColor(0, 100, 200, 130);
    ofRect((*tiles)[arrayPos.x][arrayPos.y].location.x,
           (*tiles)[arrayPos.x][arrayPos.y].location.y,
           selection.x*tileDimX, selection.y*tileDimX);
}
