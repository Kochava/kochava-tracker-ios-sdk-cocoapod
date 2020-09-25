//
//  KVAPushNotificationsToken.h
//  KochavaTracker
//
//  Created by John Bushnell on 7/23/19.
//  Copyright © 2019 - 2020 Kochava, Inc. All rights reserved.
//



#ifndef KVAPushNotificationsToken_h
#define KVAPushNotificationsToken_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAPushNotificationsToken;



#pragma mark - PROTOCOLS



@protocol KVAPushNotificationsTokenAdder <NSObject>

- (void)addToken:(nonnull KVAPushNotificationsToken *)token NS_SWIFT_NAME(addToken(_:));

@end



@protocol KVAPushNotificationsTokenRemover <NSObject>

- (void)removeToken:(nullable KVAPushNotificationsToken *)token NS_SWIFT_NAME(removeToken(_:));

@end



@protocol KVAPushNotificationsTokenAdderRemoverProvider <NSObject>

@property (strong, nonatomic, nullable, readonly) id<KVAPushNotificationsTokenAdder, KVAPushNotificationsTokenRemover> pushNotifications;

@end



#pragma mark - INTERFACE



/*!
 @class KVAPushNotificationsToken
 
 @brief A push notifications token.
 
 @author John Bushnell
 
 @copyright 2017 - 2020 Kochava, Inc.
 */
@interface KVAPushNotificationsToken : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - CLASS GENERAL



/*!
 @method + addWithData:
 
 @brief A method which adds a device token.
 
 @param tokenData The device token as provided in NSData.
 */
+ (void)addWithData:(nonnull NSData *)tokenData NS_SWIFT_NAME(add(withData:));



/*!
 @method + addWithData:adderArray:
 
 @brief A method which adds a device token.
 
 @param tokenData The device token as provided in NSData.
 
 @param adderArray An array of KVAPushNotificationsTokenAdderRemoverProvider to which to add the token.
 */
+ (void)addWithData:(nonnull NSData *)tokenData adderArray:(nullable NSArray<KVAPushNotificationsTokenAdderRemoverProvider> *)adderArray NS_SWIFT_NAME(add(withData:adderArray:));



/*!
 @method + remove
 
 @brief A method which removes any assocation for this device with any previously registered device token.
 
 @discussion This is equivalent to calling method removeWithData and passing nil.
 */
+ (void)remove NS_SWIFT_NAME(remove());



/*!
 @method + removeWithData:
 
 @brief A method which removes any assocation for this device with any previously registered device token.
 
 @param tokenData The device token as provided in NSData.
 */
+ (void)removeWithData:(nullable NSData *)tokenData NS_SWIFT_NAME(remove(withData:));



/*!
 @method + removeWithData:removerArray:
 
 @brief A method which removes any assocation for this device with any previously registered device token.
 
 @param tokenData The device token as provided in NSData.
 
 @param removerArray An array of KVAPushNotificationsTokenAdderRemoverProvider from which to remove the token.
 */
+ (void)removeWithData:(nullable NSData *)tokenData removerArray:(nullable NSArray<KVAPushNotificationsTokenAdderRemoverProvider> *)removerArray NS_SWIFT_NAME(remove(withData:removerArray:));



#pragma mark - CONSTRUCTION



/*!
 @method + pushNotificationsTokenWithData:providedDate:
 
 @brief Constructs an instance of class KVAPushNotificationsToken.
 
 @discussion To add or remove a token, see convenience methods add(withData:) and remove(withData:).

 @param data The device token as provided in NSData.

 @param providedDate The date that the token was provided by the operating system.
 */
+ (nullable instancetype)pushNotificationsTokenWithData:(nullable NSData *)data providedDate:(nullable NSDate *)providedDate NS_SWIFT_NAME(init(data:providedDate:));



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



