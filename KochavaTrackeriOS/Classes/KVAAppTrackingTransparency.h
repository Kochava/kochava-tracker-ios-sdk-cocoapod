//
//  KVAAppTrackingTransparency.h
//  KochavaTracker
//
//  Created by John Bushnell on 7/13/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAAppTrackingTransparency_h
#define KVAAppTrackingTransparency_h



#pragma mark - IMPORT



#pragma mark System
#if !TARGET_OS_WATCH && !TARGET_OS_MACCATALYST && !TARGET_OS_OSX
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif

#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAAppTrackingTransparency
 
 @brief This class provides a high-level interface for Apple's app tracking transparency framework.
 
 @author John Bushnell
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAAppTrackingTransparency : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



#pragma mark - PARAMETERS



/*!
 @property authorizationStatusString
 
 @brief The authorization status expressed as an NSString.
 
 @discussion This is optional and will be nil until a status is known.  For this reason this can be checked as a means of determining if a status has been determined.  Current possible values:  "authorized", "denied", "notDetermined", "restricted", "unknown".
 */
@property (strong, nonatomic, nullable, readonly) NSString *authorizationStatusString;



/*!
 @property authorizationStatusWaitTimeInterval
 
 @brief A time interval to wait for the request for tracking authorization before proceeding to send the install.
 
 @discussion Default 30.0.  Subject to server-based override.  This provides time to wait to obtain the authorization necessary to collect the IDFA.
 */
@property (readwrite) NSTimeInterval authorizationStatusWaitTimeInterval;



/*!
 @property autoRequestTrackingAuthorizationBool
 
 @brief A boolean which indicates if the instance should automatically request tracking authorization.
 
 @discussion Default YES.  Subject to server-based override.  Also subject to enabledBool.  See enabledBool.
 */
@property (readwrite) BOOL autoRequestTrackingAuthorizationBool;



/*!
 @property enabledBool
 
 @brief A boolean indicating if the instance of KVAAppTrackingTransparency is enabled.
 
 @discussion Default NO.  Subject to server-based override.
 */
@property (readwrite) BOOL enabledBool;



@end



#endif



