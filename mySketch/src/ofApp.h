#pragma once

#include "editorGUI.h"
#include "ofMain.h"
#include "resourceManager.h"
#include "gameTile.h"
#include "tileEditor.h"

class editorGUI;

class ofApp : public ofBaseApp{

	public:
	    void saveTiles();
	    void loadTiles();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        std::vector< std::vector<gameTile> > tiles;
        std::vector<std::vector<bool> > toUpdate;
		resourceManager* recMan;
		tileEditor* editor;


		ofVec3f camPosition;
		float camMoveSpeed;
		ofVec2f playerPosition;

		int tileDimX, tileDimY;
		int gameHeight, gameWidth;

		bool mouseClicked;
		ofVec2f mousePos;
		ofVec2f realMousePos;

		ofFbo GUI_BUFFER;
		ofFbo TILE_BUFFER;

		std::string currentFileName;

		editorGUI* GUI;


};
