//
//  KVAPartner.h
//  KochavaCore
//
//  Created by John Bushnell on 3/30/18.
//  Copyright © 2018 - 2020 Kochava, Inc.  All rights reserved.
//



#ifndef KVAPartner_h
#define KVAPartner_h



#pragma mark - IMPORT



#ifdef KOCHAVA_FRAMEWORK
#import <KochavaCore/KVAAsForContextObjectProtocol.h>
#import <KochavaCore/KVAConfigureWithObjectProtocol.h>
#import <KochavaCore/KVAFromObjectProtocol.h>
#else
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAFromObjectProtocol.h"
#endif



#pragma mark - CLASS



@class KVAContext;



#pragma mark - INTERFACE



/*!
 @class KVAPartner
 
 @brief The class KVAPartner defines a partner in the context of managing user consent in relationship to GDPR.
 
 @discussion When prompting for consent, the user should be presented with a list of the partners with which data would be shared.  That list can grow or contract independent of software version because data sharing can take place server-to-server.  With these partners being defined within your Kochava dashboard, changes can be made automatically, promptly, and across a range of software versions.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2018 - 2020 Kochava, Inc.
 */
@interface KVAPartner : NSObject <KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



#pragma mark - PARAMETERS



/*!
 @property descriptionString
 
 @brief A string containing a description of the partner.
 
 @discussion This property is optional.  This may be presented to the user when prompting for consent.
 
 Example: "Used to do X and Y."
 */
@property (strong, atomic, nullable, readonly) NSString *descriptionString;



/*!
 @property nameString
 
 @brief A string containing the name of the partner.
 
 @discussion This may be presented to the user when prompting for consent.
 
 Example: "Kochava"
 */
@property (strong, atomic, nullable, readonly) NSString *nameString;



#pragma mark - PROPERTIES



/*!
 @property responseBoolNumber
 
 @brief A boolean indicating the user's response.
 
 @discussion A value of true indicates consent was granted.  A value of false indicates consent was denied.  A value of nil exists when the user has not provided a response.
 */
@property (strong, atomic, nullable, readonly) NSNumber *responseBoolNumber;



/*!
 @property responseDate
 
 @brief The date when the user did respond to consent.
 
 @discussion This value is nil when the user has not provided a response.
 */
@property (strong, atomic, nullable, readonly) NSDate *responseDate;



/*!
 @property shouldPromptDueToBeingNewBool
 
 @brief A boolean indicating that the user should be prompted due to the partner being newly added.
 
 @discussion Internal.
 */
@property BOOL shouldPromptDueToBeingNewBool;



#pragma mark - GENERAL



/*!
 @method - didGrantDate:
 
 @brief Returns a date indicating when the user did grant consent.
 
 @discussion The returned value will be non-nil if the user's last response was to grant consent, even if that consent is not currently still valid.  Compare with isGrantedBool.
 */
- (nullable NSDate *)didGrantDate;



/*!
 @method - didPromptWithDidGrantBoolNumber:date:
 
 @brief A method for when the host did prompt for consent.
 
 @discussion Internal.
 
 @param didGrantBoolNumber The reponse from the user.  A value of true means consent was granted.  A value of false means consent was denied.
 
 @param date The date attributed to the response.
 */
- (void)didPromptWithDidGrantBoolNumber:(nullable NSNumber *)didGrantBoolNumber date:(nonnull NSDate *)date NS_SWIFT_NAME(didPrompt(didGrantBoolNumber:date:));



/*!
 @method - isEffectivelyReferringToTheSamePartner
 
 @brief Returns a boolean which indicates if two KVAPartner instances effectively refer to the same partner.
 
 @discussion Internal.
 */
- (BOOL)isEffectivelyReferringToTheSamePartner:(nullable KVAPartner *)anotherPartner NS_SWIFT_NAME(isEffectivelyReferringToTheSamePartner(_:));



/*!
@method - isGrantedBool

@brief Returns a boolean indicating if consent is granted.

@discussion This is a two-state version of isGrantedBoolNumber.  This will return false when isGrantedBoolNumber is nil.
*/
- (BOOL)isGrantedBool;



/*!
 @method - isGrantedBoolNumber
 
 @brief Returns a three-state boolean indicating if consent is granted, declined, or not known.
 
 @discussion This does not consider whether consent is required.
 */
- (nullable NSNumber *)isGrantedBoolNumber;



/*!
 @method - isGrantedDate
 
 @brief Returns a date for when consent was granted.
 
 @discussion If isGrantedBool, this returns responseDate.  If not, this returns nil.
 */
- (nullable NSDate *)isGrantedDate;



/*!
 @method - shouldBeIncludedInPromptBool
 
 @brief Returns a boolean indicating if this partner should be included in a prompt for consent.
 
 @discussion When prompting for consent you can include a list of all partners, but you may wish to list only those partners which may be new or updated.  Alternatively you may wish to denote the two separately.  This method will return a value of true when the partner should be included in a prompt for consent (or otherwise may be denoted separately).
 */
- (BOOL)shouldBeIncludedInPromptBool;



/*!
 @method - shouldPromptBool
 
 @brief Returns a boolean indicating if this partner raises a need to prompt for consent.
 
 @discussion Internal.  Compare with shouldBeIncludedInPromptBool.
 */
- (BOOL)shouldPromptBool;



/*!
 @method - willPrompt
 
 @brief Called to indicate that the user will be prompted for consent.
 
 @discussion Internal.  This is called autiomatically when the willPrompt method on KVAConsent is called.
 */
- (void)willPrompt;



@end



#endif



