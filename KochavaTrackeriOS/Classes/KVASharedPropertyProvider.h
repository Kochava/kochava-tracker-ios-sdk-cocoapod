//
//  KVASharedPropertyProvider.h
//  KochavaCore
//
//  Created by John Bushnell on 7/26/19.
//  Copyright © 2019 - 2020 Kochava, Inc.  All rights reserved.
//



#ifndef KVASharedPropertyProvider_h
#define KVASharedPropertyProvider_h



#pragma mark - PROTOCOL



@protocol KVASharedPropertyProvider <NSObject>



/*!
 @property shared
 
 @brief A shared instance.
 */
@property (class, readonly, strong, nonnull) NSObject *shared;



@end



#endif



