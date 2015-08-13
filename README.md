# AdBuddiz
Marmalade Extension for AdBuddiz

Easy integrate
1. In the mkb of your project add the extension.

subprojects
{
    ..\s3eAdBuddiz
}

2. Add "s3eAdBuddiz.h" reference to either .h or .cpp file.

3. Check if extension is available:

  if (s3eAdBuddizAvailable()) { 

4. Inside the check initialize the extension:

s3eAdBuddizInitialize("<your app id.>");   

5. Show ad when needed: s3eAdBuddizShowAd()


Note: Example app has detail of the other options.
