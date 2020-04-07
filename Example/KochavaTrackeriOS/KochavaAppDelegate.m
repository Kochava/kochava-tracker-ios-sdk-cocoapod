//
//  KochavaAppDelegate.m
//  KochavaTrackeriOS
//
//  Created by John Bushnell on 01/11/2017.
//  Copyright (c) 2017 Kochava. All rights reserved.
//



#import "KochavaAppDelegate.h"

#import "KochavaTracker.h"



@interface KochavaAppDelegate() <KochavaTrackerDelegate>
    
@end



@implementation KochavaAppDelegate
    
    
    
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    NSLog(@"KVACoreProduct.shared = %@", [KVACoreProduct.shared kva_asForContextObjectWithContext:KVAContext.log]);
    NSLog(@"KVATrackerProduct.shared = %@", [KVATrackerProduct.shared kva_asForContextObjectWithContext:KVAContext.log]);

    // trackerParametersDictionary
    NSMutableDictionary *trackerParametersDictionary = [NSMutableDictionary dictionary];
    trackerParametersDictionary[kKVAParamAppGUIDStringKey] = @"_YOUR_KOCHAVA_APP_GUID_";
    
    // KochavaTracker.shared
    [KochavaTracker.shared configureWithParametersDictionary:trackerParametersDictionary delegate:self];
    
    return YES;
}
    
    
    
@end



