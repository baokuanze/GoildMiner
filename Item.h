//
//  Item.h
//  goldMiner
//
//  Created by student on 15/8/19.
//
//

#ifndef __goldMiner__Item__
#define __goldMiner__Item__

typedef enum{
    item_large=0,
    item_middle,
    item_small
}BigType;
typedef  enum{
    gold=0,
    stone,
    diamond,
    secret
}ItemType;

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
USING_NS_CC;
class Item :public Sprite{
    
public:
    static Item* createItem();
    virtual bool init();
    void ItemLoaction(ItemType type,BigType bigType);
    
    ItemType _type;
    BigType bigType;
    Sprite *sprite;
    int score;
    int weight;
    bool itemAction;
   
};

#endif /* defined(__goldMiner__Item__) */
