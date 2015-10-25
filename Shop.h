//
//  Shop.h
//  goldMiner
//
//  Created by student on 15/8/20.
//
//

#ifndef __goldMiner__Shop__
#define __goldMiner__Shop__

#include "Shop.h"
#include "StartGame.h"
#include <stdio.h>
#include <iostream>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
using namespace cocostudio;
using namespace ui;
using namespace timeline;

USING_NS_CC;
class Shop :public Layer{
public:
    static Scene *scene();
    virtual bool init();
    void goNext();
    void reverse();
    void changePage();
    void revers();
    CREATE_FUNC(Shop);
};




#endif /* defined(__goldMiner__Shop__) */
