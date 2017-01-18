#include "ofApp.h"
#define NUMBER_OF_GATES 40

//--------------------------------------------------------------
void ofApp::setup(){
    // Initialize world
    world = World2D::create();
    world->setGravity(ofVec2f(0,0));
    world->setWorldSize(ofVec2f(0,0), ofVec2f(ofGetWidth(),ofGetHeight()));
    world->enableCollision();
    world->setDrag(1);
    
    // Add test user
    //    for(int i = 0; i < 5; i++){
    //        users.push_back(User(&world));
    //    }
    
    // Add gates
    for (int i = 0; i < NUMBER_OF_GATES; i++){
        gates.push_back(Gate(ofVec2f((25*i)+20, ofGetHeight()-100)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // MSA update for physics simulation
    world->update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto& u : users){
        u.draw();
    }
    
    for(auto& g : gates){
        g.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::gateActivated(){
    // Create user at point
    // Check neighbouring gates
    //
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
