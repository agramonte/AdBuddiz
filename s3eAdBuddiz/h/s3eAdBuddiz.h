/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_ADBUDDIZ_H
#define S3E_EXT_ADBUDDIZ_H

#include <s3eTypes.h>

typedef enum s3eAdBuddizCallback
{
	S3E_ADBUDDIZ_CALLBACK_DIDCACHEAD = 0,
	S3E_ADBUDDIZ_CALLBACK_DIDSHOWAD = 1,
    S3E_ADBUDDIZ_CALLBACK_FAILTODISPLAY = 2,
    S3E_ADBUDDIZ_CALLBACK_DIDCLICK = 3,
    S3E_ADBUDDIZ_CALLBACK_DIDHIDEAD = 4,
	S3E_ADBUDDIZ_CALLBACK_MAX
} s3eAdBuddizCallback;

typedef enum s3eAdBuddizLogLevel
{
	S3E_ADBUDDIZLOG_INFO,
	S3E_ADBUDDIZLOG_ERROR,
	S3E_ADBUDDIZLOG_SILENT
} s3eAdBuddizLogLevel;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the AdBuddiz extension is available.
 */
s3eBool s3eAdBuddizAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eAdBuddizCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eAdBuddizUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eAdBuddizCallback enum.
 */
s3eResult s3eAdBuddizRegister(s3eAdBuddizCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3eAdBuddizCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3eAdBuddizRegister
 */
s3eResult s3eAdBuddizUnRegister(s3eAdBuddizCallback cbid, s3eCallback fn);

s3eResult s3eAdBuddizInitialize(const char* publisherKey);

s3eResult s3eAdBuddizSetTestMode();

s3eResult s3eAdBuddizShowAd();

s3eResult s3eAdBuddizSetLogLevel(s3eAdBuddizLogLevel logLevel);

// \cond HIDDEN_DEFINES
S3E_END_C_DECL
// \endcond

#endif /* !S3E_EXT_ADBUDDIZ_H */