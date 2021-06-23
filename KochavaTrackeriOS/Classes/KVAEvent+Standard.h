//
//  KVAEvent+Standard.h
//  KochavaTracker
//
//  Created by John Bushnell on 4/29/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAEvent_Standard_h
#define KVAEvent_Standard_h



#pragma mark - IMPORT



#if TARGET_OS_TV
#import <JavaScriptCore/JavaScriptCore.h>
#endif

#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAEvent.h"
#endif



#pragma mark - PROTOCOL



@protocol KVAEventSenderProvider;
@protocol KVADispatchQueueDelegate;



#if TARGET_OS_TV
@protocol KVAEventStandardJSExport <JSExport>
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString NS_SWIFT_NAME(init(customWithNameString:));
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString infoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(init(customWithNameString:infoDictionary:));
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString infoString:(nullable NSString *)infoString NS_SWIFT_NAME(init(customWithNameString:infoString:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString NS_SWIFT_NAME(sendCustom(withNameString:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:senderArray:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(sendCustom(withNameString:infoDictionary:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoDictionary:(nullable NSDictionary *)infoDictionary senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:infoDictionary:senderArray:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoString:(nullable NSString *)infoString NS_SWIFT_NAME(sendCustom(withNameString:infoString:));
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoString:(nullable NSString *)infoString senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:infoString:senderArray:));
@end
#endif



#pragma mark - INTERFACE



@interface KVAEvent (Standard)
#if TARGET_OS_TV
<
KVAEventStandardJSExport
>
#endif



#pragma mark - CLASS GENERAL



/*!
 @method + sendCustomWithNameString:

 @brief Creates an instance of class KVAEvent which has a nameString, and then sends it.

 @param nameString A string containing the event name.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString NS_SWIFT_NAME(sendCustom(withNameString:));



/*!
 @method + sendCustomWithNameString:sender:
 
 @brief Creates an instance of class KVAEvent which has a nameString, and then sends it.

 @param nameString A string containing the event name.

 @param senderArray Optional.  An array of senders.  These are objects which conform to protocol KVAEventSenderProvider.  If this parameter is not passed the default sender will be used.  The default sender is the shared instance of class KVATracker, which if you are using you may simply your call by using the function of the same name which omits this parameter.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:senderArray:));



/*!
 @method + sendCustomWithNameString:infoDictionary:
 
 @brief Creates an instance of class KVAEvent which has a nameString and an optional infoDictionary, and then sends it.
 
 @param nameString A string containing the event name.
 
 @param infoDictionary A dictionary (single dimensional) containing any number of values with keys.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(sendCustom(withNameString:infoDictionary:));



/*!
 @method + sendCustomWithNameString:infoDictionary:sender:
 
 @brief Creates an instance of class KVAEvent which has a nameString and an optional infoDictionary, and then sends it.
 
 @param nameString A string containing the event name.
 
 @param infoDictionary A dictionary (single dimensional) containing any number of values with keys.
 
 @param senderArray Optional.  An array of senders.  These are objects which conform to protocol KVAEventSenderProvider.  If this parameter is not passed the default sender will be used.  The default sender is the shared instance of class KVATracker, which if you are using you may simply your call by using the function of the same name which omits this parameter.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoDictionary:(nullable NSDictionary *)infoDictionary senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:infoDictionary:senderArray:));



/*!
 @method + sendCustomWithNameString:infoString:
 
 @brief Creates an instance of class KVAEvent which has a nameString and an optional infoString, and then sends it.
 
 @param nameString A string containing event name.
 
 @param infoString An info string.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoString:(nullable NSString *)infoString NS_SWIFT_NAME(sendCustom(withNameString:infoString:));



/*!
 @method + sendCustomWithNameString:infoString:sender:
 
 @brief Creates an instance of class KVAEvent which has a nameString and an optional infoString, and then sends it.
 
 @param nameString A string containing event name.
 
 @param infoString A custom string.  It may be an unnested (single dimensional) dictionary converted to a JSON formatted string.
 
 @param senderArray Optional.  An array of senders.  These are objects which conform to protocol KVAEventSenderProvider.  If this parameter is not passed the default sender will be used.  The default sender is the shared instance of class KVATracker, which if you are using you may simply your call by using the function of the same name which omits this parameter.
 */
+ (void)sendCustomWithNameString:(nonnull NSString *)nameString infoString:(nullable NSString *)infoString senderArray:(nullable NSArray<KVAEventSenderProvider, KVADispatchQueueDelegate> *)senderArray NS_SWIFT_NAME(sendCustom(withNameString:infoString:senderArray:));



#pragma mark - CONSTRUCTION



/*!
 @method + customEventWithNameString:
 
 @brief Constructs an instance of class KVAEvent with event type KVAEventType.custom.
 
 @param customEventNameString A custom event name string.
 */
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString NS_SWIFT_NAME(init(customWithNameString:));



/*!
 @method + customEventWithNameString:infoDictionary:
 
 @brief Constructs an instance of class KVAEvent with event type KVAEventType.custom.
 
 @param customEventNameString A custom event name string.
 
 @param infoDictionary A dictionary (single dimensional) containing any number of values with keys.
 */
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString infoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(init(customWithNameString:infoDictionary:));



/*!
 @method + customEventWithNameString:infoString:
 
 @brief Constructs an instance of class KVAEvent with event type KVAEventType.custom.
 
 @param customEventNameString A custom event name string.
 
 @param infoString An info string.
 */
+ (nonnull instancetype)customEventWithNameString:(nonnull NSString *)customEventNameString infoString:(nullable NSString *)infoString NS_SWIFT_NAME(init(customWithNameString:infoString:));



@end



#endif



