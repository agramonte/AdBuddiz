#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "CCApplication.h"

class AppDelegate : private cocos2d::CCApplication
{
public:
	AppDelegate();
	virtual ~AppDelegate();

    /**
    @brief	Implement CCDirector and CCScene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

    /**
    @brief  The function is used to recalculate the CC projection matrix from the Marmalade display size and orientation
    @param  angle	orientation of display
    @param  w		Width of display is output to this variable
    @param  h		Hidth of display is output to this variable
    */
	void UpdateProjection(float angle, float& w, float& h);

    

};

#endif // _APP_DELEGATE_H_

