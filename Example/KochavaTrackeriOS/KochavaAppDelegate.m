//
//  KochavaAppDelegate.m
//  KochavaTrackeriOS
//
//  Created by John Bushnell on 01/11/2017.
//  Copyright (c) 2017 Kochava. All rights reserved.
//



#import "KochavaAppDelegate.h"

#import "KochavaTracker.h"



@interface KochavaAppDelegate()
    
@end



@implementation KochavaAppDelegate
    
    
    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    KVALog.shared.level = KVALogLevel.trace;
    
    NSLog(@"KVACoreProduct.shared = %@", [KVACoreProduct.shared kva_asForContextObjectWithContext:KVAContext.log]);

    [KVATracker.shared startWithAppGUIDString:@"_YOUR_KOCHAVA_APP_GUID_"];
    
    return YES;
}
    
    
    
@end



