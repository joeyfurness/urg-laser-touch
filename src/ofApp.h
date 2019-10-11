#pragma once

#include "ofMain.h"
#include "ofxUrg.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"
#include "ofxUrgTracker.h"
#include "ofxTiming.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

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
    
        void updatedSearchCenterPoint(ofVec2f & center);
        void updatedSearchSize(float & size);
        void updateAutoRegion(bool & input);
        void updateUrgOrientation(bool & input);
    
        ofxUrg::Device urg;
        ofxUrgTracker<ofxUrgFollower> tracker;
        ofRectangle trackingRegion;
        ofEasyCam cam;
        ofxOscSender sender;
        ofxXmlSettings settings;
        ofParameter<string> oscPort;
        ofParameter<string> oscHost;
        ofParameterGroup oscParameters;
    
        ofParameter<string> maxRange;
        ofParameter<string> urgSerialPort;
        ofParameter<string> urgIP;
        ofParameter<string> urgPort;
        ofParameter<bool> urgOrientation;
        ofParameterGroup urgParameters;
    
        ofParameter<float> zoom;
        ofParameter<ofVec2f> searchRegionCenterPt;
        ofParameter<float> searchRegionSize;
        ofRectangle searchRegion;
        ofParameter<bool> useAutoRegion;
        ofParameterGroup viewParameters;
    
        ofxPanel panel;
        vector<long> urgData;
        ofMesh mesh;
        ofImage img;
    
        map<unsigned int, Hysteresis*> timers;
        ofParameter<int> maxStddev;
        ofParameter<int> maxClusterCount;
        int preCount;
        int preSdev;
		
};
