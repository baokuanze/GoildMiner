//
//  MIner.h
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#ifndef __goldMiner__MIner__
#define __goldMiner__MIner__

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;

class Miner:public Sprite{

public:
    Miner();
    void MinerAction();
    Sprite *miner;
    

};




#endif /* defined(__goldMiner__MIner__) */
