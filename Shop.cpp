//
//  Shop.cpp
//  goldMiner
//
//  Created by student on 15/8/20.
//
//

#include "Shop.h"
#include "StartGame.h"
extern int level;
extern int Water;
extern int Boom;
Scene * Shop::scene(){
   auto scene=Scene::create();
    auto layer=Shop::create();
    scene->addChild(layer);
    return scene;
}
bool Shop:: init(){
    if (!Layer::init()) {
        return false;
    }
    auto node=CSLoader::createNode("MainScene.csb");
    this->addChild(node);
    auto sprite=node->getChildByName("Sprite_1");
    auto pageView=node->getChildByName<ui::PageView*>("PageView_1");
    auto pageView2=node->getChildByName<ui::PageView*>("PageView_2");
    auto liftButton=node->getChildByName<ui::Button*>("Button_1");
    auto rightButton=node->getChildByName<ui::Button*>("Button_2");
    auto buyButton=node->getChildByName<ui::Button*>("Button_3");
    
    liftButton->addClickEventListener([pageView,pageView2](Ref*sender){
        auto index=pageView->getCurPageIndex();
        auto index2=pageView2->getCurPageIndex();
        index2++;
        index++;
        if (index<0) {
            return ;
        }
        pageView->scrollToPage(index);
        pageView2->scrollToPage(index2);

    });
    rightButton->addClickEventListener([pageView,pageView2](Ref*){
        auto index=pageView->getCurPageIndex();
        auto index2=pageView2->getCurPageIndex();
        index--;
        index2--;
        if (index>1) {
            return ;
        }
        pageView->scrollToPage(index);
        pageView2->scrollToPage(index2);
    
    });

    auto visibleSize=Director::getInstance()->getVisibleSize();
    buyButton->addClickEventListener([sprite,pageView](Ref*){
        sprite->stopAllActions();
        auto time=CSLoader::createTimeline("MainScene.csb");
        time->gotoFrameAndPlay(100,140,true);
        sprite->runAction(time);
      
        if (pageView->getCurPageIndex()==0) {
            if (Water==3) {
                MessageBox("每关的PowerWater不能超过3个","谢谢");
                return ;
            }else
            {
                Water=Water+1;
            }

        }else if (pageView->getCurPageIndex()==1){
            if (Boom>=1) {
                
                MessageBox("每关的Boom不能超过1个","谢谢");
            }else{
                Boom=Boom+1;
            }
        }
        
    });
    
    if (level==1) {
        MenuItemFont *font=MenuItemFont::create("NEW GAME");
        font->setCallback(CC_CALLBACK_0(Shop::goNext, this));
        font->setColor(Color3B::RED);
        auto menu=Menu::create(font, NULL);
        menu->setPosition(Vec2(visibleSize.width/2+140,visibleSize.height/2-120));
        this->addChild(menu);
        //执行动作
        auto time=CSLoader::createTimeline("MainScene.csb");
        time->gotoFrameAndPlay(0,50,true);
        sprite->runAction(time);
    }else if(level<=6){
        MenuItemImage *item=MenuItemImage::create("shopArrow.png", "shopArrow.png");
        item->setCallback(CC_CALLBACK_0(Shop::goNext, this));
        auto  menu=Menu::create(item, NULL);
        menu->setPosition(425, 30);
        this->addChild(menu);
        auto time=CSLoader::createTimeline("MainScene.csb");
        time->gotoFrameAndPlay(55,95,true);
        sprite->runAction(time);
        

    }else if(level>6){
        MenuItemFont *font1=MenuItemFont::create("PASS OUT");
        font1->setPosition(Vec2(visibleSize.width/2+100,visibleSize.height/2));
        this->addChild(font1);
        MenuItemFont *font=MenuItemFont::create("NEW GAME");
        font->setCallback(CC_CALLBACK_0(Shop::revers,this));
        font->setColor(Color3B::RED);
        auto menu=Menu::create(font, NULL);
        menu->setPosition(Vec2(visibleSize.width/2+100,visibleSize.height/2-60));
        this->addChild(menu);
        ParticleSystem *par=ParticleFireworks::create();
        par->setTexture(TextureCache().addImage("fengye.png"));
        par->setPosition(Vec2(280, 0));
        par->setAutoRemoveOnFinish(true);
        this->addChild(par);
        Water=0;//将强力水设置为0;
        auto time=CSLoader::createTimeline("MainScene.csb");
        time->gotoFrameAndPlay(100,140,true);
        sprite->runAction(time);
        
    }
    return true;
}

void Shop::revers(){
level=1;
Director::getInstance()->pushScene(StartGame::secne());
}
void Shop:: goNext(){
    Director::getInstance()->pushScene(StartGame::secne());
}
