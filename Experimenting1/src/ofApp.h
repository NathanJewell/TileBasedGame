#pragma once

#include "ofMain.h"
#include "resourceManager.h"
#include "tile.h"
class ofApp : public ofBaseApp{

	public:
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

		ofCamera cam;
		float cpx, cpy, cpz;//camera position
		float x, y, height, width;//character position
		float moveSpeed;//character move speed pix/frame
		std::vector< std::vector<gameTile> > tiles;
		resourceManager recManager;

		int gameWidth, gameHeight;
		int tileDim;
};
