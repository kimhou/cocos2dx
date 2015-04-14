//
//  GameScene.cpp
//  flappyBirdDemo
//
//  Created by kim on 15/4/2.
//
//

#include "GameScene.h"
#include "AtlasLoader.h"

Scene *GameScene::createScene(){
    Scene *scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vect(0, -900));
    GameScene *gameScene = new GameScene();
    if(!gameScene->init()){
        log("create game scene error");
    }
    scene->addChild(gameScene);
    return scene;
}

bool GameScene::init(){
    log("game scene init");
    Size vsize = Director::getInstance()->getVisibleSize();
    
    auto bg = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
    bg->setPosition(Point(vsize.width/2, vsize.height/2));
    addChild(bg);
    
    auto edge = PhysicsBody::createEdgeBox(vsize);
    auto edgeSprite = Sprite::create();
    edgeSprite->setPosition(Point(vsize.width/2, vsize.height/2));
    edgeSprite->setPhysicsBody(edge);
    addChild(edgeSprite);
    
    bird = BirdSprite::create();
    bird->setPosition(Point(vsize.width/2, vsize.height/2));
    addChild(bird);
    bird->idle();
    status = GAME_STATUS_READY;
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    log("game scence touched");
    if(status == GAME_STATUS_READY){
        status = GAME_STATUS_START;
        bird->fly();
        bird->jump();
    }else if(status == GAME_STATUS_START){
        bird->jump();
    }
    return false;
}