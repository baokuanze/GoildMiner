//
//  StartGame.cpp
//  goldMiner
//
//  Created by student on 15/8/17.
//
//

#include "StartGame.h"
#include "Data.h"
#include "Tools.h"
#include "MIner.h"
#include "Hook.h"
Scene * StartGame:: secne(){
    auto scene=Scene::create();
    auto layer=StartGame::create();
    scene->addChild(layer);
    return scene;
}

StartGame::~ StartGame(){
    hook->release();
    miner->release();
    itemArray->release();
}
bool StartGame:: init(){
    if (!Layer::init()) {
        return false;
    }
     itemArray=__Array::create();
     itemArray->retain();
     int k=arc4random()%6+1;
     std::string str= StringUtils::format("mineBG%d.png",k);
     auto visibleSize=Director::getInstance()->getVisibleSize();
     auto sprite=Sprite::create(str);
     sprite->setPosition(visibleSize.width/2,visibleSize.height/2);
     this->addChild(sprite);
    //离子
    ParticleSystemQuad* quad = ParticleSystemQuad::create("fengye.plist");
    quad->setBlendAdditive(true);
    quad->setAutoRemoveOnFinish(true);
    quad->setPosition(Vec2(400, 300));
    this->addChild(quad);

    //黄金
     char a[50];
     sprintf(a, "%d",score[level-1]);
     auto sprite1=Sprite::create("Gold.png");
     sprite1->setPosition(visibleSize.width/2-200,visibleSize.height/2+130);
     auto lable1=Label::createWithSystemFont(a, "fonts/Marker Felt.ttf ", 28);
     lable1->setTextColor(Color4B::GREEN);
     lable1->setPosition(visibleSize.width/2-150,visibleSize.height/2+130);
     lable1->setTag(10);
     this->addChild(lable1);
     this->addChild(sprite1);
    
    //钱
     auto sprite2=Sprite::create("rmbImage.png");
     sprite2->setPosition(visibleSize.width/2-200,visibleSize.height/2+90);
     auto lable2=Label::createWithSystemFont("0", "fonts/Marker Felt.ttf ", 28);
     lable2->setPosition(visibleSize.width/2-150,visibleSize.height/2+90);
     lable2->setTag(20);
     lable2->setTextColor(Color4B::RED);
     this->addChild(lable2);
     this->addChild(sprite2);
    
    //矿工
     auto sprite3=Sprite::create("miner_0707.png");
     sprite3->setPosition(visibleSize.width/2+180,visibleSize.height/2+130);
     char c[50];
     sprintf(c, "%d",level);
     auto lable3=Label::createWithSystemFont(c, "fonts/Marker Felt.ttf ", 28);
     lable3->setPosition(visibleSize.width/2+220,visibleSize.height/2+130);
     lable3->setTag(30);
     lable3->setTextColor(Color4B::GREEN);
     this->addChild(lable3);
     this->addChild(sprite3);
    
    
     char d[50];
     sprintf(d, "%d",totalTime[level-1]);
     auto sprite4=Sprite::create("clockPlate.png");
     sprite4->setTag(4);
     sprite4->setPosition(visibleSize.width/2+180,visibleSize.height/2+90);
     auto lable4=Label::createWithSystemFont(d, "fonts/Marker Felt.ttf ", 28);
     lable4->setPosition(visibleSize.width/2+220,visibleSize.height/2+90);
     lable4->setTag(40);
     lable4->setTextColor(Color4B::GREEN);
     this->addChild(lable4);
     this->addChild(sprite4);
    
    
    auto item=MenuItemImage::create("qianglishui.png", "qianglishui.png");
    auto item1=MenuItemImage::create("qianglishui.png", "qianglishui.png");
    toggle=MenuItemToggle::create();
    toggle->addSubItem(item);
    toggle->addSubItem(item1);
    toggle->setScale(0.5);
    toggle->setSelectedIndex(0);
    toggle->setCallback([this](Ref*){
        //减少PowerWater数量
        auto lable=(Label*)this->getChildByTag(50);
        int num= atoi(lable->getString().c_str());
        if (num!=0){
            Water--;
            miner->setScale(1.5);
            
            //this->schedule(schedule_selector(StartGame::changeSelect),8);
             this->schedule(CC_CALLBACK_1(StartGame::changeSelect,this), 8, "changeSelect");
            
            lable->setString(StringUtils::format("%d",Water));
            this->testCollin(1.0);
        }else  if(num==0){
            toggle->setSelectedIndex(0);
            log("%d",toggle->getSelectedIndex());
        }
    });
    menu=Menu::create(toggle, NULL);
    menu->setPosition(Vec2(visibleSize.width/2+180, visibleSize.height/2+50));
    std::string str1=  StringUtils::format("%d",Water);
    lable5=Label::createWithSystemFont(str1,"fonts/Marker Felt.ttf", 28);
    lable5->setPosition(Vec2(visibleSize.width/2+220, visibleSize.height/2+50));
    lable5->setTag(50);
    lable5->setTextColor(Color4B::GREEN);
    this->addChild(lable5);
    this->addChild(menu);
    
    
    if (Boom) {
        auto item2=MenuItemImage::create("article_2001.png", "article_2001.png");
       
        item2->setScale(1.3);
        item2->setCallback(CC_CALLBACK_0(StartGame::removeBoom, this));
        auto menu=Menu::create(item2,NULL);
        menu->setPosition(Vec2(visibleSize.width/2+220, visibleSize.height/2+10));
        menu->setTag(60);
        this->addChild(menu);
    }
    
     miner=new Miner();
     miner->setPosition(visibleSize.width/2,visibleSize.height/2);
     this->addChild(miner);
     hook=Hook::createHook();
     hook->setAnchorPoint(Point(0.5, 1));
     hook->setPosition(visibleSize.width/2-5,visibleSize.height/2-20);
     hook->rotate();
     this->addChild(hook,1);
     //添加石头 黄金
     this->item();
     auto dispather=Director::getInstance()->getEventDispatcher();
     auto listener=EventListenerTouchOneByOne::create();
     listener->onTouchBegan=CC_CALLBACK_2(StartGame::onTouchBegan, this);
     //点击事件
     listener->onTouchEnded=[this](Touch *touch, Event *unused_event){
         if(hook->getPosition().x==235 && hook->getPosition().y == 140){
             hook->stopAllActions();
             hook->runTarget();
         }
     };
    dispather->addEventListenerWithSceneGraphPriority(listener ,this);

    this->schedule(CC_CALLBACK_1(StartGame::consumeTime,this), 1, "consumTime");
    this->schedule(schedule_selector(StartGame::testCollin), 0.01);
    return true;
}

