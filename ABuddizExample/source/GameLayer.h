#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "cocos2d.h"

using namespace cocos2d;

class GameLayer : public cocos2d::CCLayer
{
public:
    ~GameLayer();
    
    // Init method
    virtual bool init();

	// Draw method
	virtual void draw();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);

};

#endif // __GAMELAYER_H__

