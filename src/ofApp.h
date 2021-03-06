#pragma once

#include "ofMain.h"

// Scenes
#include "OpeningTitle.h"
#include "Intro.h"
#include "Rectangular.h"
#include "Bubbles.h"
#include "Tile.h"
#include "EnergyBliss.h"
#include "SquareFall.h"

#include "Stripe.h"
#include "Rectfall.h"
#include "Hexagon.h"
#include "LiveStage.h"
#include "Arc.h"
#include "Visualizer.h"
#include "Ink.h"
#include "Wave.h"
#include "Pentagon.h"
#include "HurlyBurly1.h"
#include "HurlyBurly2.h"
#include "HurlyBurly3.h"
#include "MonochromeTile.h"
#include "HurlyBurly4.h"
#include "HurlyBurly5.h"
#include "Tricle.h"
#include "ChikaChika.h"
#include "Triangle.h"
#include "PizzaStripe.h"
#include "MonochromeStripe.h"
#include "MonochromeStripeMove.h"
#include "Nexus.h"
#include "TrianglesOnLines.h"
#include "Gravity.h"
#include "Trink.h"
#include "RotateShimaShima.h"
#include "TriForce.h"
#include "Spotlights.h"
#include "Ending.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int sceneNumber;
    bool sceneChangedFlag;
    
    // Scenes
    OpeningTitle S00OpeningTitle;
    Intro s01Intro;
    Rectangular s02Rectangular;
    Bubbles s03Bubbles;
    Tile s04Tile;
    EnergyBliss s05EnergyBliss;
    
    Stripe sXXStripe;
    
    
    Rectfall sX1Rectfall;
    Hexagon sX2Hexagon;
    LiveStage SX3LiveStage;
    Arc SX4Arc;
    Visualizer SX5Visualizer;
    Ink SX6Ink;
    Wave SX7Wave;
    Pentagon SX8Pentagon;
    HurlyBurly1 SX9HurlyBurly1;
    HurlyBurly2 SX10HurlyBurly2;
    HurlyBurly3 SX12HurlyBurly3;
    HurlyBurly4 SX13HurlyBurly4;
    HurlyBurly5 SX14HurlyBurly5;
    MonochromeTile SX11MonochromeTile;
    Tricle SX15Tricle;
    ChikaChika SX16ChikaChika;
    Triangle SX17Triangle;
    SquareFall SX18SquareFall;
    //PizzaStripe SX18PizzaStripe;
    MonochromeStripe SX19MonochromeStripe;
    MonochromeStripeMove SX20MonochromeStripeMove;
    Nexus SX21Nexus;
    TrianglesOnLines SX22TrianglesOnLines;
    Gravity SX23Gravity;
    Trink SX24Trink;
    RotateShimaShima SX25RotateShimaShima;
    TriForce SX26TriForce;
    Spotlights SX27Spotlights;
    Ending SX28Ending;
};
