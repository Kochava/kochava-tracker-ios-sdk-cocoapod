//
//  KVAProduct.h
//  KochavaCore
//
//  Created by John Bushnell on 11/9/17.
//  Copyright © 2017 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAProduct_h
#define KVAProduct_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KVAAsForContextObjectProtocol.h>
#import <KochavaCore/KVAFromObjectProtocol.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVALogLevel;



#pragma mark - INTERFACE



/*!
 @class KVAProduct
 
 @brief A class which defines a product.
 
 @discussion A product in this context generally refers to the result of a build.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2017 - 2021 Kochava, Inc.
 */
@interface KVAProduct : NSObject <KVAAsForContextObjectProtocol, KVAFromObjectProtocol>



#pragma mark - PROPERTIES



/*!
 @property apiVersionString
 
 @brief An API version string.
 
 @discussion This property is used to establish API compatibility between products.  API compatibility is assumed to be assured when the value compares to be equal for all products with the same organizationNameString.
 */
@property (strong, nonatomic, nullable, readonly) NSString *apiVersionString;



/*!
 @property buildDateString
 
 @brief A string containing the date when the product was built.
 */
@property (strong, nonatomic, nullable, readonly) NSString *buildDateString;



/*!
 @property bundleIdentifierString
 
 @brief A string containing the bundle identifier associated with this product.  This property may be used to cross-reference this product from a Class.  Logging uses this to take the class for a LogMessage and lookup the associated Product.
 */
@property (strong, nonatomic, nullable, readonly) NSString *bundleIdentifierString;



/*!
 @property bundleTypeString

 @brief The library type.

 @discussion Example: "xcframework", "dynamic framework", "static library", "app".
*/
@property (strong, nonatomic, nonnull, readonly) NSString *bundleTypeString;



/*!
 @property compilerFlagNameStringArray
 
 @brief An array containing strings which are the names of compiler flags.
 */
@property (strong, nonatomic, nullable, readonly) NSArray<NSString *> *compilerFlagNameStringArray;



/*!
 @property compilerFlagPredicateSubstitutionVariablesDictionary
 
 @brief A dictionary containing substitution variables for use with an NSPredicate containing compiler flags.
 */
@property (strong, nonatomic, nullable, readonly) NSDictionary *compilerFlagPredicateSubstitutionVariablesDictionary;



/*!
 @property logLevel
 
 @brief The log level for the product.
 
 @discussion Default nil.  When set this overrides the log default for log messages generated within the product.
 */
@property (strong, atomic, nullable, readwrite) KVALogLevel *logLevel;



/*!
 @property moduleNameString
 
 @brief The name of the module.
 
 @discussion Example: "KochavaCore".
 */
@property (strong, nonatomic, nonnull, readonly) NSString *moduleNameString;



/*!
 @property nameString
 
 @brief A name string.
 
 @discussion Example: "KochavaCoreiOS".
 */
@property (strong, nonatomic, nonnull, readonly) NSString *nameString;



/*!
 @property nameWithVersionString
 
 @brief A string containing the name and the version.
 
 @discussion The two are delimited by a space.
 */
@property (strong, nonatomic, nonnull, readonly) NSString *nameWithVersionString;



/*!
 @property standardVersionInfoString
 
 @brief A string containing the name and the version.
 
 @discussion The two are delimited by a space.
 */
@property (strong, nonatomic, nonnull, readonly) NSString *standardVersionInfoString;



/*!
 @property organizationNameString
 
 @brief A string containing the name of the organization representing the product.
 */
@property (strong, nonatomic, nonnull, readonly) NSString *organizationNameString;



/*!
 @property reverseDomainNameString
 
 @brief A string containing a reverse domain name style representation of the name of the product.
 
 @discussion This is used in the definition of keys for persistent storage, dispatch queues, etc.
 
 Example:  "com.kochava.KochavaCore"
 
 Note:  This excludes a trailing period.
 */
@property (strong, nonatomic, nullable, readonly) NSString *reverseDomainNameString;



/*!
 @property versionString
 
 @brief A version string.
 */
@property (strong, nonatomic, nullable, readonly) NSString *versionString;



/*!
 @property wrapperProduct
 
 @brief An optional product which wraps this product.
 */
@property (strong, nonatomic, nullable, readwrite) KVAProduct *wrapperProduct NS_SWIFT_NAME(wrapperProduct);



#pragma mark - GENERAL



/*!
 @method - register
 
 @brief Registers the product.
 
 @discussion Generally Kochava products automatically register themselves, but there are a few exceptions.  If you're using a product which is optional and weakly linked, this method should be called once, early, to register the product for use.  One such example is the product KochavaLocation.  As a weakly-linked optional product, it would be optimized away by the linker if a call to register it was not explicitly made and if there were no other explicit interactions early with its API.  For products which automtically register themselves calling this method is redundant and will have no effect.  Important Note:  The existence of a product will not be recognized by the SDK until it has been registered.  It is important therefore to register the product before configuring an instance of class KVATracker to ensure that it is recognized by the SDK at the time when it may be needed;  however, that having been said, some products if registered immediately afterward will still be guaranteed to be recognized in time due to architectural considerations designed to avoid a race condition.  You should not assume that registering a product after configuring a tracker is guaranteed to work properly.
 */
- (void)register;



/*!
@method - resetWithDeleteLocalDataBool:

@brief Resets the product.

@discussion This involves resetting variables to their original states.  This may include releasing shared instances.  When parameter deleteLocalDataBool is passed true it also includes erasing any keys from persistent storage which are associated with the product.
 
 @param deleteLocalDataBool A boolean indicating whether or not local data should be deleted.
*/
- (void)resetWithDeleteLocalDataBool:(BOOL)deleteLocalDataBool NS_SWIFT_NAME(reset(deleteLocalDataBool:));



/*!
 @method - shutdownWithDeleteLocalDataBool:

 @brief Shuts down the product.

 @discussion This can be regarded as being equivalent to performing a reset, but may also include hints to avoid performing automatic behavior consistent with being freshly initialized. 
 
 @param deleteLocalDataBool A boolean indicating whether or not local data should be deleted.
*/
- (void)shutdownWithDeleteLocalDataBool:(BOOL)deleteLocalDataBool NS_SWIFT_NAME(shutdown(deleteLocalDataBool:));



#pragma mark - CLASS GENERAL



/*!
 @method + productWithAPIVersionString:buildDateString:bundleIdentifierString:compilerFlagNameStringArray:compilerFlagPredicateSubstitutionVariablesDictionary:nameString:organizationNameString:reverseDomainNameString:versionString:
 
 @brief Creates and returns a product.
 */
+ (nonnull instancetype)productWithAPIVersionString:(nullable NSString *)apiVersionString buildDateString:(nullable NSString *)buildDateString bundleIdentifierString:(nullable NSString *)bundleIdentifierString bundleTypeString:(nullable NSString *)bundleTypeString compilerFlagNameStringArray:(nullable NSArray<NSString *> *)compilerFlagNameStringArray compilerFlagPredicateSubstitutionVariablesDictionary:(nullable NSDictionary *)compilerFlagPredicateSubstitutionVariablesDictionary moduleNameString:(nonnull NSString *)moduleNameString nameString:(nonnull NSString *)nameString organizationNameString:(nonnull NSString *)organizationNameString reverseDomainNameString:(nullable NSString *)reverseDomainNameString versionString:(nullable NSString *)versionString;



@end



#endif



