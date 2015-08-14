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

// Depending on your app, replace "TEST_PUBLISHER_KEY" with the right publisher key.
s3eAdBuddizInitialize("TEST_PUBLISHER_KEY");   

-- Show ad when needed

s3eAdBuddizShowAd()

Note: Example app has detail of the other options.
