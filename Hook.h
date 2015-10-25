//
//  Hook.h
//  goldMiner
//
//  Created by student on 15/8/19.
//
//

#ifndef __goldMiner__Hook__
#define __goldMiner__Hook__

#include <stdio.h>
#include<iostream>
#include <cocos2d.h>
USING_NS_CC;
class Hook:public Sprite{
public:
    static Hook *createHook();
    virtual bool init();
    void rotate();
    void runTarget();
    void runToPoint(Point point);
    bool hookAction;
    
};



#endif /* defined(__goldMiner__Hook__) */
