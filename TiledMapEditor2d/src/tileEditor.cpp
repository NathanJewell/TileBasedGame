#include "tileEditor.h"

tileEditor::tileEditor(std::vector<std::vector<gameTile> >& gts, resourceManager& rcM, const int& tdx)
:tiles(gts), recMan(rcM), tileDimX(rcM)
{
    for(int ii  = 0; ii < recMan.mappedTextures.size(); ii++)
    {
        textures.push_back(recMan.mappedTextures[ii].key_type);
    }
    currentTexture index = 1;
}

void tileEditor::update(const ofVec2f& mousePos, const bool mouseClicked, resourceManager& recMan)
{
    for(int aa = 0; aa < tiles.size(); aa++)
    {
        for(int bb = 0; bb < tiles[aa].size(); bb++)
        {
            if(mousePos.x < tiles[aa][bb].x ||
               mousePos.x > tiles[aa][bb].x + tileDimX ||
               mousePos.y < tiles[aa][bb].y ||
               mousePos.y < tiles[aa][bb].y + tileDimX)
            {
                down = aa;
                over = bb;
                if(mouseClicked == true)
                {
                    tiles[aa][bb].setTexture(recMan, textures[currentTextureIndex]);
                }
                break;
            }
            else{down = -1;}
        }
    }
}

void tileEditor::draw()
{
    ofSetColor(0, 100, 200, 140);
    if(down > 0)
    {
        ofRect(tiles[down][over].x, tiles[down][over].y, tileDimX, tileDimX);
    }
}
