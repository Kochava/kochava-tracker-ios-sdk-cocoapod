//
//  KVAConsent.h
//  KochavaCore
//
//  Created by John Bushnell on 3/30/18.
//  Copyright © 2018 - 2021 Kochava, Inc.  All rights reserved.
//



#ifndef KVAConsent_h
#define KVAConsent_h



#pragma mark - IMPORT



#pragma mark KochavaCore
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



@class KVAPartner;



#pragma mark - INTERFACE



/*!
 @class KVAConsent
 
 @brief The class KVAConsent provides a means of managing user consent in relationship to GDPR.
 
 @discussion Data sharing privacy laws such as GDPR require consent to be obtained before certain kinds of personal data may be collected or gathered, kept in memory, persisted or retained in persistent storage, and/or shared with partners.  During the natural lifecycle, there are times where partners may be added and cause the consent status to fall back to an unknown state.  Later the user may again be prompted and the consent status may (or may not) again come to be known.  All of this is predicated upon whether or not consent is required, which is governed by a variety of factors such as location.
 
 Inherits from: NSObject
 
 @author John Bushnell
 
 @copyright 2018 - 2021 Kochava, Inc.
 */
@interface KVAConsent : NSObject <NSCopying, KVAAsForContextObjectProtocol, KVAConfigureWithObjectProtocol, KVAFromObjectProtocol>



#pragma mark - TYPEDEF



/*!
 @typedef KVAConsentDidUpdateBlock
 
 @brief A block which is called when there is an update to consent.
 
 @discussion This can be used to prompt the user for consent and to enable and/or disable functionality.  Updates include, but are not limited to, when the user travels into or out of an area requiring consent, when new partners are added, and when conditions indicate a need to retry prompting the user.
 */
typedef void (^ KVAConsentDidUpdateBlock) (KVAConsent * _Nonnull consent);



#pragma mark - PARAMETERS



/*!
 @property descriptionString
 
 @brief A string containing a high level description concerning consent.
 
 @discussion Optional.  This may be presented to the user when prompting for consent.
 
 Sample Value: "We share information with various partners... we'd like your consent..."
 */
@property (strong, atomic, nullable, readonly) NSString *descriptionString;



/*!
 @property didUpdateBlock
 
 @brief A block which is called when there is an update to consent.
 
 @discussion This can be used to prompt the user for consent and to enable and/or disable functionality.  Updates include, but are not limited to, when the user travels into or out of an area requiring consent, when new partners are added, and when conditions indicate a need to retry prompting the user.
 */
@property (strong, nonatomic, nullable, readwrite) KVAConsentDidUpdateBlock didUpdateBlock;



/*!
 @property intelligentManagementBool
 
 @brief A boolean which indicates that intelligent management is enabled.
 
 @discussion When intelligent consent management is enabled and configured within your Kochava dashboard, the SDK will indicate when the user should be prompted for consent.  It will also not gather, persist, or transmit data which requires consent unless consent has been granted.
 */
@property BOOL intelligentManagementBool;



/*!
 @property manualManagedRequirementsBool
 
 @brief A boolean which indicates that the requirements for consent are managed manually (locally).
 
 @discussion When intelligent consent management is enabled and configured within your Kochava dashboard, the SDK will indicate when the user should be prompted for consent.  It will also not gather, persist, or transmit data which requires consent unless consent has been granted.
 */
@property BOOL manualManagedRequirementsBool;



/*!
 @property partnerArray
 
 @brief An array of instances of class KVAPartner.
 
 @discussion This array of partners can be utilized when prompting for consent.
 
 Swift example:
 @code
 let consent = KVATracker.shared.consent
 if let partnerArray = consent.partnerArray {
     for partner in partnerArray {
         print("do something with the partner... partner.nameString=\(String(describing: partner.nameString))")
     }
 }
 @endcode
 */
@property (strong, nonatomic, nullable, readonly) NSArray<KVAPartner *> *partnerArray;



/*!
 @property promptIdString
 
 @brief A string containing a unique value which, when changed, indicates a difference in what is required for consent.
 
 @discussion Internal.  The value provided by the server which can be used to override what actually happens, i.e. force a re-prompt.
 */
@property (strong, nonatomic, nullable, readonly) NSString *promptIdString;



/*!
 @property requiredBool
 
 @brief A boolean indicating if consent is required.
 
 @discussion This is expected to be true when the user is taken to be under the scope of consent gathering requirements such as GDPR.  This is expected to be the case for EU citizens within EU territory or abroad, and non-EU citizens within EU territory.  When requiredBoolNumber is undefined this will return a default of YES.  It will also be overridden to NO when intelligentManagementBool is NO.  This variable may also be set when Manual Managed Requirements is turned on.  See also requiredBoolNumber.
 */
