#pragma once
#include "ofApp.h"
#include "ofxGui.h"
class ofApp;

class editorGUI
{
public:
    editorGUI(ofApp&);
    void update(ofApp&);
    void draw(ofFbo&);

    ofxPanel GUI;
    ofxToggle collidable;
    ofxIntSlider brushSize;
    ofxIntSlider zoom;

    float &VZoom;
    ofVec2f &VBrushSize;

    void brushSizeChanged(int&);
    void zoomChanged(int&);
};
