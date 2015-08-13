/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eAdBuddiz_autodefs.h"
#include "s3eEdk.h"
#include "s3eAdBuddiz.h"
//Declarations of Init and Term functions
extern s3eResult s3eAdBuddizInit();
extern void s3eAdBuddizTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static s3eResult s3eAdBuddizInitialize_wrap(const char* publisherKey)
{
    IwTrace(ADBUDDIZ_VERBOSE, ("calling s3eAdBuddiz func on main thread: s3eAdBuddizInitialize"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eAdBuddizInitialize, 1, publisherKey);
}

static s3eResult s3eAdBuddizSetTestMode_wrap()
{
    IwTrace(ADBUDDIZ_VERBOSE, ("calling s3eAdBuddiz func on main thread: s3eAdBuddizSetTestMode"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eAdBuddizSetTestMode, 0);
}

static s3eResult s3eAdBuddizShowAd_wrap()
{
    IwTrace(ADBUDDIZ_VERBOSE, ("calling s3eAdBuddiz func on main thread: s3eAdBuddizShowAd"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eAdBuddizShowAd, 0);
}

static s3eResult s3eAdBuddizSetLogLevel_wrap(s3eAdBuddizLogLevel logLevel)
{
    IwTrace(ADBUDDIZ_VERBOSE, ("calling s3eAdBuddiz func on main thread: s3eAdBuddizSetLogLevel"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eAdBuddizSetLogLevel, 1, logLevel);
}

#define s3eAdBuddizInitialize s3eAdBuddizInitialize_wrap

#define s3eAdBuddizSetTestMode s3eAdBuddizSetTestMode_wrap

#define s3eAdBuddizShowAd s3eAdBuddizShowAd_wrap

#define s3eAdBuddizSetLogLevel s3eAdBuddizSetLogLevel_wrap


#endif

s3eResult s3eAdBuddizRegister(s3eAdBuddizCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult s3eAdBuddizUnRegister(s3eAdBuddizCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_MAX, cbid, fn);
}

void s3eAdBuddizRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[6];
    funcPtrs[0] = (void*)s3eAdBuddizRegister;
    funcPtrs[1] = (void*)s3eAdBuddizUnRegister;
    funcPtrs[2] = (void*)s3eAdBuddizInitialize;
    funcPtrs[3] = (void*)s3eAdBuddizSetTestMode;
    funcPtrs[4] = (void*)s3eAdBuddizShowAd;
    funcPtrs[5] = (void*)s3eAdBuddizSetLogLevel;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[6] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("s3eAdBuddiz", funcPtrs, sizeof(funcPtrs), flags, s3eAdBuddizInit, s3eAdBuddizTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eAdBuddizStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eAdBuddizRegisterExt;
    return 0;
}

int g_s3eAdBuddizVal = s3eAdBuddizStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eAdBuddizRegisterExt();
}
#endif

#endif