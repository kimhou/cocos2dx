//
//  WellcomeScene.cpp
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#include "WellcomeScene.h"
#include "AtlasLoader.h"
#include <SimpleAudioEngine.h>
#include "BirdSprite.h"
#include "GameScene.h"

BirdSprite *bird;

Scene* WellcomeScene::createScene(){
    log("wellcome scene createScene");
    Scene* scene = Scene::create();
    Layer* layer = WellcomeScene::create();
    scene->addChild(layer);
    return scene;
}

bool WellcomeScene::init(){
    log("wellcome scene init");
    if(!Layer::init()){
        return false;
    }
    
    Size vsize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite* bg = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
    bg->setAnchorPoint(Point::ZERO);
    bg->setPosition(Point::ZERO);
    addChild(bg);
    
    Sprite* title = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("title"));
    title->setPosition(Point(vsize.width/2, vsize.height - 10 - (((title->getSpriteFrame())->getRect()).size.height)));
    addChild(title);
    
    Sprite* land = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
    land->setAnchorPoint(Point::ZERO);
    land->setPosition(Point::ZERO);
    addChild(land);

    Sprite *button = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play")),
        *buttonTouch = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("button_play"));
    buttonTouch->setPositionY(-5);
    MenuItemSprite *item = MenuItemSprite::create(button, buttonTouch);
    item->setCallback(CC_CALLBACK_0(WellcomeScene::playButtonClickListener, this));
    
    auto menu = Menu::create(item, NULL);
    menu->setPosition(Point(vsize.width/2, vsize.height/2));
    addChild(menu);
    
    bird = BirdSprite::create();
    bird->setPosition(Point(vsize.width/2, vsize.height/2 - 80));
    addChild(bird);
    
    bird->idle();

    return true;
}

void WellcomeScene::playButtonClickListener(){
    log("playButtonClickListener");
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/sfx_swooshing.ogg");
    
    auto gameScene = GameScene::createScene();
    TransitionScene *transition = TransitionFade::create(0, gameScene);
    Director::getInstance()->replaceScene(transition);
}