void StartGame::removeBoom(){
    
    auto menu=this->getChildByTag(60);
    menu->removeFromParent();
    Boom=1;
    log("Boom=%d",Boom);

}


void StartGame:: changeSelect(float dt){
    log("changeSelect");
    if (toggle->getSelectedIndex()==1) {
        toggle->setSelectedIndex(0);
        miner->setScale(1);
        unschedule("changeSelect");
    }else{
        return;
    }
}

//碰撞检测
void StartGame::testCollin(float dt){
    auto visibleSize=Director::getInstance()->getWinSize();
    __Array *tempItemArray=__Array::create();
    tempItemArray->retain();
    Item *item;
    for (int i=0; i<itemArray->count(); i++) {
        item=(Item*)itemArray->getObjectAtIndex(i);
        if (Tools::isCollision(hook, item)&&!hook->hookAction&&!item->itemAction) {
            hook->stopAllActions();
            miner->MinerAction();
            tempItemArray->addObject(item);
            hook->hookAction = true;
            item->itemAction=true;
            if (toggle->getSelectedIndex()==1) {
                dt=0.5;
            }else{
                dt=2.0;
            }
            auto move=MoveTo::create(dt, Vec2(visibleSize.width/2-5,visibleSize.height/2-20));
            auto call=CallFunc::create(CC_CALLBACK_0(StartGame::move, this));
            auto sequence=Sequence::create(move,call, NULL);
            hook->runAction(sequence);
            if (item->itemAction) {
                item->setRotation(hook->getRotation());
                item->setAnchorPoint(Point(0.5, 1));
                hook->setAnchorPoint(Point(0.5, 0.7));
                item->setPosition(hook->getPosition());
                hook->setAnchorPoint(Point(0.5, 1));
            }
            if (item->_type==diamond||item->_type==secret) {
                ParticleSystemQuad* quad = ParticleSystemQuad::create("Boom.plist");
                quad->setBlendAdditive(true);
                quad->setAutoRemoveOnFinish(true);
                quad->setPosition(item->getPosition());
                quad->setDuration(0.2);
                this->addChild(quad);
            }
            auto move1=MoveTo::create(dt, Vec2(visibleSize.width/2-5,visibleSize.height/2-20));
            auto call1=CallFuncN::create(CC_CALLBACK_1(StartGame::removeItem, this));
            auto sequence1=Sequence::create(move1,call1, NULL);
            item->runAction(sequence1);
        }
    }
    itemArray->removeObjectsInArray(tempItemArray);
    tempItemArray->release();
}
void StartGame:: move(){
    hook->rotate();
}

