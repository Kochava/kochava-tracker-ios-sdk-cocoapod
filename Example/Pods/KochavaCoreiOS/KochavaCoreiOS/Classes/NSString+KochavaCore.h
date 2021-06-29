//
//  NSString+KochavaCore.h
//  KochavaCore
//
//  Created by John Bushnell on 6/30/16.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef NSString_KochavaCore_h
#define NSString_KochavaCore_h



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



@interface NSString (KochavaCore) <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - GENERAL



/*!
 @method - kva_isNumberBool
 
 @brief A method which returns if the string is a number.
 */
- (BOOL)kva_isNumberBool;



/*!
 @method - kva_serializedJSONObject
 
 @brief Returns a JSON object, assuming that the string represents JSON.
 */
- (nullable id)kva_serializedJSONObject;



/*!
 @method - kva_withMaximumLength:

 @brief Returns a string which is limited to a maximum length.
 
 @discussion If the receiver is within the maximum length then self will be returned without copy.
 
 @param maximumLength The maximum length allowed.
 */
- (nonnull NSString *)kva_withMaximumLength:(NSUInteger)maximumLength NS_SWIFT_NAME(kva_withMaximumLength(_:));



#pragma mark - CLASS GENERAL



/*!
 @method + kva_stringFromJSONObject:prettyPrintBool:
 
 @brief A method to return a json string serialized from a json object.
 
 @param prettyPrintBool A boolean indicating whether you want the json to be pretty printed.  Pretty printing involves adding carriage returns, indentation, etc.  It generally makes it more human readable but increases the total bytes.
 
 @return A formatted string.
 */
+ (nullable NSString *)kva_stringFromJSONObject:(nullable id)jsonObject prettyPrintBool:(BOOL)prettyPrintBool NS_SWIFT_NAME(init(kva_fromJSONObject:prettyPrintBool:));



/*!
 @method + kva_string:isEqualToString:
 
 @brief A method to compare two strings for equality, which provides for the possibility that either string may be nil.
 
 @discussion Although you can test two strings for equality by using the isEqualToString: method directly, that comparison will fail if both strings are nil.  In contrast, this method will safely return true if both strings are nil.  It will also recognize when one string is nil and the other is not nil that they are not equal.
 */
+ (BOOL)kva_string:(nullable NSString *)string isEqualToString:(nullable NSString *)anotherString NS_SWIFT_NAME(kva_string(_:isEqualToString:));



@end



#endif



