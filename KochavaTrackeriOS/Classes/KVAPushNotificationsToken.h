//
//  KVAPushNotificationsToken.h
//  KochavaTracker
//
//  Created by John Bushnell on 7/23/19.
//  Copyright © 2019 - 2021 Kochava, Inc. All rights reserved.
//



#ifndef KVAPushNotificationsToken_h
#define KVAPushNotificationsToken_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAPushNotificationsToken;



#pragma mark - PROTOCOL



@protocol KVAPushNotificationsTokenRegistrar <NSObject>

- (void)registerToken:(nonnull KVAPushNotificationsToken *)token
    NS_SWIFT_NAME(register(token:));

@end



@protocol KVAPushNotificationsTokenRegistrarProvider <NSObject>

@property (strong, nonatomic, nullable, readonly) id<KVAPushNotificationsTokenRegistrar> pushNotifications;

@end



#pragma mark - INTERFACE



/*!
 @class KVAPushNotificationsToken
 
 @brief A push notifications token.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVAPushNotificationsToken : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - CLASS GENERAL



/*!
 @method + registerWithData:
 
 @brief A method which registers a device token.
 
 @param deviceTokenData The device token as provided in NSData.
 */
+ (void)registerWithData:(nonnull NSData *)deviceTokenData
    NS_SWIFT_NAME(register(withData:));



/*!
 @method + registerWithDataHexString:
 
 @brief A method which registers a device token.
 
 @param deviceTokenDataHexString The device token as provided as a data hex string.
 */
+ (void)registerWithDataHexString:(nonnull NSString *)deviceTokenDataHexString
    NS_SWIFT_NAME(register(withDataHexString:));



/*!
 @method + registerWithData:registrarArray:
 
 @brief A method which adds a device token.
 
 @param tokenData The device token as provided in NSData.
 
 @param registrarArray An array of KVAPushNotificationsTokenRegistrarProvider to which to add the token.
 */
+ (void)registerWithData:
    (nonnull NSData *)tokenData
    registrarArray: (nullable NSArray<KVAPushNotificationsTokenRegistrarProvider> *)registrarArray
    NS_SWIFT_NAME(register(withData:registrarArray:));



/*!
 @method + registerWithDataHexString:registrarArray:
 
 @brief A method which adds a device token.
 
 @param deviceTokenDataHexString The device token as provided as a data hex string.
 
 @param registrarArray An array of KVAPushNotificationsTokenRegistrarProvider to which to add the token.
 */
+ (void)registerWithDataHexString:
    (nonnull NSString *)deviceTokenDataHexString
    registrarArray: (nullable NSArray<KVAPushNotificationsTokenRegistrarProvider> *)registrarArray
    NS_SWIFT_NAME(register(withDataHexString:registrarArray:));



#pragma mark - PROPERTIES



/*!
 @property data
 
 @brief The token data as provided by the operating system.
 */
@property (strong, nonatomic, nullable, readonly) NSData *data;



/*!
 @property providedDate
 
 @brief The date that the token was provided by the operating system.
 */
@property (strong, nonatomic, nullable, readonly) NSDate *providedDate;



@end



#endif



