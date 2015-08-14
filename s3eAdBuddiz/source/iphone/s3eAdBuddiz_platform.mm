/*
 * iphone-specific implementation of the s3eAdBuddiz extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#import <Foundation/Foundation.h>
#import <AdBuddiz/AdBuddiz.h>
#import <UIKit/UIKit.h>

#include "s3eAdBuddiz_internal.h"
#include "s3eEdk.h"
#include "s3eEdk_iphone.h"
#include <s3eTypes.h>

BOOL setTestMode = false;
int setLogLevelTo = 2;

@interface s3eAdBuddizDelegate: NSObject<AdBuddizDelegate>
@end

@implementation s3eAdBuddizDelegate


- (void)didCacheAd{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH,S3E_ADBUDDIZ_CALLBACK_DIDCACHEAD);
    
}// When an Ad has been downloaded and is ready to show
- (void)didShowAd{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDSHOWAD);
    
}// When an Ad has been displayed to user

- (void)didFailToShowAd:(AdBuddizError) error{
    int c = error;
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_FAILTODISPLAY, &c, sizeof(int));
    
}// When no Ad was displayed
- (void)didClick{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDCLICK);
    
}// When an Ad was clicked
- (void)didHideAd{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDHIDEAD);
    
}// When an Ad was hidden

@end

s3eResult s3eAdBuddizInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eAdBuddizTerminate_platform()
{ 
}

s3eResult s3eAdBuddizInitialize_platform(const char* publisherKey)
{
    NSString *key;
    key = [[NSString alloc] initWithUTF8String:publisherKey];

    [AdBuddiz setPublisherKey:key];
    
    [AdBuddiz setDelegate:[s3eAdBuddizDelegate alloc]];

    
    if (setLogLevelTo == 0){
        [AdBuddiz setLogLevel:ABLogLevelInfo];
    }else if (setLogLevelTo == 1){
        [AdBuddiz setLogLevel:ABLogLevelError];
    } else {
        [AdBuddiz setLogLevel:ABLogLevelSilent];
    }
    
    if (setTestMode) {
        [AdBuddiz setTestModeActive];
    }
    
    [AdBuddiz cacheAds];
    return S3E_RESULT_SUCCESS;
}

s3eResult s3eAdBuddizSetTestMode_platform()
{
    setTestMode = true;
    return S3E_RESULT_SUCCESS;
}

s3eResult s3eAdBuddizShowAd_platform()
{
    if ([AdBuddiz isReadyToShowAd]) {
        [AdBuddiz showAd];
        return S3E_RESULT_SUCCESS;
    } else {
        return S3E_RESULT_ERROR;
    }
    
}

s3eResult s3eAdBuddizSetLogLevel_platform(s3eAdBuddizLogLevel logLevel)
{
    setLogLevelTo = logLevel;
    return S3E_RESULT_SUCCESS;
}



