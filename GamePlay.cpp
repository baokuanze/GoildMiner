//
//  GamePlay.cpp
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#include "GamePlay.h"
Scene * GamePlay::secene(){
    auto secene=Scene::create();
    auto layer=GamePlay::create();
    secene->addChild(layer);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("backMusic.mp3");
    SimpleAudioEngine::getInstance()->playBackgroundMusic("backMusic.mp3",true);
    return secene;

}
bool GamePlay:: init(){
    auto visibileSize=Director::getInstance()->getVisibleSize();
    auto sprite=Sprite::create("MainMenu.png");
    sprite->setPosition(visibileSize.width/2,visibileSize.height/2);
    this->addChild(sprite);
    
    auto playItem=MenuItemImage::create("PlayMenu.png", "PlayMenu.png");
    playItem->setCallback(CC_CALLBACK_0(GamePlay::GoGame,this));
    auto menu=Menu::create(playItem, NULL);
    menu->setPosition(Vec2(visibileSize.width/2-110,visibileSize.height-98));
    this->addChild(menu,1);
 
    
    auto item=MenuItemImage::create("soundController.png", "soundController.png");
    auto item1=MenuItemImage::create("soundController2.png", "soundController2.png");
    auto toggle=MenuItemToggle::create();
    toggle->addSubItem(item);
    toggle->addSubItem(item1);
    toggle->setSelectedIndex(0);
    toggle->setCallback(CC_CALLBACK_0(GamePlay::music, this));
    auto menu1=Menu::create(toggle, NULL);
    menu1->setPosition(Vec2(50, 50));
    this->addChild(menu1);
    return true;
}
void GamePlay::music(){
    
    static bool fag=true;
    if (fag)
    {
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        fag=false;
    }
    else
    {
        SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
        fag=true;
    }

}

void GamePlay:: GoGame(){
    Director::getInstance()->pushScene(StartGame::secne());
    //Director::getInstance()->replaceScene(StartGame::secne());
   // auto sece=StartGame::secne();
   // TransitionFlipY *flip=TransitionFlipY::create(2, sece,TransitionFlipY::Orientation::DOWN_OVER);
   // Director::getInstance()->replaceScene(flip);
}
