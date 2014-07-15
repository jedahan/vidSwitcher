#include "ofApp.h"

void ofApp::setup(){
	ofSetVerticalSync(true);
    dir.listDir("videos/");
	dir.sort();

	if( dir.size() ){
		videos.assign(dir.size(), ofVideoPlayer());
	}
    
	for(int i = 0; i < (int)dir.size(); i++){
		videos[i].loadMovie(dir.getPath(i));
	}
	currentVideo = 0;

	ofBackground(ofColor::white);
}

void ofApp::update(){
    videos[currentVideo].update();c
}

void ofApp::draw(){
    videos[currentVideo].draw(0, 0);
}

void ofApp::keyPressed(int key){
    videos[currentVideo].stop();
    switch(key){
        case OF_KEY_LEFT:
            currentVideo--;
            if(currentVideo < 0) { currentVideo = videos.size()-1; }
            break;
        default:
            currentVideo++;
            currentVideo %= videos.size();
            break;
    }
    videos[currentVideo].play();
    ofSetFullscreen(true);
}