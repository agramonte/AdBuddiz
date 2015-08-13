/*
 * android-specific implementation of the s3eAdBuddiz extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eAdBuddiz_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"



static jobject g_Obj;
static jmethodID g_s3eAdBuddizInitialize;
static jmethodID g_s3eAdBuddizSetTestMode;
static jmethodID g_s3eAdBuddizShowAd;
static jmethodID g_s3eAdBuddizSetLogLevel;

void native_onDidCacheAdCallback(JNIEnv * env, jobject obj)
{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH,S3E_ADBUDDIZ_CALLBACK_DIDCACHEAD);
    
}

void native_onFailToDisplayCallback(JNIEnv* env, jobject obj, jint cause)
{
    int c = cause;
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_FAILTODISPLAY, &c, sizeof(int));
}

void native_onDidHideAdCallback(JNIEnv *evn, jobject obj)
{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDHIDEAD);
}

void native_onDidClickCallback(JNIEnv *evn, jobject obj)
{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDCLICK);
}

void native_onDidShowAdCallback(JNIEnv * env, jobject obj)
{
    s3eEdkCallbacksEnqueue(S3E_EXT_ADBUDDIZ_HASH, S3E_ADBUDDIZ_CALLBACK_DIDSHOWAD);
}

s3eResult s3eAdBuddizInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;
    
    const JNINativeMethod nativeMethodDefs[] = {
        { "native_onDidHideAdCallback", "()V", (void *)&native_onDidHideAdCallback },
        { "native_onDidClickCallback", "()V", (void *)&native_onDidClickCallback },
        { "native_onDidShowAdCallback", "()V", (void *)&native_onDidShowAdCallback },
        { "native_onDidCacheAdCallback", "()V", (void *)&native_onDidCacheAdCallback },
        { "native_onFailToDisplayCallback", "(I)V", (void *)&native_onFailToDisplayCallback },
    };

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eAdBuddiz");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eAdBuddizInitialize = env->GetMethodID(cls, "s3eAdBuddizInitialize", "(Ljava/lang/String;)I");
    if (!g_s3eAdBuddizInitialize)
        goto fail;

    g_s3eAdBuddizSetTestMode = env->GetMethodID(cls, "s3eAdBuddizSetTestMode", "()I");
    if (!g_s3eAdBuddizSetTestMode)
        goto fail;

    g_s3eAdBuddizShowAd = env->GetMethodID(cls, "s3eAdBuddizShowAd", "()I");
    if (!g_s3eAdBuddizShowAd)
        goto fail;

    g_s3eAdBuddizSetLogLevel = env->GetMethodID(cls, "s3eAdBuddizSetLogLevel", "(I)I");
    if (!g_s3eAdBuddizSetLogLevel)
        goto fail;

    if(env->RegisterNatives(cls, nativeMethodDefs, sizeof(nativeMethodDefs)/sizeof(nativeMethodDefs[0])))
        goto fail;
    
    
    IwTrace(ADBUDDIZ, ("ADBUDDIZ init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eAdBuddiz, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void s3eAdBuddizTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

s3eResult s3eAdBuddizInitialize_platform(const char* publisherKey)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring publisherKey_jstr = env->NewStringUTF(publisherKey);
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eAdBuddizInitialize, publisherKey_jstr);
}

s3eResult s3eAdBuddizSetTestMode_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eAdBuddizSetTestMode);
}

s3eResult s3eAdBuddizShowAd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eAdBuddizShowAd);
}

s3eResult s3eAdBuddizSetLogLevel_platform(s3eAdBuddizLogLevel logLevel)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_s3eAdBuddizSetLogLevel, logLevel);
}






