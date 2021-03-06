#include "Spotlights.h"

//--------------------------------------------------------------
void Spotlights::setup(){

	ofSetFullscreen(true);

	ofSetCircleResolution(64);
	ofEnableSmoothing();
	ofBackground(0);
	// Scene config setup
	// 0 => draw , 1 => do not draw
	drawCircleFlag = 1;
	// Location setup
	x = 0;
	dx = 3.0;
	// Images setup
	hurly_burly[1].loadImage("stripe.jpg");
	hurly_burly[0].loadImage("hurly_burly1.jpg");
	img_num = 0;
	cv_img.setFromPixels(hurly_burly[img_num].getPixels(), hurly_burly[img_num].width, hurly_burly[img_num].height);

}

//--------------------------------------------------------------
void Spotlights::update(){

	x += dx;
	// do not draw
	if (x >= ofGetWidth() / 3 - 80 || x <= -1 * (ofGetWidth() / 3 - 80)) {
		if (img_num == 0) {
				img_num = 1;
				cv_img.setFromPixels(hurly_burly[img_num].getPixels(), hurly_burly[img_num].width, hurly_burly[img_num].height);
				ofSleepMillis(100);
				x *= -1;
				ofSleepMillis(100);
		}
		else if (img_num == 1) {
			img_num = 0;
			cv_img.setFromPixels(hurly_burly[img_num].getPixels(), hurly_burly[img_num].width, hurly_burly[img_num].height);
		}
		if (x >= ofGetWidth() / 2.5 || x <= -1* (ofGetWidth() / 2.5)){
			// dx *= -1;
			// x *= -1;
		}
		else {
			drawCircleFlag = 1;
		}
	}
	// draw
	else {
		if (drawCircleFlag == 1) {
			drawCircleFlag = 0;
		}
	}	

	if (drawCircleFlag == 0){
		y = sqrt((1 - x / (ofGetWidth() / 2.5)) * (1 + x / (ofGetWidth() / 2.5)) * ((ofGetHeight() / 2.5) * (ofGetHeight() / 2.5)));
		y /= dx / 2.5;
		// Image update
		cv_img.setROI((x / hurly_burly[img_num].width) * x + hurly_burly[img_num].width / 2.5, 
			(y / hurly_burly[img_num].height) * y + hurly_burly[img_num].height / 2.5 - 40, 400, 400);
	  	currentImage.setFromPixels(cv_img.getRoiPixelsRef());
	}
}

//--------------------------------------------------------------
void Spotlights::draw(){

	if (drawCircleFlag == 0) {
		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
		for (int i = 0; i < 2; i++) {
			x *= -1;
			y *= -1;
			// Draw image
			ofSetColor(255);
			currentImage.draw(x - 200, y - 200);
			// Draw CIrcles 
			ofSetLineWidth(20);
			ofNoFill();
			ofSetColor(0);
			for (int j = 0; j < 30; j++)
				ofCircle(x , y , 200 + 2.8 * j);
		}
		// ofSetColor(0);
		// ofRect(x, y, 4, 4);
		// ofRect(-1 * x, -1 * y, 4, 4);
		ofPopMatrix();
	}
}
