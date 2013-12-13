#include "GamePlay.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;
CCScene* GamePlay::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GamePlay *layer = GamePlay::create();

    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GamePlay::init()
{
//    this->setTouchPriority(2);
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //add player
    
    sprPlayer = CCSprite::create("Player/Player_front1.png");
    sprPlayer->setPosition(ccp(size.width/2,size.height/10));
    this->addChild(sprPlayer, ZORDER_PLAYER);
    flyWhenStart();
    unscheduleUpdate();
    this->setTouchEnabled(true);
    return true;
}

void GamePlay::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GamePlay::flyWhenStart(){
    sprPlayer->runAction(CCMoveBy::create(4, ccp(0, CCDirector::sharedDirector()->getWinSize().height/1.5)));
}
#pragma mark Touch
void GamePlay::ccTouchesBegan(CCSet *touches, CCEvent *event){
    CCLOG("Touch begin");
}

void GamePlay::ccTouchesMoved(CCSet *touches, CCEvent *event){
}

void GamePlay::ccTouchesEnded(CCSet *touches, CCEvent *event){
    CCLOG("Touch end");
    CCTouch *touch = (CCTouch*)touches->anyObject();
    CCPoint touchLoc = this->getParent()->convertTouchToNodeSpace(touch);
    CCRect touchRect = CCRect(touchLoc.x, touchLoc.y, 70, 70);
    
    CCRect playerRect = CCRectMake(sprPlayer->getPosition().x, sprPlayer->getPosition().y, sprPlayer->getContentSize().width/2, sprPlayer->getContentSize().height/2);
    if (touchRect.intersectsRect(playerRect)){
        sprPlayer->runAction(CCMoveBy::create(4, ccp(0, (-1) * CCDirector::sharedDirector()->getWinSize().height/1.5)));
    }

}

GamePlay::~GamePlay(){
}

void GamePlay::update(float dt){
}
bool GamePlay::containsTouchLocation(cocos2d::CCTouch* touch){
    return false;
}