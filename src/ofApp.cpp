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
    
    // Setup gui
    setupGUI();
        
    // Add gates
    for (int i = 0; i < NUMBER_OF_GATES; i++){
        gates.push_back(Gate(ofVec2f((20.0*i)+20, ofGetHeight()-100),&users,&world, &timingThreshold));
    }
        
    // Add pointers to neighbours
    for(int i = 0; i < gates.size(); i++){
        std::vector<Gate*> neighbours;        
        // special cases for outer gates:
        if(i == 0){
            neighbours.push_back(&gates.at(1));
        }else if(i == gates.size()-1){
            neighbours.push_back(&gates.at(gates.size()-2));
        }else{
            // TWO NEIGHBOURS
            neighbours.push_back(&gates.at(i-1));
            neighbours.push_back(&gates.at(i+1));
        }
        
        gates.at(i).addNeighbours(neighbours);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // MSA update for physics simulation
    world->update();
    
    // Delete dead users
    vector<User>::iterator it = users.begin();
    while(it != users.end()) {
        if((*it).hasTravelledForTooLongNow()) {
            it = users.erase(it);
        }
        else ++it;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(gui.getWidth(), 0);
    for(auto& u : users){
        u.draw();
    }
    
    for(auto& g : gates){
        g.draw();
    }
    
    ofPopMatrix();
    
    std::string info;
    info+="no. of users:\n";
    info+=ofToString(users.size());
    ofSetColor(ofColor::darkRed);
    ofDrawBitmapString(info, 10, 25+gui.getHeight());
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::setupGUI(){
    gui.setup();
    gui.add(timingThreshold.set("timing threshold", 2.5,0.5,5.0));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key-48 > 0 && key-48 < gates.size()){
        gates.at(key-48).activate();
    }
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
