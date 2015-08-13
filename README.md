# AdBuddiz
Marmalade Extension for AdBuddiz

Easy integration:

-- In the mkb of your project add the extension.

subprojects
{
    ..\s3eAdBuddiz
}

-- Add "s3eAdBuddiz.h" reference to either .h or .cpp file.

-- Check if extension is available:

  if (s3eAdBuddizAvailable()) { 

-- Inside the check initialize the extension:

s3eAdBuddizInitialize("<your app id.>");   

-- Show ad when needed: s3eAdBuddizShowAd()


Note: Example app has detail of the other options.
