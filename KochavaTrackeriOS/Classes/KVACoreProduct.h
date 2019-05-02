//
//  KVACoreProduct.h
//  KochavaCore
//
//  Created by John Bushnell on 11/9/17.
//  Copyright © 2017 - 2019 Kochava, Inc.  All rights reserved.
//



#ifndef KVACoreProduct_h
#define KVACoreProduct_h



#pragma mark - IMPORT



#import "KVAProduct.h"



#pragma mark - INTERFACE



/*!
 @class KVACoreProduct
 
 @brief A class which defines a tracker product.
 
 @discussion A product in this context generally refers to the result of a build.
 
 Inherits from: KVAProduct
 
 @author John Bushnell
 
 @copyright 2017 - 2019 Kochava, Inc.
 */
@interface KVACoreProduct : KVAProduct



#pragma mark - CLASS PROPERTIES
#pragma mark KVACoreProduct.shared (Singleton Shared Instance)



/*!
 @property shared
 
 @brief The singleton shared instance.
 */
@property (class, readonly, strong, nonnull) KVACoreProduct *shared;



@end



#endif



