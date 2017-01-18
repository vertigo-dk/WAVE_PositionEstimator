#pragma once

#include "ofMain.h"
#include "MsaPhysics2D.h"

using namespace msa::physics;

class User{
public:
    User(World2D_ptr* world){
        this->particle = (*world)->makeParticle();
        this->particle->moveTo(ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()-100,ofGetHeight())));
        this->particle->addVelocity(ofVec2f(ofRandom(-8,8),0));
        this->particle->setRadius(3);
        this->particle->disableCollision();
    }
    
    void draw(){
        ofSetColor(ofColor::darkRed);
        ofDrawCircle(particle->getPosition(), particle->getRadius());
        std::string info;;
        info+=ofToString(particle->getPosition());
        ofDrawBitmapString(info, particle->getPosition());
    }
    
    Particle2D_ptr particle;
    
};

class Gate{
public:
    Gate(ofVec2f position){
        this->position = position;
    }
    
    void draw(){
        ofSetColor(ofColor::darkGray);
        ofSetLineWidth(3);
        ofDrawLine(position,ofVec2f(position.x,position.y+width));
    }
    
    ofVec2f position;
    const float width = 100;
};


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void gateActivated();
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
    
    World2D_ptr world;
    vector<User> users;
    vector<Gate> gates;
    
    
    
    
};
