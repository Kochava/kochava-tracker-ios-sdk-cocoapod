//
//  KVAFromObjectProtocol.h
//  KochavaCore
//
//  Created by John Bushnell on 2/1/18.
//  Copyright © 2018 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAFromObjectProtocol_h
#define KVAFromObjectProtocol_h



@protocol KVAFromObjectProtocol <NSObject>



/*!
 @method + kva_fromObject:
 
 @brief Creates and returns an instance from another object.
 
 @param object An object from which to create the instance.  This is expected to be an NSDictionary in most contexts, but for specific implementations may be other classes.  Examples include, but are not limited to, NSString, NSNumber, NSData.  Native class objects are also generally assumed to be supported, returning themselves directly.
 */
+ (nullable instancetype)kva_fromObject:(nullable id)object
    NS_SWIFT_NAME(kva_from(object:));



@end



#endif



