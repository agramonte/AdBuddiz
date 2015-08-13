#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "GameLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
	pDirector->setProjection(kCCDirectorProjection2D);

    // Set projection
    float w, h;
    float angle = s3eSurfaceGetInt(S3E_SURFACE_DEVICE_BLIT_DIRECTION) * 90.0f;
    UpdateProjection(angle, w, h);

	// Set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

    // Create a scene
    CCScene *pScene = GameLayer::scene();

    // Run
    pDirector->runWithScene(pScene);

	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	CCDirector::sharedDirector()->pause();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
	CCDirector::sharedDirector()->resume();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::UpdateProjection(float angle, float& w, float& h)
{
    if (IwGLGetInt(IW_GL_VIRTUAL_WIDTH) >= 0)
    {
        w = (float)IwGLGetInt(IW_GL_VIRTUAL_WIDTH);
        h = (float)IwGLGetInt(IW_GL_VIRTUAL_HEIGHT);
    }
    else
    {
        w = (float)s3eSurfaceGetInt(S3E_SURFACE_WIDTH);
        h = (float)s3eSurfaceGetInt(S3E_SURFACE_HEIGHT);
    }
    if ((angle == 90.0f) || (angle == 270.0f))
    {
        float oh = h;
        h = w;
        w = oh;
    }
    CCEGLView::sharedOpenGLView()->setFrameSize(w, h);
    CCEGLView::sharedOpenGLView()->setViewPortInPoints(0.0f, 0.0f, w, h);

    kmGLMatrixMode(KM_GL_PROJECTION);
    kmGLLoadIdentity();

    // Rotate to achieve landscape orientation
    kmGLRotatef(-(float)angle, 0, 0, 1);
    kmMat4 orthoMatrix;
    kmMat4OrthographicProjection(&orthoMatrix, 0, w, 0, h, -1024, 1024 );
    kmGLMultMatrix(&orthoMatrix);
    kmGLMatrixMode(KM_GL_MODELVIEW);
    kmGLLoadIdentity();
}
