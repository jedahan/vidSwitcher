#pragma once

#include "ofMain.h"
#include "ofxOMXPlayer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        ofDirectory dir;
        vector<ofxOMXPlayer> omxPlayers;
    
        int currentPlayer;
};
