//
//  KVADeeplinks.h
//  KochavaTracker
//
//  Created by John Bushnell on 10/14/19.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVADeeplinks_h
#define KVADeeplinks_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif

#pragma mark KochavaTracker
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaTracker/KochavaTracker.h>
#else
#import "KVADeeplink.h"  // for KVADeeplinksProcessor
#endif



#pragma mark - INTERFACE



/*!
 @class KVADeeplinks
 
 @brief A controller for working with deeplinks.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVADeeplinks : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVADeeplinksProcessor, KVAFromObjectProtocol>



@end



#endif



