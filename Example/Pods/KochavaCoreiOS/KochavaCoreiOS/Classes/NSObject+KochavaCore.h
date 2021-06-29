//
//  NSObject+KochavaCore.h
//  KochavaCore
//
//  Created by John Bushnell on 2/7/18.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef NSObject_KochavaCore_h
#define NSObject_KochavaCore_h



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



@interface NSObject (KochavaCore) <KVAAsForContextObjectProtocol>



#pragma mark - TYPEDEF



/*!
 @typedef KVACustomMethodsBlock
 
 @brief Defines a block which is intended to hold custom methods which can be used to extend individual instances of an object.
 */
typedef void (^ KVACustomMethodsBlock) (NSObject * _Nonnull object, NSString * _Nonnull methodNameString, NSDictionary * _Nullable parametersDictionary);



#pragma mark - CONSTRUCTOR



/*!
 @method - kva_redactedCopyFromKeyStringRedactedBoolDictionary:
 
 @brief Returns a redacted copy.
 
 @param keyStringRedactedBoolDictionary A dictionary containing redactedBoolNumber(s) keyed by keyString(s).
 
 @param redactedKeyArray An array of keys which were redacted, which is modified.
 
 @discussion This method only redacts.  As such, any containers within the returned object will be the same as those provided.  That is to say that if those containers were mutable they will remain mutable.  Also this does not effect a deep copy, optimizing for performance.
 */
- (nullable id)kva_redactedCopyFromKeyStringRedactedBoolDictionary:(nullable NSDictionary *)keyStringRedactedBoolDictionary key:(nullable NSObject *)key redactionKeySuffixString:(nullable NSString *)redactionKeySuffixString redactedKeyArray:(nullable NSMutableArray *)redactedKeyArray NS_SWIFT_NAME(kva_redactedCopy(fromKeyStringRedactedBoolDictionary:key:redactionKeySuffixString:redactedKeyArray:));



#pragma mark - CLASS GENERAL



/*!
 @method + kva_object:isEqualToObject:
 
 @brief A method to compare two objects for equality, which provides for the possibility that either object may be nil.
 
 @discussion Although you can test two objects for equality by using the isEqual: method directly, that comparison will fail if both strings are nil.  In contrast, this method will safely return true if both objects are nil.  It will also recognize when one object is nil and the other is not nil that they are not equal.
 */
+ (BOOL)kva_object:(nullable NSObject *)object isEqualToObject:(nullable NSObject *)anotherObject NS_SWIFT_NAME(kva_object(_:isEqualToObject:));



/*!
 @method + kva_fromObject:class:
 
 @brief Returns a native object for a class from another object.
 
 @param fromObject An object which may or may not be a native class object, with the hope that it may not be but may be convertable to one.  Non-native objects are typically instances of NSDictionary or NSArray which were created from a call to an asForContextObjectWithContext method.  They may also have originated from external sources, such as servers, and often are valid JSON.

 @param class The target class.  This parameter is optional.  When omitted the class to use will be inferred from kva_fromObject, if possible.  This typically becomes possible when kva_fromObject is a dictionary which contains a key "$class" which specifies the class, or else when kva_fromObject is an array of objects which can be similarly resolved.  When this parameter is passed, it takes precedence over these specifications, and will enforce the class by attempting to create an object from the specified class.  If kva_fromObject is not truly an object which can be converted to the class, the results may be less than desireable, as you should generally expect to end up with an object of the specified class which is relatively unconfigured (or nil altogether).
 
 @param elementClass A target class for any elements.  This parameter is optional.  This parameter generally applies to cases of class where the class would have elements, such as arrays and sets.  The rules for how this is used is identical to class, except applied to any elements within the class.
 
 @discussion If an object cannot be converted then kva_fromObject will be returned as-is, making this method safe to be used on any object to see if it can be brought into a native class object.
 */
