//
//  Hook.cpp
//  goldMiner
//
//  Created by student on 15/8/19.
//
//

#include "Hook.h"
#define lift (240/130)*180/3.1415

Hook * Hook::createHook(){
    Hook *hook = new(std::nothrow) Hook();
    if (hook && hook->init())
    {
        hook->autorelease();
        return hook;
    }
    else
    {
        delete hook;
        hook = NULL;
        return NULL;
    }
}
bool Hook::init(){
    if (!Sprite::init()) {
        return false;
    }
    this->initWithFile("hook.png");
    hookAction=false;
    return true;
}

void Hook::rotate()
{
    auto rotate=RotateTo::create(2, 90);
    auto rotate1=RotateTo::create(2, -90);
    auto sequence=Sequence::create(rotate,rotate1, NULL);
    this->runAction(RepeatForever::create(sequence));
}
void Hook::runTarget(){
    float x;
    float y;
    if (this->getRotation()>0){
        if(this->getRotation()<=lift){
            x=240-tan(this->getRotation()*3.1415/180)*160;
            y=0.0;
        }else{
            x=0.0;
            y=160-240*tan((90-this->getRotation())*3.1415/180);
        }
    }else if (this->getRotation()<0){
        if (this->getRotation()>=-lift) {
            x=240-tan(this->getRotation()*3.1414/180)*160;
            y=0.0;
        }else{
            x=480;
            y=160-240*tan((90+this->getRotation())*3.1414/180);
        }
    }else if (this->getRotation()==0){
        x=240;
        y=0;
    }
    Point p=Point(x,y);
    this->runToPoint(p);
}
void Hook::runToPoint(Point point)
{
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto start=this->getPosition();
    float distance= sqrt((point.x-start.x)*(point.x-start.x))+ sqrt((point.y-start.y)*(point.y-start.y));
    int time=distance *0.01;
    auto move=MoveTo::create(time, point);
    auto moveBack=MoveTo::create(time,Vec2(visibleSize.width/2-5,visibleSize.height/2-20));
    auto call=CallFunc::create(CC_CALLBACK_0(Hook::rotate, this));
    auto sequence=Sequence::create(move,moveBack,call,NULL);
    this->runAction(sequence);
}


