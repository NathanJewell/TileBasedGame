#include "editorGUI.h"
#include "ofApp.h"
#include "editorGUI.h"
editorGUI::editorGUI(ofApp& app) :
VZoom(app.camPosition.z), VBrushSize(app.editor->selection)
{
    brushSize.addListener(this, &editorGUI::brushSizeChanged);
    zoom.addListener(this, &editorGUI::zoomChanged);
    GUI.setup();
    GUI.add(collidable.setup("Passable", false));
    GUI.add(brushSize.setup("Brush Size:", 1, 1, 10));
    GUI.add(zoom.setup("Zoom:", 500, 300, -2000));


}

void editorGUI::update(ofApp& app)
{

}

void editorGUI::draw(ofFbo& fbo)
{
    fbo.begin();
    GUI.draw();
    fbo.end();
}

void editorGUI::brushSizeChanged(int& bSize)
{
    VBrushSize.x = bSize;
    VBrushSize.y = bSize;
}

void editorGUI::zoomChanged(int& newZoom)
{
    VZoom = newZoom;
}
