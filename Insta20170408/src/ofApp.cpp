#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Many Particle");
	ofEnableDepthTest();
	ofEnableSmoothing();
	ofBackground(0);
	ofSetFrameRate(60);
	//ofBlendMode(OF_BLENDMODE_ADD);

	this->flg = true;

	for (int i = 0; i < 512; i++) {
		Particle particle = Particle(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-512, 512));
		this->particles.push_back(particle);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (this->flg) {
		if (ofGetMousePressed()) {
			for (auto& p : this->particles) {
				p.applyForce(p.seek(ofVec3f(ofGetMouseX() - ofGetWidth() / 2, ofGetMouseY() - ofGetHeight() / 2, 0)));
			}
		}

		for (auto& p : this->particles) {
			p.update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	for (auto& p : this->particles) {
		p.draw(this->particles);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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
	this->flg = true;
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
