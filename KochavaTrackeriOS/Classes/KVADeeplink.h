//
//  KVADeeplink.h
//  KochavaTracker
//
//  Created by John Bushnell on 10/14/19.
//  Copyright © 2019 - 2020 Kochava, Inc. All rights reserved.
//



#ifndef KVADeeplink_h
#define KVADeeplink_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#if TARGET_OS_TV
#if TARGET_OS_SIMULATOR
#import <KochavaCoreTVOSSimulator/KochavaCoreTVOSSimulator.h>
#else
#import <KochavaCoreTVOSDevice/KochavaCoreTVOSDevice.h>
#endif
#else
#if TARGET_OS_SIMULATOR
#import <KochavaCoreiOSSimulator/KochavaCoreiOSSimulator.h>
#else
#import <KochavaCoreiOSDevice/KochavaCoreiOSDevice.h>
#endif
#endif
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVADeeplink;



#pragma mark - TYPEDEF



/*!
 @typedef KVADeeplinkProcessCompletionHandler
 
 @brief A block to be called when processing is complete.
 */
typedef void (^ KVADeeplinkProcessCompletionHandler) (KVADeeplink * _Nonnull deeplink);



#pragma mark - PROTOCOL



@protocol KVADeeplinksProcessor <NSObject>



/*!
 @method - processDeeplink:
 
 @brief Processes a KVADeeplink.
 
 @param deeplink An instance of KVADeeplink.
 
 @param completionHandler A completion handler to call when processing is complete.
 */
- (void)processDeeplink:(nonnull KVADeeplink *)deeplink timeoutTimeInterval:(NSTimeInterval)timeoutTimeInterval completionHandler:(nullable KVADeeplinkProcessCompletionHandler)completionHandler NS_SWIFT_NAME(process(deeplink:timeoutTimeInterval:completionHandler:));



@end



@protocol KVADeeplinksProcessorPropertyProvider <NSObject>



/*!
 @property deeplinks
 
 @brief An instance which conforms to protocol KVADeeplinksProcessor.
 */
@property (strong, nonatomic, nullable, readonly) id<KVADeeplinksProcessor> deeplinks;



@end



#pragma mark - INTERFACE



/*!
 @class KVADeeplink
 
 @brief A deep link.
 
 @author John Bushnell
 
 @copyright 2017 - 2020 Kochava, Inc.
 */
@interface KVADeeplink : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - PROPERTIES



/*!
 @property destinationString
 
 @brief The destination for the deeplink.
 */
@property (strong, nonatomic, nullable, readonly) NSString *destinationString;



/*!
 @property rawDictionary
 
 @brief A dictionary containing raw information about the deeplink.
 */
@property (strong, nonatomic, nullable, readwrite) NSDictionary *rawDictionary;



#pragma mark - CLASS GENERAL



/*!
@method + processWithURL:completionHandler:

@brief A method which processes a deep link.

@param url The deep link url as provided.

@param completionHandler A block to be called when processing is complete.
*/
+ (void)processWithURL:(nullable NSURL *)url completionHandler:(nullable KVADeeplinkProcessCompletionHandler)completionHandler NS_SWIFT_NAME(process(withURL:completionHandler:));



/*!
 @method + processWithURL:timeoutTimeInterval:completionHandler:
 
 @brief A method which processes a deep link.
 
 @param url The deep link url as provided.
 
 @param timeoutTimeInterval A time interval after which to timeout and return whatever result we have.
 
 @param completionHandler A block to be called when processing is complete.
 */
+ (void)processWithURL:(nullable NSURL *)url timeoutTimeInterval:(NSTimeInterval)timeoutTimeInterval completionHandler:(nullable KVADeeplinkProcessCompletionHandler)completionHandler NS_SWIFT_NAME(process(withURL:timeoutTimeInterval:completionHandler:));




/*!
@method + processWithURL:deeplinksProcessorPropertyProvider:completionHandler:

@brief A method which processes a deep link.

@param url The deep link url as provided.

@param deeplinksProcessorPropertyProvider An array of KVADeeplinksProcessorPropertyProvider to which to add the token.

@param completionHandler A block to be called when processing is complete.
*/
+ (void)processWithURL:(nullable NSURL *)url deeplinksProcessorPropertyProvider:(nullable id<KVADeeplinksProcessorPropertyProvider>)deeplinksProcessorPropertyProvider completionHandler:(nullable KVADeeplinkProcessCompletionHandler)completionHandler NS_SWIFT_NAME(process(withURL:deeplinksProcessorPropertyProvider:completionHandler:));



/*!
 @method + processWithURL:timeoutTimeInterval:deeplinksProcessorPropertyProvider:completionHandler:
 
 @brief A method which processes a deep link.
 
 @param url The deep link url as provided.
 
 @param timeoutTimeInterval A time interval after which to timeout and return whatever result we have.

 @param deeplinksProcessorPropertyProvider An array of KVADeeplinksProcessorPropertyProvider to which to add the token.
 
 @param completionHandler A block to be called when processing is complete.
 */
+ (void)processWithURL:(nullable NSURL *)url timeoutTimeInterval:(NSTimeInterval)timeoutTimeInterval deeplinksProcessorPropertyProvider:(nullable id<KVADeeplinksProcessorPropertyProvider>)deeplinksProcessorPropertyProvider completionHandler:(nullable KVADeeplinkProcessCompletionHandler)completionHandler NS_SWIFT_NAME(process(withURL:timeoutTimeInterval:deeplinksProcessorPropertyProvider:completionHandler:));



@end



#endif



