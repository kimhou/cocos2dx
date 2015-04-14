//
//  AtlasLoader.cpp
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#include "AtlasLoader.h"

AtlasLoader* AtlasLoader::sharedAtlasLoader = nullptr;

AtlasLoader* AtlasLoader::getInstance(){
    if(sharedAtlasLoader == NULL){
        sharedAtlasLoader = new AtlasLoader();
        if(!sharedAtlasLoader->init()){
            delete sharedAtlasLoader;
            sharedAtlasLoader = NULL;
            CCLOG("ERROR: init AtlasLoader failure");
        }
    }
    return sharedAtlasLoader;
}

AtlasLoader::AtlasLoader(){};
bool AtlasLoader::init(){
    return true;
}

void AtlasLoader::loadAtlas(string fileName, Texture2D* texture){
    string frameInfo = FileUtils::getInstance()->getStringFromFile(fileName);
    
    unsigned long position = frameInfo.find_first_of("\n");
    Atlas atlas;
    
    string line = frameInfo.substr(0, position);
    frameInfo = frameInfo.substr(position + 1);
    
    while(line != ""){
        sscanf(line.c_str(), "%s %d %d %f %f %f %f", atlas.name, &atlas.width, &atlas.height, &atlas.start.x, &atlas.start.y, &atlas.end.x, &atlas.end.y);
        atlas.start.x *= 1024;
        atlas.start.y *= 1024;
        atlas.end.x *= 1024;
        atlas.end.y *= 1024;
        
        position = frameInfo.find_first_of("\n");
        line = frameInfo.substr(0, position);
        frameInfo = frameInfo.substr(position + 1);
        
        if(atlas.name == string("land")){
            atlas.start.x += 1;
        }
        
        Rect rect = Rect(atlas.start.x, atlas.start.y, atlas.width, atlas.height);
        auto frame = SpriteFrame::createWithTexture(texture, rect);
        _spriteFrames.insert(string(atlas.name), frame);
    }
    
}

SpriteFrame* AtlasLoader::getSpriteFrameByName(string name){
    return _spriteFrames.at(name);
}