+ (nullable id)kva_fromObject:(nullable id)fromObject class:(nullable Class)class elementClass:(nullable Class)elementClass NS_SWIFT_NAME(kva_fromObject(_:class:elementClass:));



/*!
 @method + kva_nonnullObjectFromObject:
 
 @return A santized object purposed for use as a dictionary value.  The returned value is guaranteed to not be nil so that it can be safely sent straight into a dictionary constructor that would crash with if passed a nil value.
 */
+ (nonnull id)kva_nonnullObjectFromObject:(nullable id)object;



/*!
 @method + kva_sanitizedNameStringForClass
 
 @discussion Occasionally when we receive an object back from the operating system, it has an unexpected class.  It's usually some low-level or undocumented class that is supposed to behave equivalently to the class we expect, but the problem is that these names are not safe to be persisted.  A future operating system could come along with a new underlying class name and have no support for the previous one.  This method santizes for the things we know about.
 */
+ (nonnull NSString *)kva_sanitizedNameStringForClass:(nullable Class)class;



#pragma mark - CONSTRUCTORS



/*!
 @method - kva_objectAppendingObject1:object2:
 
 @brief Appends two objects.
 
 @discussion Supports the appending of two objects with deep support for specific types such as NSDictionary and NSArray.  This supports working with JSON objects.
 */
+ (nullable id)kva_objectAppendingObject1:(nullable id)object1 object2:(nullable id)object2 NS_SWIFT_NAME(kva_objectAppending(object1:object2:));



#pragma mark - LIFECYCLE



/*!
 @method - kva_didMutate
 
 @brief A method to call when the object did mutate.
 
 @discussion This will broadcast a standardized notification.
 */
- (void)kva_didMutate;



/*!
 @method - kva_didMutateWithInfoDictionary
 
 @brief A method to call when the object did mutate.
 
 @discussion This will broadcast a standardized notification.  It will dispatch to the globalSerial dispatch queue before posting the notification.
 
 @param infoDictionary A dictionary containing information about the mutation.
 */
- (void)kva_didMutateWithInfoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(kva_didMutate(withInfoDictionary:));



/*!
 @method - kva_didMutate_withoutDispatch_withInfoDictionary
 
 @brief A method to call when the object did mutate.
 
 @discussion This will broadcast a standardized notification.  It will do this on the caller's thread.
 
 @param infoDictionary A dictionary containing information about the mutation.
 */
- (void)kva_didMutate_withoutDispatch_withInfoDictionary:(nullable NSDictionary *)infoDictionary NS_SWIFT_NAME(kva_didMutate_withoutDispatch(withInfoDictionary:));



/*!
 @method - kva_didMutate_addObserverUsingBlock:
 
 @brief A method to create an observer to observe when the value of this adapter is taken to have mutated.
 
 @discussion This mechanism may not ensure that the value returned is definitely different as there are factors such as range checking which may influence the value and may cause it to be the same even when the underlying raw value may have changed.
 
 @return An observer.
 */
- (nullable id<NSObject>)kva_didMutate_addObserverUsingBlock:(void (^ _Nullable)(NSNotification * _Nullable notification))block;



/*!
 @method - kva_mayMutateBool
 
 @brief Returns whether the object is capable of mutating.

 @discussion Returns YES for any class except for those known to be immutable, such as NSString, NSDate, etc.  Excluded are classes such as NSArray and NSDictionary which may contain elements which may themselves mutate.  This method can theoretically be overridden to designate the objects of class as immutable.
 */
- (BOOL)kva_mayMutateBool;



#pragma mark - ENCODING



/*!
 @method - kva_asForContextObjectProtocol
 
 @brief Returns the receiver if it conforms to the KVAAsForContextObjectProtocol, otherwise returns nil.
 
 @discussion This is a convenience method to cast an object to a KVAAsForContextObjectProtocol.
 */
- (nullable NSObject<KVAAsForContextObjectProtocol> *)kva_asForContextObjectProtocol;



@end



#endif



