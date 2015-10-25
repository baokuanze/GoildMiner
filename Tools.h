//
//  Tools.h
//  goldMiner
//
//  Created by student on 15/8/21.
//
//

#ifndef __goldMiner__Tools__
#define __goldMiner__Tools__

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;
class Tools{
public:
    static bool isCollision(Sprite *sprite1,Sprite *sprite2);
    static bool Collision(Sprite *sprite1,Menu *sprite2);
};


#endif /* defined(__goldMiner__Tools__) */
