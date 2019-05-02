//
//  KVASendEventFuncProvider.h
//  KochavaCore
//
//  Created by John Bushnell on 4/17/19.
//  Copyright © 2019 Kochava, Inc.  All rights reserved.
//



#ifndef KVASendEventFuncProvider_h
#define KVASendEventFuncProvider_h



#pragma mark - CLASS



@class KochavaEvent;



#pragma mark - PROTOCOL



@protocol KVASendEventFuncProvider



/*!
 @method - sendEvent:
 
 @brief A method to queue an event with standardized parameters to be sent to the server.
 
 @param event A KochavaEvent configured with the values you want to associate with the event.
 */
- (void)sendEvent:(nonnull KochavaEvent *)event;



@end



#endif



