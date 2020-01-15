//
//  KVASystem.h
//  KochavaCore
//
//  Created by John Bushnell on 12/28/17.
//  Copyright © 2017 - 2020 Kochava, Inc.  All rights reserved.
//



#ifndef KVASystem_h
#define KVASystem_h



#pragma mark - INTERFACE



/*!
 @class KVASystem
 
 @brief A class for working with system-level properties.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2017 - 2020 Kochava, Inc.
 */
@interface KVASystem : NSObject



#pragma mark - CLASS PROPERTIES
#pragma mark KVASystem.shared (Singleton Shared Instance)



/*!
 @property shared
 
 @brief The singleton shared instance.
 */
@property (class, readonly, strong, nonnull) KVASystem *shared;



#pragma mark - PROPERTIES



/*!
 @property stateActiveBool
 
 @brief A boolean indicating if the system's state is active.
 
 @discussion This considers the application active state and/or the extension active state (when applicable).  It unifies the notion of an system active state.
 */
@property (atomic, readonly) BOOL stateActiveBool;



#pragma mark - GENERAL



/*!
 @method - stateActiveDidBecome
 
 @brief A method which can be called to report that the active state should become true.

 @discussion Calling this method is generally redundant when the host is an application, as this change is observed automatically.  But this method can and should be called in app extensions, such as iMessage apps, to notify when the state is reported to have become active.
 */
- (void)stateActiveDidBecome;



/*!
@method - stateActiveWillResign

@brief A method which can be called to report that the active state should resign true.

@discussion Calling this method is generally redundant when the host is an application, as this change is observed automatically.  But this method can and should be called in app extensions, such as iMessage apps, to notify when the state is reported to have resigned active.
*/
- (void)stateActiveWillResign;



@end



#endif



