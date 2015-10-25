//
//  Tools.cpp
//  goldMiner
//
//  Created by student on 15/8/21.
//
//

#include "Tools.h"
bool Tools:: isCollision(Sprite *sprite1,Sprite *sprite2){
    Rect rect1 = sprite1->boundingBox();
    Rect rect2 = sprite2->boundingBox();
    float rect1MinX = rect1.getMinX()+3;
    float rect1MaxX = rect1.getMaxX()-3;
    float rect1MinY = rect1.getMinY()+5;
    float rect1MaxY = rect1.getMaxY()-5;
    
    float rect2MinX = rect2.getMinX()+8;
    float rect2MaxX = rect2.getMaxX()-8;
    float rect2MinY = rect2.getMinY()+8;
    float rect2MaxY = rect2.getMaxY()-8;
    
    if ( rect1MinX>rect2MaxX ||rect1MinY>rect2MaxY)
        return false;
    if ( rect2MinX>rect1MaxX ||rect2MinY>rect1MaxY )
        return false;
    return true;
}
bool Tools:: Collision(Sprite *sprite1,Menu *sprite2){
    Rect rect1 = sprite1->boundingBox();
    Rect rect2 = sprite2->boundingBox();
    float rect1MinX = rect1.getMinX()+3;
    float rect1MaxX = rect1.getMaxX()-3;
    float rect1MinY = rect1.getMinY()+5;
    float rect1MaxY = rect1.getMaxY()-5;
    
    float rect2MinX = rect2.getMinX()+8;
    float rect2MaxX = rect2.getMaxX()-8;
    float rect2MinY = rect2.getMinY()+8;
    float rect2MaxY = rect2.getMaxY()-8;
    
    if ( rect1MinX>rect2MaxX ||rect1MinY>rect2MaxY)
        return false;
    if ( rect2MinX>rect1MaxX ||rect2MinY>rect1MaxY )
        return false;
    return true;

}