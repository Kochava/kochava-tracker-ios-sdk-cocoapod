//
//  KVAPrivacy.h
//  KochavaTracker
//
//  Created by John Bushnell on 12/10/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAPrivacy_h
#define KVAPrivacy_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAPrivacyProfile;



#pragma mark - INTERFACE



/*!
 @class KVAPrivacy
 
 @brief A controller for working with privacy.
 
 @discussion This class provides an API for working with KVAPrivacyProfiles.
 
 @author John Bushnell
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAPrivacy : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



/*!
 @method - setEnabledBoolForProfileNameString:enabledBool:
 
 @brief Sets a boolean indicating if a specified profile name is enabled.
 
 @param profileNameString The name of a profile.
 
 @param enabledBool A boolean indicating if enabled.
 
 @discussion See method registerProfile.
 */
- (void)setEnabledBoolForProfileNameString:(nonnull NSString *)profileNameString enabledBool:(BOOL)enabledBool NS_SWIFT_NAME(setEnabledBool(forProfileNameString:enabledBool:));



/*!
 @method - registerProfile:
 
 @brief Registers a profile.
 */
- (void)registerProfile:(nonnull KVAPrivacyProfile *)privacyProfile NS_SWIFT_NAME(registerProfile(_:));



@end



#endif



