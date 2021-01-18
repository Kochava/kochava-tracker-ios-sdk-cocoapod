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



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVADeeplinks
 
 @brief A controller for working with deeplinks.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVADeeplinks : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



@end



#endif



