//
//  LoadingScene.h
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#ifndef __flappyBirdDemo__LoadingScene__
#define __flappyBirdDemo__LoadingScene__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class LoadingScene : public Scene{
public:
    LoadingScene();
    ~LoadingScene();
    
    CREATE_FUNC(LoadingScene);

    
private:
    virtual bool init();
    void loadingCallback(Texture2D* texture);
};

#endif /* defined(__flappyBirdDemo__LoadingScene__) */
