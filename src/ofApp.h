#pragma once

#include "ofMain.h"
#include "ofxGUI.h"
#include "MsaPhysics2D.h"

using namespace msa::physics;

class User{
public:
    User(World2D_ptr* world, ofVec2f position, ofVec2f velocity){
        this->particle = (*world)->makeParticle();
        this->particle->moveTo(position);
        this->particle->addVelocity(velocity);
        this->particle->setRadius(3);
        this->particle->disableCollision();
        this->startPosition = position;
    }
    
    void draw(){
        ofSetColor(ofColor::darkRed);
        ofDrawCircle(particle->getPosition(), particle->getRadius());
        std::string info;;
        info+=ofToString(particle->getPosition());
        ofDrawBitmapString(info, particle->getPosition());
    }
    
    bool hasTravelledForTooLongNow(){
        float dist = startPosition.distance(this->particle->getPosition());
        return dist > maxDist;
    }
    
    Particle2D_ptr particle;
    ofVec2f startPosition;
    float maxDist = 30;
    
};

class Gate{
public:
    Gate(ofVec2f position, vector<User>* users, World2D_ptr* world){
        this->position = position;
        this->users = users;
        this->world = world;
    }
    
    void addNeighbours(std::vector<Gate*> neighbours){
        this->neighbours = neighbours;
    }
    
    
    void draw(){
        if(ofGetElapsedTimef() - lastActivationTime < timingThreshold){
            color = ofColor::darkRed;
        }else{
            color = ofColor::darkGray;
        }
        
        ofSetColor(color);
        ofSetLineWidth(3);
        ofDrawLine(position,ofVec2f(position.x,position.y+width));
    }
    
    
    void activate(){
        lastActivationTime = ofGetElapsedTimef();
        
        for(auto& n : neighbours){
            if(n->isActivated()){
                //create particle and add velociy
                float velocity =  std::abs(distanceToNeighbour/(n->lastActivationTime - this->lastActivationTime))/100;
                ofVec2f velocityVector = ofVec2f((this->position.x-n->position.x)*velocity,0);
                User user = *new User(world,this->position,velocityVector);
                this->users->push_back(user);
                break;
            }
        }
    }
    
    bool isActivated(){
        return ofGetElapsedTimef() - lastActivationTime < timingThreshold;
    }
    
    vector<Gate*> neighbours;
    vector<User>* users;
    World2D_ptr* world;
    ofColor color = ofColor::darkGray;
    float lastActivationTime = 0;
    float timingThreshold = 2.5;
    const float distanceToNeighbour = 2.0;
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
    
    // GUI
    ofxPanel gui;
    ofParameter<bool> drawFloor;
    ofParameter<bool> drawGates;
    
};
