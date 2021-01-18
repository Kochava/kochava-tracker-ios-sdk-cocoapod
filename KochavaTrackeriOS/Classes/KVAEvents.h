//
//  KVAEvents.h
//  KochavaTracker
//
//  Created by John Bushnell on 7/6/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEvents_h
#define KVAEvents_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAEventSender.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAEvents
 
 @brief A controller for working with events.
 
 @author John Bushnell
 
 @copyright 2016 - 2021 Kochava, Inc.
 */
@interface KVAEvents : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAEventSender, KVAFromObjectProtocol>



@end



#endif



