//
//  KVATrackerProduct.h
//  KochavaTracker
//
//  Created by John Bushnell on 11/9/17.
//  Copyright © 2017 - 2019 Kochava, Inc.  All rights reserved.
//



#ifndef KVATrackerProduct_h
#define KVATrackerProduct_h



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
#import "KVAProduct.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVATrackerProduct
 
 @brief A class which defines a tracker product.
 
 @discussion A product in this context generally refers to the result of a build.
 
 Inherits from: KVAProduct
 
 @author John Bushnell
 
 @copyright 2017 - 2019 Kochava, Inc.
 */
@interface KVATrackerProduct : KVAProduct



#pragma mark - CLASS PROPERTIES
#pragma mark KVATrackerProduct.shared (Singleton Shared Instance)



/*!
 @property shared
 
 @brief The singleton shared instance.
 */
@property (class, readonly, strong, nonnull) KVATrackerProduct *shared;



@end



#endif



