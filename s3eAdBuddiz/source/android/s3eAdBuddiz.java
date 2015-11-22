/*
java implementation of the s3eAdBuddiz extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.purplebrain.adbuddiz.sdk.AdBuddiz;
import com.purplebrain.adbuddiz.sdk.AdBuddizDelegate;
import com.purplebrain.adbuddiz.sdk.AdBuddizError;
import com.purplebrain.adbuddiz.sdk.AdBuddizLogLevel;
import com.purplebrain.adbuddiz.sdk.AdBuddizRewardedVideoDelegate;
import com.purplebrain.adbuddiz.sdk.AdBuddizRewardedVideoError;



class s3eAdBuddiz implements AdBuddizDelegate, AdBuddizRewardedVideoDelegate
{
    
    public final static int S3E_ADBUDDIZLOG_INFO = 0;
    public final static int S3E_ADBUDDIZLOG_ERROR = 1;
    public final static int S3E_ADBUDDIZLOG_SILENT = 2;
    
    private int logType = 2;
    private boolean testMode = false;
    
    public int s3eAdBuddizInitialize(String publisherKey)
    {
		AdBuddiz.setPublisherKey(publisherKey);
        
        if(testMode == true){
            AdBuddiz.setTestModeActive();
        }
        
        if (logType == S3E_ADBUDDIZLOG_INFO){
            AdBuddiz.setLogLevel(AdBuddizLogLevel.Info);
        }
        
        if (logType == S3E_ADBUDDIZLOG_ERROR){
            AdBuddiz.setLogLevel(AdBuddizLogLevel.Error);
        }
        
        if (logType == S3E_ADBUDDIZLOG_SILENT){
            AdBuddiz.setLogLevel(AdBuddizLogLevel.Silent);
        }
        
        
        AdBuddiz.cacheAds(LoaderActivity.m_Activity);
        AdBuddiz.setDelegate(this);

        return 0;
    }
    
    public int s3eAdBuddizSetTestMode()
    {
        testMode = true;
        
        return 0;
    }
    
    public int s3eAdBuddizShowAd()
    {
        if (AdBuddiz.isReadyToShowAd(LoaderActivity.m_Activity)) {
            AdBuddiz.showAd(LoaderActivity.m_Activity);
            return 0;
        }
        
        return 1;
        
    }
    
    public int s3eAdBuddizSetLogLevel(int logLevel)
    {
        logType = logLevel;
        return 0;
    }

    public void s3eAdBuddizRewardedVideoFetch()
    {
        AdBuddiz.RewardedVideo.setDelegate(this);
        AdBuddiz.RewardedVideo.fetch(LoaderActivity.m_Activity);
    }
    public void s3eAdBuddizRewardedVideoShowAd()
    {
        AdBuddiz.RewardedVideo.show(LoaderActivity.m_Activity);
        
    }

    
    @Override
    public void didCacheAd(){
        native_onDidCacheAdCallback();
    }
    
    @Override
    public void didShowAd(){
        native_onDidShowAdCallback();
    }
    
    @Override
    public void didClick(){
        native_onDidClickCallback();
    }
    
    @Override
    public void didHideAd(){
        native_onDidHideAdCallback();
    }
    
    
	
	@Override // delegate call
	public void didFailToShowAd(AdBuddizError cause) {
		int code = 0;
		switch(cause)
		{
			case UNSUPPORTED_ANDROID_SDK:
				code = 1;
				break;
		    case MISSING_INTERNET_PERMISSION_IN_MANIFEST:
				code = 3;
				break;
		    case MISSING_ADBUDDIZ_ACTIVITY_IN_MANIFEST:
				code = 5;
				break;
		    case CONFIG_NOT_READY:
				code = 6;
				break;
		    case PLACEMENT_BLOCKED:
				code = 8;
				break;
		    case NO_NETWORK_AVAILABLE:
				code = 10;
				break;
		    case NO_MORE_AVAILABLE_CACHED_ADS:
				code = 11;
				break;
		    case NO_MORE_AVAILABLE_ADS:
				code = 12;
				break;
            default:
                code = 14;
                break;
		}
        
		native_onFailToDisplayCallback(code);
	}
    
    //Video Reward
    @Override
    public void didComplete(){
        native_onRewardedCompleteCallback();
    }
    
    @Override
    public void didFetch(){
        native_onReawardedFetchedCallback();
    }
    
    @Override
    public void didFail(AdBuddizRewardedVideoError error){
        native_onRewardedFailedCallback();
    }
    
    @Override
    public void didNotComplete(){
        native_onRewardedNotCompleteCallback();
        
    }
    
    
    
    ////////////////////////////////////////////////////////////////
    // Native interface
	private static native void native_onFailToDisplayCallback(int cause);
    private static native void native_onDidCacheAdCallback();
    private static native void native_onDidShowAdCallback();
    private static native void native_onDidClickCallback();
    private static native void native_onDidHideAdCallback();
    private static native void native_onRewardedCompleteCallback();
    private static native void native_onReawardedFetchedCallback();
    private static native void native_onRewardedFailedCallback();
    private static native void native_onRewardedNotCompleteCallback();
    ////////////////////////////////////////////////////////////////
}

