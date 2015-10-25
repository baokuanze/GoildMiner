//
//  StartGame.h
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#ifndef __goldMiner__StartGame__
#define __goldMiner__StartGame__



#include "Item.h"
#include "Shop.h"
#include <stdio.h>
#include <iostream>
USING_NS_CC;
class Miner;
class Hook;
class StartGame:public Layer{
public:
    Hook *hook;
    Miner *miner;
    Label *lable5;
    Menu *menu;
    MenuItemToggle *toggle;
    void item();
    void move();
    static Scene *secne();
    virtual bool init();
    CREATE_FUNC(StartGame);
    void consumeTime(float dt);
    void testCollin(float dt);

    void removeItem(Node *render);
    void removeBoom();//移除炸弹
    void chooseItem(ItemType type,int count);
    void changeSelect(float dt);
    virtual  bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void draw(Renderer *renderer, const Mat4& transform,uint32_t flags);
    __Array *itemArray;
    ~StartGame();
protected:
    CustomCommand _customCommand;
    void onDraw( const cocos2d::Mat4 &transform, uint32_t flags);
};

#endif /* defined(__goldMiner__StartGame__) */
