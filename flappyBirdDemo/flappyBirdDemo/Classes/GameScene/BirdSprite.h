//
//  BirdSprite.h
//  flappyBirdDemo
//
//  Created by kim on 15/4/2.
//
//

#ifndef __flappyBirdDemo__BirdSprite__
#define __flappyBirdDemo__BirdSprite__

#include <stdio.h>
#include "cocos2d.h"
#include <SimpleAudioEngine.h>

using namespace::cocos2d;
using namespace std;

class BirdSprite : public Node{
public:
    CREATE_FUNC(BirdSprite);
    virtual bool init();
    
    void idle();
    void fly();
    void jump();
    void die();
    
private:
    Sprite *bird;
    Action *idleAction;
    Action *swingAction;
};

#endif /* defined(__flappyBirdDemo__BirdSprite__) */
