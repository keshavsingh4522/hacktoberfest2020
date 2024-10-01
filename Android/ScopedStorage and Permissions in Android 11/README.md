**Introduction to Scoped Storage:**
```
Apps that run on Android 11 but target Android 10 (API level 29) can still request the requestLegacyExternalStorage attribute. 
This flag allows apps to temporarily opt out of the changes associated with scoped storage,
such as granting access to different directories and different types of media files.
After you update your app to target Android 11, the system ignores the requestLegacyExternalStorage flag.
```

**Managing Scoped Storage:**


```
Starting in Android 11, apps that use the scoped storage model can access only their own app-specific cache files.

1. Check for free space by invoking the ACTION_MANAGE_STORAGE intent action.
2. If there isn't enough free space on the device, prompt the user to give your app consent to clear all caches. 
To do so, invoke the ACTION_CLEAR_APP_CACHE intent action.
```
