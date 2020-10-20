//
//  KVAAppGroups.h
//  KochavaCore
//
//  Created by John Bushnell on 9/29/20.
//  Copyright © 2020 Kochava, Inc.  All rights reserved.
//



#ifndef KVAAppGroups_h
#define KVAAppGroups_h



#pragma mark - INTERFACE



/*!
 @class KVAAppGroups
 
 @brief A class for working with the App Groups capability.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2020 Kochava, Inc.
 */
@interface KVAAppGroups : NSObject



#pragma mark - SHARED INSTANCE (SINGLETON)



/*!
 @property shared
 
 @brief The singleton shared instance.
 */
@property (class, readonly, strong, nonnull) KVAAppGroups *shared;



#pragma mark - PROPERTIES



/*!
 @property deviceAppGroupIdentifierString
 
 @brief A string which corresponds to an app group identifier to be used as a shared container for the Kochava SDK.
 */
@property (strong, atomic, nullable, readwrite) NSString *deviceAppGroupIdentifierString;



@end



#endif



