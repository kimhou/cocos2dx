//
//  BirdSprite.cpp
//  flappyBirdDemo
//
//  Created by kim on 15/4/2.
//
//

#include "BirdSprite.h"
#include "AtlasLoader.h"

bool BirdSprite::init(){
    log("bird init");
    
    bird = Sprite::create();
    addChild(bird);
    
    PhysicsBody *body = PhysicsBody::create();
    body->addShape(PhysicsShapeCircle::create(12));
    body->setDynamic(true);
    body->setLinearDamping(0.5f);
    body->setGravityEnable(false);
    bird->setPhysicsBody(body);

    Animation *idleAnimation = Animation::create();
    idleAnimation->setDelayPerUnit(1.0f/8.0f);
    for(int i = 0; i < 3; i++){
        string fileName = String::createWithFormat("bird0_%d", i)->getCString();
        SpriteFrame *frame = AtlasLoader::getInstance()->getSpriteFrameByName(fileName);
        idleAnimation->addSpriteFrame(frame);
    }
    Animate *animate = Animate::create(idleAnimation);
    idleAction = RepeatForever::create(animate);
    
    ActionInterval *up = MoveBy::create(0.4f, Point(0, 8));
    ActionInterval *down = up->reverse();
    swingAction = RepeatForever::create(Sequence::create(up, down, NULL));
    return true;
}

void BirdSprite::idle(){
    bird->runAction(idleAction);
    bird->runAction(swingAction);
}

void BirdSprite::fly(){
    bird->stopAction(swingAction);
    bird->getPhysicsBody()->setGravityEnable(true);
}

void BirdSprite::jump(){
    bird->getPhysicsBody()->setVelocity(Vect(0, 160));
}

void BirdSprite::die(){
    bird->stopAllActions();
}

