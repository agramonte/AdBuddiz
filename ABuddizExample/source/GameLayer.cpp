#include "GameLayer.h"
#include "s3eAdBuddiz.h" //1. Add header file reference.
#include "s3e.h"
#include "s3eExt.h"
//1. Ad the header for the extension.

static int32 onAdCached(void* systemData, void* userData)
{
    CCLog("---------------------------Ad cached.");
    
    
    if (s3eAdBuddizShowAd() == S3E_RESULT_SUCCESS){ //4. Show ad.
        CCLog("---------------------------Ad was available to show.");
    } else {
        CCLog("---------------------------Not available to show.");
    }
    return 0;
}

static int32 onDidShowAd(void* systemData, void* userData)
{
    CCLog("---------------------------Ad shown.");
    return 0;
}

static int32 onFailToDisplayAd(void* systemData, void* userData)
{
    int failCode = *(int*)systemData;
    CCLog("---------------------------Ad failed to display: "+failCode);
    return 0;
}

static int32 onDidClickAd(void* systemData, void* userData)
{
    CCLog("---------------------------Ad clicked.");
    return 0;
}

static int32 onDidHideAd(void* systemData, void* userData)
{
    CCLog("---------------------------Ad is hidden.");
    return 0;
}

GameLayer::~GameLayer()
{
}

CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();

    // Add layer as a child to scene
    scene->addChild(layer);

    // Return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
    if (!CCLayer::init())
        return false;
    
    if (s3eAdBuddizAvailable()) { //2. Check if it is available.
        
        s3eAdBuddizSetTestMode(); //Optional: Un-Comment this line to get test ads.
        s3eAdBuddizSetLogLevel(S3E_ADBUDDIZLOG_INFO); //Optional: Set log level.
        
        s3eAdBuddizInitialize("<your app key."); //3. Add your publisher key.
        
        //Optional: Register one or more call backs.
        s3eAdBuddizRegister(S3E_ADBUDDIZ_CALLBACK_DIDCACHEAD, onAdCached, NULL);
        s3eAdBuddizRegister(S3E_ADBUDDIZ_CALLBACK_DIDSHOWAD, onDidShowAd, NULL);
        s3eAdBuddizRegister(S3E_ADBUDDIZ_CALLBACK_FAILTODISPLAY, onFailToDisplayAd, NULL);
        s3eAdBuddizRegister(S3E_ADBUDDIZ_CALLBACK_DIDCLICK, onDidClickAd, NULL);
        s3eAdBuddizRegister(S3E_ADBUDDIZ_CALLBACK_DIDHIDEAD, onDidHideAd, NULL);
        
        
    }

    // Create main loop
    this->schedule(schedule_selector(GameLayer::update));

    // COCOS2D TIP
    // Create Cocos2D objects here

    return true;
}

void GameLayer::draw()
{
}

void GameLayer::update(float dt)
{
}

