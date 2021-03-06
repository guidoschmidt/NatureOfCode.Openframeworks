#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  this->_attractor = new Attractor();
  this->_mover = new Mover(ofRandom(20, 30),
                           ofRandom(0, ofGetHeight()),
                           ofRandom(0, ofGetHeight()));
}

//--------------------------------------------------------------
void ofApp::update(){
  this->_attractor->hover(ofGetMouseX(), ofGetMouseY());
  this->_attractor->drag();
  glm::vec2 force = this->_attractor->attract(this->_mover);
  this->_mover->applyForce(force);
  this->_mover->update();
  this->_mover->checkEdges();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(255, 255, 255);
  this->_attractor->display();
  this->_mover->display();
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
  this->_attractor->clicked(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  this->_attractor->stopDragging();
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
