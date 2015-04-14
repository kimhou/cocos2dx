//
//  AtlasLoader.h
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#ifndef __flappyBirdDemo__AtlasLoader__
#define __flappyBirdDemo__AtlasLoader__

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

typedef struct _atlas{
    char name[255];
    int width;
    int height;
    Point start;
    Point end;
}Atlas;

class AtlasLoader{
public:
    static AtlasLoader* getInstance();

    void loadAtlas(string fileName, Texture2D* texture);
    SpriteFrame* getSpriteFrameByName(string name);
    
protected:
    AtlasLoader();
    virtual bool init();

    static AtlasLoader* sharedAtlasLoader;
    Map<string, SpriteFrame*>_spriteFrames;
};


#endif /* defined(__flappyBirdDemo__AtlasLoader__) */