void StartGame:: removeItem(Node *render){
    auto item=static_cast<Item*>(render);
    hook->hookAction=false;
    item->itemAction=false;
    item->removeFromParent();
    miner->stopAllActions();
    auto label=(Label*)this->getChildByTag(20);
    int score= atoi(label->getString().c_str())+item->score;
    label->setString(StringUtils::format("%d",score));


}
//画线
void StartGame:: draw(Renderer *renderer, const Mat4& transform,uint32_t flags){
    _customCommand.init(11);
    _customCommand.func =CC_CALLBACK_0(StartGame::onDraw, this,transform,flags);
    renderer->addCommand(&_customCommand);
}
void StartGame:: onDraw( const cocos2d::Mat4 &transform, uint32_t flags){
    Size s=Director::getInstance()->getVisibleSize();
    Director*director=Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    CHECK_GL_ERROR_DEBUG();
    glLineWidth(6.0f);
    DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
    DrawPrimitives::drawLine(Vec2(s.width/2-5,s.height/2-20),hook->getPosition());
}

//闹钟
void StartGame::consumeTime(float dt){
    auto lable1=(Label*)this->getChildByTag(40);
    int time= atoi(lable1->getString().c_str())-1;
    std::string str= StringUtils::format("%d",time);
    lable1->setString(str);
    if (time<=10) {
        auto sprite1=(Sprite*)this->getChildByTag(4);
        auto rotateto=RotateTo::create(0.1,10);
        auto rotateto1=RotateTo::create(0.1,-10);
        auto sequence=Sequence::create(rotateto,rotateto1, NULL);
        sprite1->runAction(RepeatForever::create(sequence));
    }
    if (time==0) {
    unschedule("consumTime");
    auto lable2=(Label*)this->getChildByTag(20);
    int lable2Num=atoi(lable2->getString().c_str());
    if (lable2Num<score[level-1]) {
        level=1;
    }else{
        level=level+1;
    }
      Director::getInstance()->pushScene(Shop::scene());
    }
}
void StartGame:: item(){
    auto num=itemNum[level-1];
    this->chooseItem(gold,num);
    this->chooseItem(stone,num);
    auto num1=diamondNum[level-1];
    this->chooseItem(diamond, num1);
    auto num2=secretNum[level-1];
    this->chooseItem(secret, num2);
    
}

void StartGame:: chooseItem(ItemType type,int count){
    for (int i=0; i<count; i++) {
        int x=arc4random()%400;
        int y=arc4random()%100;
        int k=arc4random()%3;
        Item *item=new Item();
        switch (k) {
            case 0:
                item->ItemLoaction(type, item_large);
                break;
            case 1:
                item->ItemLoaction(type, item_middle);
                break;
            case 2:
                item->ItemLoaction(type, item_small);
                break;
            default:
                break;
        }
        item->setPosition(Vec2(x, y));
        item->setAnchorPoint(Point(0.5, 1));
        itemArray->addObject(item);
        this->addChild(item,100);
    }
}
bool StartGame:: onTouchBegan(Touch *touch, Event *unused_event){
    return true;

}







