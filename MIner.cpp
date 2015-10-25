//
//  MIner.cpp
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#include "MIner.h"
Miner::Miner(){
    
    
  //  Texture2D *texture=Director::getInstance()->getTextureCache()->addImage("miner.png");
    //auto minerSprite=Sprite::initWithTexture(texture);
   // auto minerSprite=Sprite::create("miner.png");//开辟空间并初始化
    miner=(Sprite*)Sprite::initWithFile("miner.png");
}

void Miner::MinerAction(){
    SpriteFrameCache *cache=SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("minerAction.plist","minerAction.png");
    char PFileName[50];
    sprintf(PFileName, "minerAction.plist");
    __Dictionary *dictionary=__Dictionary::createWithContentsOfFile(PFileName);
    __Dictionary *dic=(__Dictionary*)dictionary->objectForKey("frames");
    int num=dic->count();
    log("num=%d",num);
    Vector<SpriteFrame*>vec;
    for (int i=1; i<=num; i++) {
        std::string str=StringUtils::format("miner_07%02d.png",i);
        log("%s",str.c_str());
        auto frame=cache->getSpriteFrameByName(str);
        vec.pushBack(frame);
    }
    auto animation=Animation::createWithSpriteFrames(vec,0.1f);
    auto animate=Animate::create(animation);
    this->runAction(RepeatForever::create(animate));

}