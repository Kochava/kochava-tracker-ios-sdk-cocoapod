//
//  KVAPushNotifications.h
//
//  Created by John Bushnell on 7/22/19.
//  Copyright © 2017 - 2020 Kochava, Inc.  All rights reserved.
//



#ifndef KVAPushNotifications_h
#define KVAPushNotifications_h



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
 @class KVAPushNotifications
 
 @brief A controller for working with Push Notifications.
 
 @author John Bushnell
 
 @copyright 2017 - 2020 Kochava, Inc.
 */
@interface KVAPushNotifications : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



@end



#endif



