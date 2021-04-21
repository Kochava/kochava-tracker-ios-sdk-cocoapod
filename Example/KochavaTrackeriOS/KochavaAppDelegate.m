//
//  KochavaAppDelegate.m
//  KochavaTrackeriOS
//
//  Created by John Bushnell on 01/11/2017.
//  Copyright (c) 2017 - 2021 Kochava. All rights reserved.
//



#import "KochavaAppDelegate.h"

#import "KochavaTracker.h"



@interface KochavaAppDelegate()
    
@end



@implementation KochavaAppDelegate
    
    
    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // KVALog.shared.level
    // ⓘ Set to trace.  This will result in the KVACoreProduct being registered, and this will be prefaced by any other known modules which are included.  This will be printed to the log where they can be inspected.
    KVALog.shared.level = KVALogLevel.trace;

    // KVATracker.shared
    // ⓘ Start.  Note that unless you were to change the passed app guid to a real Kochava app guid that issues will be printed in the log, as the supplied app guid here is not real.
    [KVATracker.shared startWithAppGUIDString:@"_YOUR_KOCHAVA_APP_GUID_"];
    
    return YES;
}
    
    
    
@end



