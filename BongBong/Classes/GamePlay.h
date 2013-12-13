#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "cocos2d.h"
#include "Definition.h"
using namespace cocos2d;
USING_NS_CC;

class GamePlay : public cocos2d::CCLayer
{
public:
    ~GamePlay();
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    //start
    void flyWhenStart();
    void update(float dt);
    
#pragma mark Touch
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *event);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *event);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *event);
    bool containsTouchLocation(cocos2d::CCTouch* touch);


    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GamePlay);
    
private:
    //player
    CCSprite* sprPlayer;
};

#endif // __HELLOWORLD_SCENE_H__
