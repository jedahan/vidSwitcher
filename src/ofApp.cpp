#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
    dir.listDir("videos/");
	dir.sort();

	if( dir.size() ){
		omxPlayers.assign(dir.size(), ofxOmxPlayer());
	}
    
	for(int i = 0; i < (int)dir.size(); i++){
		omxPlayers[i].loadMovie(dir.getPath(i));
	}
	currentPlayer = 0;

	ofBackground(ofColor::white);
}

void ofApp::update(){
}

void ofApp::draw(){
    omxPlayers[currentPlayer].draw(0, 0, ofGetWidth(), ofGetHeight());
    
    ofDrawBitmapStringHighlight(omxPlayers[currentPlayer].getInfo(), 60, 60, ofColor(ofColor::black, 90), ofColor::yellow);
}

void ofApp::keyPressed(int key){
    omxPlayers[currentPlayer].stop();
    switch(key){
        case OF_KEY_LEFT:
            currentPlayer--;
            if(currentPlayer < 0) { currentPlayer = omxPlayers.size()-1; }
            break;
        default:
            currentPlayer++;
            currentPlayer %= omxPlayers.size();
            break;
    }
    omxPlayers[currentPlayer].play();
    ofSetFullscreen(true);
}