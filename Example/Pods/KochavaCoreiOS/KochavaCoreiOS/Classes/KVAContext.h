//
//  KVAContext.h
//  KochavaCore
//
//  Created by John Bushnell on 3/19/18.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAContext_h
#define KVAContext_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KVAAsForContextObjectProtocol.h>
#import <KochavaCore/KVAFromObjectProtocol.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAContext
 
 @brief A class which defines a context.
 
 @discussion This class provides the means of defining the context for something that is being done.  It is generally used to identify a target or provider.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2018 - 2021 Kochava, Inc.
 */
@interface KVAContext : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - ENUMERATED VALUES



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
 @property + server
 
 @brief A context which represents the Server.
 */
@property (class, strong, nonatomic, nonnull, readonly) KVAContext *server;



/*!
 @property + serverUnrestricted
 
 @brief A context which represents the Server, and is un-restricted by considerations such as allowed and denied identifiers.
 
 @discussion This is of particular relevance with KVANetTransaction(s) where allowed and/or denied identifiers may not (or not yet) be known, such as config retrievals.
 */
@property (class,strong, nonatomic, nonnull, readonly) KVAContext *serverUnrestricted;



#pragma mark - PARAMETERS



/*!
 @property nameString
 
 @brief The name.
 
 @discussion Examples:  "host", "log", "persistentStorage", "sdk", "server".
 */
@property (strong, nonatomic, nonnull, readonly) NSString *nameString;



@end



#endif



