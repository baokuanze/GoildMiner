//
//  Item.cpp
//  goldMiner
//
//  Created by student on 15/8/19.
//
//

#include "Item.h"
Item* Item::createItem(){
    Item *item = new(std::nothrow) Item();
    if (item && item->init())
    {
        item->autorelease();
        return item;
    }
    else
    {
        delete item;
        item = NULL;
        return NULL;
    }

}

bool Item::init(){
    if (!Sprite::init()) {
        return false;
    }
    itemAction=false;
    return true;
}

void Item:: ItemLoaction(ItemType type,BigType bigType){
        switch (type)
        {
            case 0:
               {
                switch (bigType) {
                    case 0:
                    {
                     this->initWithFile("gold_large.png");
                        this->score=300;
                        this->weight=40;
                        _type = type;
                        break;
                    }
                    case 1:
                    {
                       this->initWithFile("gold_middle.png");
                        this->score=200;
                        this->weight=20;
                        _type = type;
                        break;
                    }
                    case 2:
                    {
                        this->initWithFile("gold_small.png");
                        this->score=100;
                        this->weight=10;
                        _type = type;
                        break;
                    }
            
                 }
                   break;
               }
    
           case 1:
               {
                switch (bigType) {
                    case 0:
                    {
                        this->initWithFile("stone_large.png");
                        this->score=30;
                        this->weight=40;
                        _type = type;
                        break;
                    }
                    case 1:
                    {
                        this->Sprite::initWithFile("stone_middle.png");
                        this->score=20;
                        this->weight=20;
                        _type = type;
                        break;
                    }
                    case 2:
                    {
                        this->initWithFile("stone_small.png");
                        this->score=10;
                        this->weight=10;
                        _type = type;
                        break;
                    }
                    default:
                   break;
        
             }
                    break;
               }
               
          case 2:
               {
                switch (bigType) {
                    case 0:
                    {
                        this->initWithFile("diamond_large.png");
                        this->score=400;
                        this->weight=40;
                        _type = type;
                        break;
                    }
                    case 1:
                    {
                       this->initWithFile("diamond_middle.png");
                        this->score=300;
                        this->weight=20;
                        _type = type;
                        break;
                    }
                    case 2:
                    {
                     this->initWithFile("diamond_small.png");
                        this->setAnchorPoint(Vec2(0,0));
                        this->score=200;
                        this->weight=10;
                        _type = type;
                        break;
                    }
                    default:
                        break;
                        
                }
                   break;
              }
           
         case 3:
            {
              switch (bigType) {
                    case 0:
                    {
                        this->initWithFile("secret_large.png");
                        this->score=400;
                        this->weight=40;
                        _type = type;
                        break;
                    }
                    case 1:
                    {
                        this->initWithFile("secret_middle.png");

                        this->score=200;
                        this->weight=20;
                        _type = type;
                        break;
                    }
                    case 2:
                    {
                        this->initWithFile("secret_small.png");
                        this->score=50;
                        this->weight=10;
                        _type = type;
                        break;
                    }
                        
                }
                break;
            }
            
        }
    }





