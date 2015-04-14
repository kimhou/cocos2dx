//
//  WellcomeScene.h
//  flappyBirdDemo
//
//  Created by kim on 15/4/1.
//
//

#ifndef __flappyBirdDemo__WellcomeScene__
#define __flappyBirdDemo__WellcomeScene__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class WellcomeScene : public Layer{
public:
    CREATE_FUNC(WellcomeScene);
    static Scene* createScene();
protected:
    virtual bool init();
private:
    void playButtonClickListener();
};

#endif /* defined(__flappyBirdDemo__WellcomeScene__) */
