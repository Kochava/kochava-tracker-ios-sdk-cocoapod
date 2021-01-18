//
//  KVAEventType.h
//  KochavaCore
//
//  Created by John Bushnell on 04/30/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEventType_h
#define KVAEventType_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KVAAsForContextObjectProtocol.h>
#import <KochavaCore/KVAFromObjectProtocol.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAEventType
 
 @brief A class which defines an event type.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAEventType : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - ENUMERATED VALUES



/*!
 @property + addToCart
 
 @brief An event type which signifies that an item was added to a cart.  You may use this in any equivalent circumstance.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAEventType *addToCart;



/*!
 @property + addToWishList
 
 @brief An event type which signifies that an item was added to a wish list.  You may use this in any equivalent circumstance.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAEventType *addToWishList;



/*!
 @property + achievement
 
 @brief An event type which signifies that an achievement was achieved.  You may use this in any equivalent circumstance.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAEventType *achievement;



/*!
 @property + checkoutStart
 
 @brief An event type which signifies that a checkout was started.  You may use this in any equivalent circumstance.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAEventType *checkoutStart;



/*!
 @property + custom
 
 @brief An event type which signifies that a customEventNameString will be supplied.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAEventType *custom;



/*!
 @property + levelComplete
 
 @brief An event type which signifies that a level was completed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *levelComplete;



/*!
 @property + purchase
 
 @brief An event type which signifies that a purchase was completed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *purchase;



/*!
 @property + rating
 
 @brief An event type which signifies that an item was rated.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *rating;



/*!
 @property + registrationComplete
 
 @brief An event type which signifies that a registration was completed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *registrationComplete;



/*!
 @property + search
 
 @brief An event type which signifies that a search was performed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *search;



/*!
 @property + tutorialComplete
 
 @brief An event type which signifies that a tutorial was completed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *tutorialComplete;



/*!
 @property + view
 
 @brief An event type which signifies that an item was viewed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *view;



/*!
 @property + adView
 
 @brief An event type which signifies that an ad was viewed.  You may use this in any equivalent circumstance.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *adView;



/*!
 @property + pushReceived
 
 @brief An event type which signifies that a push notification was received.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *pushReceived;



/*!
 @property + pushOpened
 
 @brief An event type which signifies that a push notification was opened.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *pushOpened;



/*!
 @property + consentGranted
 
 @brief An event type which signifies that consent was granted.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *consentGranted;



/*!
 @property + deeplink
 
 @brief An event type which signifies that there was a deep link.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *deeplink;



/*!
 @property + adClick
 
 @brief An event type which signifies that an ad was clicked.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *adClick;



/*!
 @property + startTrial
 
 @brief An event type which signifies that a trial was started.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *startTrial;



/*!
 @property + subscribe
 
 @brief An event type which signifies that there was a subscription.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAEventType *subscribe;



#pragma mark - PARAMETERS



/*!
 @property nameString
 
 @brief The name.
 
 @discussion Examples:  "Add to Cart", "Add to Wish List", "Achievement", etc.
 */
@property (strong, nonatomic, nonnull) NSString *nameString;



@end



#endif



