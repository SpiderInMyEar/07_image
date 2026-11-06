#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

	ofImage imgSource;
		ofImage imgResult;
		ofColor currentColor;
		int effect { 0 };
		int maxEffects { 10 };

		ofColor filter(int effectP, ofColor color, float p = 1.0f);
		void filterImage(int effect, float p);

		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
