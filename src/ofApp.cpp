#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1600, 900);
	bool loadingOk = imgSource.load("frog_baptism.png");

	if (!loadingOk) {
		ofLogError() << "image non trouvée";
	}
	imgResult.allocate(imgSource.getWidth(), imgSource.getHeight(),
		OF_IMAGE_COLOR);

	// Setup image

}

void ofApp::filterImage(int effect, float p) {
	for (int y = 0; y < imgSource.getHeight(); y++) {
		for (int x = 0; x < imgSource.getWidth(); x++) {
			ofColor tempColor = imgSource.getColor(x, y);

			imgResult.setColor(x, y, filter(effect, tempColor, p));
		}
	}
	imgResult.update();
}

ofColor ofApp::filter(int effectP, ofColor color, float p) {
	float r = color.r;
	float g = color.g;
	float b = color.b;

	ofColor resultColor;
	int grayLevel = (r + g + b) / 3;
	float luminance = 0.299f * r + 0.114f * b + 0.587f * g;
	float k;
	switch (effectP) {
		// EFFECT 1 : INVERSED
	case 1:
		resultColor = { 255 - r, 255 - g, 255 - b };
		return resultColor;

		break;
		// EFFECT 2: GRAYSCALE
	case 2:
		resultColor = { (r + g + b) / 3 };
		return resultColor;
		break;

		// EFFECT 3: Gray luminance
	case 3:
		
		return { luminance };
		break;

		// EFFECT 4: BLACK & WHITE (WIP)
	case 4:
		
		if (luminance > 255 / 3) {
			resultColor = { 255 };
		} else {
			resultColor = { 0 };
		}
		return resultColor;
		break;
		// EFFECT 5: 4 GRAY LEVELS
	case 5:
		
		if (grayLevel < 255 / 4) {
			resultColor = { 0 };
		} else if (grayLevel < 255 / 2) {
			resultColor = { 255 / 3 };
		} else if (grayLevel > (255 * 3) / 4) {
			resultColor = { (255 * 2) / 3 };
		} else {
			resultColor = { 255 };
		}
		return resultColor;
		break;
	case 6:
		// EFFECT 6: changing brightness
		k = (p - 0.5f) * 256;

		r = ofClamp(r + k, 0, 255);
		g = ofClamp(g + k, 0, 255);
		b = ofClamp(b + k, 0, 255);

		resultColor = { r, g, b };
		return resultColor;
	case 7:
		// EFFECT 7: contrast
		k = p * 3;
		r = ofClamp((r -128)*k + 128, 0, 255);
		g = ofClamp((g - 128) * k + 128, 0, 255);
		b = ofClamp((b - 128) * k + 128, 0, 255);
		resultColor = { r, g, b };
		return resultColor;
		break;
	case 8:
		// EFFECT 8: Sepia
		resultColor = {
			ofClamp(0.393f * r + 0.769f * g + 0.189f * b, 0, 255),
			ofClamp(0.349f * r + 0.686f * g + 0.168f * b, 0, 255),
			ofClamp(0.272f * r + 0.534f * g + 0.131f * b, 0, 255)
		};
		return resultColor;
	case 9:
		// EFFECT 9: Green Screen WIP
		if (g > 60 && b < 50 && r < 30) {
			return { 0, 0, 0, 0 };
		} else
			return color;
	}
	
	return color;
}


//--------------------------------------------------------------
void ofApp::update(){
	/*
	int px = ofClamp(mouseX, 0, imgSource.getWidth()-1);
	int py = ofClamp(mouseY, 0, imgSource.getHeight()-1);
	currentColor = imgSource.getColor(px, py);
	*/
	float power = mouseX / (float)ofGetWindowWidth();
	filterImage(effect, power);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	imgResult.draw(0, 0);


	/*
	ofSetColor(currentColor);
	ofDrawRectangle(mouseX + 10, mouseY - 20, 60, 60);
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		effect--;
	}
	if (key == OF_KEY_RIGHT) {
		effect++;
	}
	effect = (effect + maxEffects) % maxEffects;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
