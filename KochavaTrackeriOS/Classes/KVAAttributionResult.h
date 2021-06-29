//
//  KVAAttributionResult.h
//  KochavaTracker
//
//  Created by John Bushnell on 5/18/20.
//  Copyright © 2017 - 2021 Kochava, Inc. All rights reserved.
//



#ifndef KVAAttributionResult_h
#define KVAAttributionResult_h



#pragma mark - IMPORT



#pragma mark System
#if TARGET_OS_TV
#import <JavaScriptCore/JavaScriptCore.h>
#endif

#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAAttributionResult
 
 @brief The attribution result.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVAAttributionResult : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - GENERAL



/*!
 @property retrievedBool
 
 @brief A boolean indicating if the result was retrieved.
 */
@property (readonly) BOOL retrievedBool;



/*!
 @property attributedBool

 @brief A boolean indicating if the result attributed the install.
 */
@property (readonly) BOOL attributedBool;



/*!
 @property firstInstallBool

 @brief A boolean indicating if the current install is the first install.
 */
@property (readonly) BOOL firstInstallBool;



/*!
 @property rawDictionary
 
 @brief A dictionary containing the raw result information.
 */
@property (strong, nonatomic, nullable, readonly) NSDictionary *rawDictionary;



@end



#endif



