//
//  LoadingScene.cpp
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#include "LoadingScene.h"
#include "AtlasLoader.h"
#include "WellcomeScene.h"

LoadingScene::LoadingScene(){}
LoadingScene::~LoadingScene(){}

bool LoadingScene::init(){
    log("init");
    if(Scene::init()){
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();
        
        Sprite* bg = Sprite::create("image/splash.png", Rect(0, 0, visibleSize.width, visibleSize.height));
        bg->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
        
        this->addChild(bg);
        
        Director::getInstance()->getTextureCache()->addImageAsync("image/atlas.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
        
        return true;
    }else{
        return false;
    }
}


void LoadingScene::loadingCallback(Texture2D* texture){
    log("loading callback");
    AtlasLoader::getInstance()->loadAtlas("image/atlas.txt", texture);
    
    auto scene = WellcomeScene::createScene();
    TransitionScene* transition = TransitionFade::create(1, scene);
    Director::getInstance()->replaceScene(transition);
}