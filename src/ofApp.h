#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        ofDirectory dir;
        vector<ofVideoPlayer> videos;
    
        int currentVideo;
};