@property (readwrite) BOOL requiredBool;



/*!
 @property requiredBoolNumber
 
 @brief A boolean indicating if consent is required.
 
 @discussion This is expected to be true when the user is taken to be under the scope of consent gathering requirements such as GDPR.  This is expected to be the case for EU citizens within EU territory or abroad, and non-EU citizens within EU territory.  When it is undefined this will return a default of nil.  This variable may also be set when Manual Managed Requirements is turned on.  See also requiredBool.
 */
@property (strong, nonatomic, nullable, readwrite) NSNumber *requiredBoolNumber;



#pragma mark - PROPERTIES



/*!
 @property responseDate
 
 @brief A date representing the last time the user did respond concerning consent.
 
 @discussion This includes both positive and negative responses.  This value is nil when the user has not provided a response.
 */
@property (strong, atomic, nullable, readonly) NSDate *responseDate;



/*!
 @property responseBoolNumber
 
 @brief A boolean indicating the user's response to a prompt for consent.
 
 @discussion A value of true indicates consent was granted.  A value of false indicates consent was denied.  A value of nil exists when the user has not provided a response.
 */
@property (strong, nonatomic, nullable, readonly) NSNumber *responseBoolNumber;



#pragma mark - GENERAL



/*!
 @method - didPromptWithDidGrantBoolNumber:
 
 @brief A method to be called when there has been a prompt for consent.
 
 @param didGrantBoolNumber The response from the user, as a boolean wrapped in an NSNumber.  A value of true means consent was granted.  A value of false means consent was denied.  A value of nil means the user did not provide a response, and this includes if the user may have dismissed the dialog without indicating one way or another.
 */
- (void)didPromptWithDidGrantBoolNumber:(nullable NSNumber *)didGrantBoolNumber NS_SWIFT_NAME(didPrompt(didGrantBoolNumber:));



/*!
 @method - isGrantedBool
 
 @brief Returns a boolean indicating if consent is granted.
 
 @discussion This considers if the user previously granted consent, as well as the current definition of consent- which may have changed since consent was last given.  This does not consider whether consent is required.  Compare with mayCollectBool, mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)isGrantedBool;



/*!
 @method - isGrantedBoolNumber
 
 @brief Returns a boolean indicating if consent is granted, denied, or there is no response.
 
 @discussion This considers if the user previously granted consent, as well as the current definition of the Consent which may have changed since consent was last given.  This does not consider whether consent is required.  See also isGrantedBool.  Compare with mayCollectBool, mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (nullable NSNumber *)isGrantedBoolNumber;



/*!
 @method - isGrantedDate
 
 @brief Returns a date for when consent was granted.
 
 @discussion If isGrantedBool, then this returns responseDate.  If not, then this returns nil.
 */
- (nullable NSDate *)isGrantedDate;



/*!
 @method - mayCalculateBool
 
 @brief Returns a boolean indicating if the app may calculate (or collect) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)mayCalculateBool __attribute__((deprecated("Deprecated in 4.2.0.  Please use mayCollectBool instead.")));



/*!
 @method - mayCollectBool
 
 @brief Returns a boolean indicating if the app may collect (or calculate) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)mayCollectBool;



/*!
 @method - mayKeepBool
 
 @brief Returns a boolean indicating if the app may keep (or retain in memory) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else the user did not otherwise previously deny consent.  This will return true while consent is not known, as long as the previous response did not deny consent.  This includes when the definition for consent has changed and the user previously granted consent.  Compare with mayCollectBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)mayKeepBool;



/*!
 @method - mayPersistBool
 
 @brief Returns a boolean indicating if the app may persist (or retain in persistent storage) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayCollectBool, mayKeepBool, and mayShareBool.
 */
- (BOOL)mayPersistBool;



/*!
 @method - mayShareBool
 
 @brief Returns a boolean indicating if the app may share (or export) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayCollectBool, mayKeepBool, and mayPersistBool.
 */
- (BOOL)mayShareBool;



/*!
 @method - shouldPromptBool
 
 @brief Returns a boolean indicating if a prompt for consent should be made.
 
 @discussion You should check this property when a call is made to didUpdateBlock to determine if the user should be prompted for consent.
 */
- (BOOL)shouldPromptBool;



/*!
 @method - willPrompt
 
 @brief A method which may be called to notify that a prompt for consent will be made.
 
 @discussion Optional.  This method can be used if you want to ensure that the prompt for consent will not be made again, even when a subsequent call to didPromptWithDidGrantBoolNumber: is never made, such as in the case of an unexpected termination.  If you call didPromptWithDidGrantBoolNumber: whenever the prompt is dismissed, even if the user did not give a response, then this method does not need to be called.
 */
- (void)willPrompt NS_SWIFT_NAME(willPrompt());



@end



#endif



