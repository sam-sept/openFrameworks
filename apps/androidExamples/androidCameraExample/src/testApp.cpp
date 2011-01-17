#include "testApp.h"
#include "ofxAndroidVideoGrabber.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetLogLevel(OF_LOG_NOTICE);
	grabber.setGrabber(new ofxAndroidVideoGrabber);
	grabber.initGrabber(640,480);
	one_second_time = ofGetSystemTime();
	camera_fps = 0;
	frames_one_sec = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
	if(grabber.isFrameNew()){
		frames_one_sec++;
		if( ofGetSystemTime() - one_second_time >= 1000){
			camera_fps = frames_one_sec;
			frames_one_sec = 0;
			one_second_time = ofGetSystemTime();
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xFFFFFF);
	grabber.draw(5,5);
	ofSetHexColor(0x000000);
	ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()),330,10);
	ofDrawBitmapString("camera fps: " + ofToString(camera_fps),330,30);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

