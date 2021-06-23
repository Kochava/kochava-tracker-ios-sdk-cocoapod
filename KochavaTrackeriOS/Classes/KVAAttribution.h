//
//  KVAAttribution.h
//  KochavaTracker
//
//  Created by John Bushnell on 5/18/20.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAAttribution_h
#define KVAAttribution_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAAttribution;
@class KVAAttributionResult;



#pragma mark - INTERFACE



/*!
 @class KVAAttribution
 
 @brief A controller for working with Apple Search Ads.
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVAAttribution : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - PARAMETERS



/*!
 @property retrieveResultBool
 
 @brief A boolean indicating if an attribution result should be retrieved.
 
 @discussion This boolean does not need to be set if you are using func retrieveResult(withCompletionHandler:).  It needs to be set if you intend to query var result perodically with the expectation of seeing a retrieved result.
 */
@property (readwrite) BOOL retrieveResultBool;



#pragma mark - PROPERTIES
#pragma mark public var result



/*!
 @property result
 
 @brief The current Apple Search Ads result.
 
 @discussion This is backed by an asychronous gathering process.  When accessed this property will contain the currently known value.  If this value should be gathered or otherwise refreshed the backing asynchronous gathering process will be initiated.  For asynchronous gathering see resultAdapter.
 */
@property (strong, atomic, nonnull, readonly) KVAAttributionResult *result;



/*!
 @method - retrieveResultWithCompletionHandler:

 @brief Get the attribution result with a completion handler.
 
 @param completionHandler A completion handler to call once the result has been retrieved.
 */
- (void)retrieveResultWithCompletionHandler:(void (^_Nullable)(KVAAttributionResult * _Nonnull attributionResult))completionHandler NS_SWIFT_NAME(retrieveResult(withCompletionHandler:));



@end



#endif



