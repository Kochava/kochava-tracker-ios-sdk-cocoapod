//
//  KVAIdentityLink.h
//  KochavaTracker
//
//  Created by John Bushnell on 7/2/20.
//  Copyright © 2020 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAIdentityLink_h
#define KVAIdentityLink_h



#pragma mark - IMPORT



#pragma mark KochavaCore
#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KochavaCore.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - INTERFACE



/*!
 @class KVAIdentityLink
 
 @brief A controller for working with identityLink.
 
 @author John Bushnell
 
 @copyright 2020 - 2021 Kochava, Inc.
 */
@interface KVAIdentityLink : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



/*!
 @method - registerWithNameString:identifierString:
 
 @brief Registers and identity link.
 
 @param nameString The name of the identifier.
 
 @param identifierString The identifier.
 
 Important Note:  When possible, this method should be called as soon as possible after the tracker is started.  This ensures that your identity values are always associated with your install.
 */
- (void)registerWithNameString:(nonnull NSString *)nameString identifierString:(nonnull NSString *)identifierString NS_SWIFT_NAME(register(withNameString:identifierString:));



@end



#endif



