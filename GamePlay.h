//
//  GamePlay.h
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#ifndef __goldMiner__GamePlay__
#define __goldMiner__GamePlay__

#include <stdio.h>
#include <iostream>
#include "StartGame.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
class GamePlay:public Layer{
public:
    static Scene *secene();
    virtual bool init();
    CREATE_FUNC(GamePlay);
    void GoGame();
    void music();
};


#endif /* defined(__goldMiner__GamePlay__) */
