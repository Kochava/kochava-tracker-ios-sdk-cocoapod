//
//  KVAAsForContextObjectProtocol.h
//  KochavaTracker
//
//  Created by John Bushnell on 2/1/18.
//  Copyright © 2018 Kochava, Inc. All rights reserved.
//



#ifndef KVAAsForContextObjectProtocol_h
#define KVAAsForContextObjectProtocol_h



#pragma mark - CLASS



@class KVAContext;



#pragma mark - PROTOCOL



@protocol KVAAsForContextObjectProtocol <NSObject>



/*!
 @method - asForContextObjectWithContext:
 
 @brief Converts the object for a given target context.
 
 @discussion The returned value will be a nullable NSMutableDictionary.
 */
- (nullable NSObject *)asForContextObjectWithContext:(nullable KVAContext *)context NS_SWIFT_NAME(asForContextObject(withContext:));



@end



#endif



