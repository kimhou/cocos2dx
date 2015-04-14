//
//  GameScene.h
//  flappyBirdDemo
//
//  Created by kim on 15/4/2.
//
//

#ifndef __flappyBirdDemo__GameScene__
#define __flappyBirdDemo__GameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "BirdSprite.h"

using namespace cocos2d;
using namespace std;

typedef enum _game_status{
    GAME_STATUS_READY = 1,
    GAME_STATUS_START,
    GAME_STATUS_OVER
}GAME_STATUS;

class GameScene : public Layer{
public:
    static Scene *createScene();
    virtual bool init();
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    GAME_STATUS status;
    
private:
    BirdSprite *bird;
};

#endif /* defined(__flappyBirdDemo__GameScene__) */
