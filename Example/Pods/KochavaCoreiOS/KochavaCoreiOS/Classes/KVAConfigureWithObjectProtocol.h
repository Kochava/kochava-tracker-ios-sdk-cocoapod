//
//  KVAConfigureWithObjectProtocol.h
//  KochavaCore
//
//  Created by John Bushnell on 2/1/18.
//  Copyright © 2018 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAConfigureWithObjectProtocol_h
#define KVAConfigureWithObjectProtocol_h



#pragma mark - CLASS



@class KVAContext;



#pragma mark - PROTOCOL



@protocol KVAConfigureWithObjectProtocol <NSObject>



/*!
 @method - kva_configureWith:context:
 
 @brief Configures (updates) the instance from another object.
 
 @param withObject An object from which to update the instance.  This is expected to be a native instance, or else an object which can resolve to a native instance.
 
 @param context Optional.  The context.
 */
- (void)kva_configureWith:(nullable id)withObject context:(nullable KVAContext *)context NS_SWIFT_NAME(kva_configure(with:context:));



@end



#endif



