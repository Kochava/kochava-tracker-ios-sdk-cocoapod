//
//  KVAEventSender.h
//  KochavaCore
//
//  Created by John Bushnell on 4/17/19.
//  Copyright © 2019 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEventSender_h
#define KVAEventSender_h



#pragma mark - CLASS



@class KVAEvent;



#pragma mark - PROTOCOL



@protocol KVAEventSender



/*!
 @method - sendEvent:
 
 @brief A method to queue an event with standardized parameters to be sent to the server.
 
 @param event A KVAEvent configured with the values you want to associate with the event.
 */
- (void)sendEvent:(nonnull KVAEvent *)event
    NS_SWIFT_NAME(send(event:));



@end



@protocol KVAEventSenderProvider <NSObject>



/*!
 @property events

 @brief A property which conforms to protocol KVAEventSender.
 */
@property (strong, nonatomic, nonnull, readonly) id<KVAEventSender> events;



@end



#endif



