//
//  KVAPrivacyProfile.h
//  KochavaTracker
//
//  Created by John Bushnell on 12/10/20.
//  Copyright © 2020 - 2021 Kochava, Inc. All rights reserved.
//



#ifndef KVAPrivacyProfile_h
#define KVAPrivacyProfile_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAPrivacyProfile;



#pragma mark - PROTOCOL



@protocol KVAPrivacyProfileRegistrar <NSObject>

- (void)registerProfile:(nonnull KVAPrivacyProfile *)privacyProfile
    NS_SWIFT_NAME(register(profile:));

@end



@protocol KVAPrivacyProfileRegistrarProvider <NSObject>

@property (strong, nonatomic, nullable, readonly) id<KVAPrivacyProfileRegistrar> privacy;

@end



#pragma mark - INTERFACE



/*!
 @class KVAPrivacyProfile
 
 @brief A profile describing how information should be redacted for privacy.
 
 @author John Bushnell
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAPrivacyProfile : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - CLASS GENERAL



/*!
 @method + registerWithNameString:payloadKeyStringArray:
 
 @brief A method which registers a privacy profile.
 
 @param nameString The name of the privacy profile.
 
 @param payloadKeyStringArray An array of payload keys (datapoint identifiers).
 */
+ (void)registerWithNameString:
    (nonnull NSString *)nameString
    payloadKeyStringArray: (nullable NSArray<NSString *> *)payloadKeyStringArray
    NS_SWIFT_NAME(register(withNameString:payloadKeyStringArray:));



/*!
 @method + registerWithNameString:payloadKeyStringArray:registrarArray:
 
 @brief A method which registers a privacy profile.
 
 @param nameString The name of the privacy profile.
 
 @param payloadKeyStringArray An array of payload keys (datapoint identifiers).

 @param registrarArray An array of KVAPrivacyProfileRegistrarProvider to which to register the privacy profile.
 */
+ (void)registerWithNameString:
    (nonnull NSString *)nameString
    payloadKeyStringArray: (nullable NSArray<NSString *> *)payloadKeyStringArray
    registrarArray: (nullable NSArray<KVAPrivacyProfileRegistrarProvider> *)registrarArray
    NS_SWIFT_NAME(register(withNameString:payloadKeyStringArray:registrarArray:));



#pragma mark - PROPERTIES



/*!
 @property nameString
 
 @brief A unique name string.
 */
@property (strong, nonatomic, nullable, readonly) NSString *nameString;



/*!
 @property payloadKeyStringArray
 
 @brief An array of payload keys (datapoint identifiers).
 */
@property (strong, nonatomic, nullable, readonly) NSArray<NSString *> *payloadKeyStringArray;



/*!
 @property payloadIdStringArray
 
 @brief An array of payload identifiers (network transaction types).
 */
@property (strong, nonatomic, nullable, readonly) NSArray<NSString *> *payloadIdStringArray;



@end



#endif



