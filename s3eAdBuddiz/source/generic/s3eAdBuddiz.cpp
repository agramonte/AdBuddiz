/*
Generic implementation of the s3eAdBuddiz extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eAdBuddiz_internal.h"
s3eResult s3eAdBuddizInit()
{
    //Add any generic initialisation code here
    return s3eAdBuddizInit_platform();
}

void s3eAdBuddizTerminate()
{
    //Add any generic termination code here
    s3eAdBuddizTerminate_platform();
}

s3eResult s3eAdBuddizInitialize(const char* publisherKey)
{
	return s3eAdBuddizInitialize_platform(publisherKey);
}

s3eResult s3eAdBuddizSetTestMode()
{
	return s3eAdBuddizSetTestMode_platform();
}

s3eResult s3eAdBuddizShowAd()
{
	return s3eAdBuddizShowAd_platform();
}

s3eResult s3eAdBuddizSetLogLevel(s3eAdBuddizLogLevel logLevel)
{
	return s3eAdBuddizSetLogLevel_platform(logLevel);
}

void s3eAdBuddizRewardedVideoFetch()
{
	s3eAdBuddizRewardedVideoFetch_platform();
}

void s3eAdBuddizRewardedVideoShowAd()
{
	s3eAdBuddizRewardedVideoShowAd_platform();
}
