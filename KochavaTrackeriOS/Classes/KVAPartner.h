//
//  KVAPartner.h
//  KochavaTracker
//
//  Created by John Bushnell on 3/30/18.
//  Copyright © 2018 Kochava. All rights reserved.
//



#pragma mark - IMPORT



#import "KVAAsForContextObjectProtocol.h"

#import "KVAFromObjectProtocol.h"



#pragma mark - CLASS



@class KVAContext;



#pragma mark - INTERFACE



@interface KVAPartner : NSObject <KVAFromObjectProtocol, KVAAsForContextObjectProtocol>



#pragma mark - PARAMETERS



/*!
 @property descriptionString
 
 @brief A description of the partner.
 
 @discussion Optional.  This may be presented to the user when prompting for consent.
 
 Example: "Used to do X and Y."
 */
@property (strong, nonatomic, nullable, readonly) NSString *descriptionString;



/*!
 @property nameString
 
 @brief The name of the partner.
 
 @discussion This may be presented to the user when prompting for consent.
 
 Example: "Kochava"
 */
@property (strong, nonatomic, nullable, readonly) NSString *nameString;



#pragma mark - PROPERTIES



/*!
 @property responseBoolNumber
 
 @brief A boolean indicating the user's response.
 
 @discussion A value of true indicates consent was granted.  A value of false indicates consent was denied.  A value of nil exists when the user has not provided a response.
 */
@property (strong, nonatomic, nullable, readonly) NSNumber *responseBoolNumber;



/*!
 @property responseDate
 
 @brief The date when the user did respond to consent.
 
 @discussion This value is nil when the user has not provided a response.
 */
@property (strong, nonatomic, nullable, readonly) NSDate *responseDate;



/*!
 @property shouldPromptDueToBeingNewBool
 
 @brief A boolean indicating that the user should be prompted due to the partner being newly added.
 
 @discussion Internal.
 */
@property BOOL shouldPromptDueToBeingNewBool;



#pragma mark - GENERAL



/*!
 @method - asForContextObjectWithContext:
 
 @brief Converts the object for a given target context.
 
 @discussion The returned value will be a nullable NSMutableDictionary.
 */
- (nullable NSObject *)asForContextObjectWithContext:(nullable KVAContext *)context NS_SWIFT_NAME(asForContextObject(withContext:));



/*!
 @method - didGrantDate:
 
 @brief A date indicating when the user did grant consent.
 
 @discussion The returned value will be non-nil if the user's last response was to grant consent, even if that consent is not currently valid.  Compare with isGrantedBool.
 */
- (nullable NSDate *)didGrantDate;



/*!
 @method - didPromptWithDidGrantBoolNumber:date:
 
 @brief A method for when the host did respond for consent.
 
 @discussion Internal.
 
 @param didGrantBoolNumber The reponse from the user.  A value of true means consent was granted.  A value of false means consent was denied.
 
 @param date The date attributed to the response.
 */
- (void)didPromptWithDidGrantBoolNumber:(nullable NSNumber *)didGrantBoolNumber date:(nonnull NSDate *)date;



/*!
 @method - isEffectivelyReferringToTheSamePartner
 
 @brief A method returning a boolean which indicates if two KVAPartner instances effectively refer to the same partner.
 
 @discussion Internal.
 */
- (BOOL)isEffectivelyReferringToTheSamePartner:(nullable KVAPartner *)anotherPartner NS_SWIFT_NAME(isEffectivelyReferringToTheSamePartner(_:));



/*!
@method - isGrantedBool

@brief A method returning a boolean indicating if consent is granted.

@discussion This is a two-state version of isGrantedBoolNumber.  This will return false when isGrantedBoolNumber is nil.
*/
- (BOOL)isGrantedBool;



/*!
 @method - isGrantedBoolNumber
 
 @brief A method returning a three-state boolean indicating if consent is granted, declined, or not known.
 
 @discussion This does not consider whether consent is required.
 */
- (nullable NSNumber *)isGrantedBoolNumber;



/*!
 @method - isGrantedDate
 
 @brief A method returning a date for when consent was granted.
 
 @discussion If isGrantedBool, this returns responseDate.  If not, this returns nil.
 */
- (nullable NSDate *)isGrantedDate;



/*!
 @method - shouldBeIncludedInPromptBool
 
 @brief A method returning a boolean indicating if this partner should be included in a prompt for consent.
 */
- (BOOL)shouldBeIncludedInPromptBool;



/*!
 @method - shouldPromptBool
 
 @brief A method returning a boolean indicating if this partner raises a need to prompt for consent.
 
 @discussion Internal.  Compare with shouldBeIncludedInPromptBool.
 */
- (BOOL)shouldPromptBool;



/*!
 @method - updateFrom:context:
 
 @brief Updates the receiver from another instance.
 
 @discussion Internal.
 
 @param fromObject An object from which to update the instance.  This is expected to be a native instance, or else an object which can resolve to a native instance.
 
 @param context Optional.  The context.
 */
- (void)updateFrom:(nullable id)fromObject context:(nullable KVAContext *)context;



/*!
 @method - willPrompt
 
 @brief Called to indicate that the user will be prompted for consent.
 
 @discussion Internal.  This is called autiomatically when the willPrompt method on KVAConsent is called.
 */
- (void)willPrompt;



#pragma mark - LIFECYCLE



/*!
 @method + fromObject:
 
 @discussion Internal.
 
 @brief A method to return an instance of consent from another object.
 
 @return A consent.  A value of nil will be returned if the object is not recognized.
 */
+ (nullable instancetype)fromObject:(nullable id)fromObject NS_SWIFT_NAME(init(fromObject:));



@end



