/*
 * Internal header for the s3eAdBuddiz extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EADBUDDIZ_INTERNAL_H
#define S3EADBUDDIZ_INTERNAL_H

#include "s3eTypes.h"
#include "s3eAdBuddiz.h"
#include "s3eAdBuddiz_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eAdBuddizInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eAdBuddizInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eAdBuddizTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eAdBuddizTerminate_platform();
s3eResult s3eAdBuddizInitialize_platform(const char* publisherKey);

s3eResult s3eAdBuddizSetTestMode_platform();

s3eResult s3eAdBuddizShowAd_platform();

s3eResult s3eAdBuddizSetLogLevel_platform(s3eAdBuddizLogLevel logLevel);


#endif /* !S3EADBUDDIZ_INTERNAL_H */