//
//  KVAContext.h
//  KochavaCore
//
//  Created by John Bushnell on 3/19/18.
//  Copyright © 2017 - 2019 Kochava, Inc.  All rights reserved.
//



#ifndef KVAContext_h
#define KVAContext_h



#pragma mark - IMPORT



#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"



#pragma mark - ENUM



#pragma mark - INTERFACE



/*!
 @class KVAContext
 
 @brief A class which defines a context.
 
 @discussion This class provides the means of defining the context for something that is being done.  It is generally used to identify a target or provider.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2018 - 2019 Kochava, Inc.
 */
@interface KVAContext : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - CLASS PROPERTIES



/*!
 @property + host
 
 @brief A context which represents the host app.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *host;



/*!
 @property + log
 
 @brief A context which represents the log.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *log;



/*!
 @property + persistentStorage
 
 @brief A context which represents persistentStorage.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *persistentStorage;



/*!
 @property + sdk
 
 @brief A context which represents the SDK.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *sdk;



/*!
 @property + sdkWrapper
 
 @brief A context which represents an SDK Wrapper.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *sdkWrapper;



/*!
 @property + server
 
 @brief A context which represents the Server.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *server;



/*!
 @property + serverUnrestricted
 
 @brief A context which represents the Server, and is un-restricted by considerations such as whitelist and blacklist.
 
 @discussion This is of particualar relevance with KVANetTransaction(s) where whitelist and/or blacklist information may not (or not yet) be known, such as the Tracker.trInitNetTransaction.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAContext *serverUnrestricted;



#pragma mark - PARAMETERS



/*!
 @property nameString
 
 @brief The name.
 
 @discussion Examples:  "host", "log", "persistentStorage", "sdk", "server".
 */
@property (strong, nonatomic, nonnull) NSString *nameString;



#pragma mark - CLASS GENERAL



/*!
 @method + kva_fromObject:
 
 @brief A method to return a context from another object.
 
 @return A context.  A value of nil will be returned if the object is not recognized.
 */
+ (nullable instancetype)kva_fromObject:(nullable id)fromObject NS_SWIFT_NAME(kva_fromObject(_:));



#pragma mark - GENERAL



/*!
 @method - kva_asForContextObjectWithContext:
 
 @brief Converts the object for a given target context.
 
 @discussion The returned value will be a nullable NSMutableDictionary.
 */
- (nullable NSObject *)kva_asForContextObjectWithContext:(nullable KVAContext *)context NS_SWIFT_NAME(kva_asForContextObject(withContext:));



@end



#endif



