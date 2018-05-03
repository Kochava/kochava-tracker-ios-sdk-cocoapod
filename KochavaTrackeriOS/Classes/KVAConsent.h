//
//  KVAConsent.h
//  KochavaTracker
//
//  Created by John Bushnell on 3/30/18.
//  Copyright © 2018 Kochava. All rights reserved.
//



#pragma mark - IMPORT



#import "KVAAsForContextObjectProtocol.h"

#import "KVAFromObjectProtocol.h"



#pragma mark - CLASS



@class KVAPartner;



#pragma mark - INTERFACE



@interface KVAConsent : NSObject <NSCopying, KVAFromObjectProtocol, KVAAsForContextObjectProtocol>



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
 
 @brief A description of the partner.
 
 @discussion Optional.  This may be presented to the user when prompting for consent.
 
 Example: "Used to do X and Y."
 */
@property (strong, nonatomic, nullable, readonly) NSString *descriptionString;



/*!
 @property didUpdateBlock
 
 @brief A block which is called when there is an update to consent.
 
 @discussion This can be used to prompt the user for consent and to enable and/or disable functionality.  Updates include, but are not limited to, when the user travels into or out of an area requiring consent, when new partners are added, and when conditions indicate a need to retry prompting the user.
 */
@property (strong, nonatomic, nullable, readwrite) KVAConsentDidUpdateBlock didUpdateBlock;



/*!
 @property intelligentManagementBool
 
 @brief A boolean which indicates that intelligent management is enabled.
 
 @discussion Internal.  See kKVAParamConsentIntelligentManagementBoolKey.  When intelligent consent management is enabled and configured within your Kochava dashboard, the SDK will indicate when the user should be prompted for consent.  It will also not gather, persist, or transmit data which requires consent unless consent has been granted.
 */
@property BOOL intelligentManagementBool;



/*!
 @property partnerArray
 
 @brief An array of KVAPartner(s).
 
 Swift example:
 @code
 if (consent.partnerArray != nil)
 {
     for partner in consent.partnerArray! as! [KVAPartner]
     {
         print("partner name = \(partner.nameString!)")
     }
 }
 @endcode
 */
@property (strong, nonatomic, nullable, readonly) NSMutableArray<KVAPartner *> *partnerArray;



/*!
 @property promptIdString
 
 @brief A string containing a unique value which, when changed, indicates a difference in what is required for consent.
 
 @discussion Internal.  The value provided by the server which can be used to override what actually happens, i.e. force a re-prompt.
 */
@property (strong, nonatomic, nullable, readonly) NSString *promptIdString;



/*!
 @property requiredBool
 
 @brief A boolean indicating if consent is required.
 
 @discussion This is expected to be true when the user is taken to be under the scope of consent gathering requirements such as GDPR.  This is expected to be the case for EU citizens within EU territory or abroad, and non-EU citizens within EU territory.  When requiredBoolNumber is undefined this will return a default of YES.  It will also overridden to NO when intelligentManagementBool is NO.  See also requiredBoolNumber.
 */
@property (readonly) BOOL requiredBool;



/*!
 @property requiredBoolNumber
 
 @brief A boolean indicating if consent is required.
 
 @discussion This is expected to be true when the user is taken to be under the scope of consent gathering requirements such as GDPR.  This is expected to be the case for EU citizens within EU territory or abroad, and non-EU citizens within EU territory.  When it is undefined this will return a default of nil.  See also requiredBool.
 */
@property (strong, nonatomic, nullable, readonly) NSNumber *requiredBoolNumber;



#pragma mark - PROPERTIES



/*!
 @property responseDate
 
 @brief A date representing the last time the user did respond concerning consent.
 
 @discussion This value is nil when the user has not provided a response.
 */
@property (strong, nonatomic, nullable, readonly) NSDate *responseDate;



/*!
 @property responseBoolNumber
 
 @brief A boolean indicating the user's response.
 
 @discussion A value of true indicates consent was granted.  A value of false indicates consent was denied.  A value of nil exists when the user has not provided a response.
 */
@property (strong, nonatomic, nullable, readonly) NSNumber *responseBoolNumber;



#pragma mark - GENERAL



/*!
 @method - asForContextObjectWithContext:
 
 @brief Converts the object for a given target context.
 
 @discussion The returned value will be a nullable NSMutableDictionary.
 */
- (nullable NSObject *)asForContextObjectWithContext:(nullable KVAContext *)context NS_SWIFT_NAME(asForContextObject(withContext:));



/*!
 @method - didPromptWithDidGrantBoolNumber:
 
 @brief A method to be called when there has been a prompt for consent.
 
 @param didGrantBoolNumber The reponse from the user, as a boolean wrapped in an NSNumber.  A value of true means consent was granted.  A value of false means consent was denied.  A value of nil means the user did not provide a response, and this includes if th user may have dismissed the dialog without indicating one way or another.
 */
- (void)didPromptWithDidGrantBoolNumber:(nullable NSNumber *)didGrantBoolNumber NS_SWIFT_NAME(didPrompt(didGrantBoolNumber:));



/*!
 @method - isGrantedBool
 
 @brief A method returning a boolean indicating if consent is granted.
 
 @discussion This considers if the user previously granted consent, as well as the current definition of the Consent which may have changed since consent was last given.  This does not consider whether consent is required.  Compare with mayCalculateBool, mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)isGrantedBool;



/*!
 @method - isGrantedBoolNumber
 
 @brief A method returning a boolean indicating if consent is granted (or denied).
 
 @discussion This considers if the user previously granted consent, as well as the current definition of the Consent which may have changed since consent was last given.  This does not consider whether consent is required.  See also isGrantedBool.  Compare with mayCalculateBool, mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (nullable NSNumber *)isGrantedBoolNumber;



/*!
 @method - isGrantedDate
 
 @brief A method returning a date for when consent was granted.
 
 @discussion If isGrantedBool, then this returns responseDate.  If not, then this returns nil.
 */
- (nullable NSDate *)isGrantedDate;



/*!
 @method - mayCalculateBool
 
 @brief A method returning a boolean indicating if the app may calculate (or gather) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayKeepBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)mayCalculateBool;



/*!
 @method - mayKeepBool
 
 @brief A method returning a boolean indicating if the app may keep (or hold in memory) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else the user did not otherwise previously deny consent.  This will return true while consent is not known, as long as the previous response did not deny consent.  This includes when the definition for consent has changed and the user previously granted consent.  Compare with mayCalculateBool, mayPersistBool, and mayShareBool.
 */
- (BOOL)mayKeepBool;



/*!
 @method - mayPersistBool
 
 @brief A method returning a boolean indicating if the app may persist (or retain in persistent storage) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayCalculateBool, mayKeepBool, and mayShareBool.
 */
- (BOOL)mayPersistBool;



/*!
 @method - mayShareBool
 
 @brief A method returning a boolean indicating if the app may share (internally or externally) data which may be subject to consent.
 
 @discussion Returns true if consent is not required or else is granted.  This will immediately return false if the consent requirement(s) have been updated but not an updated consent response has not yet been given from the user.  Compare with mayCalculateBool, mayKeepBool, and mayPersistBool.
 */
- (BOOL)mayShareBool;



/*!
 @method - shouldPromptBool
 
 @brief A method returning a boolean indicating if a prompt for consent should be made.
 */
- (BOOL)shouldPromptBool;



/*!
 @method - willPrompt
 
 @brief A method which may be used to notify that a prompt for consent will be made.
 
 @discussion Optional.  This method can be used if you want to ensure that the prompt for consent will not be made again, even when a subsequent call to didPromptWithDidGrantBoolNumber: is never made, such as in the case of an unexpected termination.  If you call didPromptWithDidGrantBoolNumber: whenever the prompt is dismissed, even if the user did not give a response, then this method does not need to be called.
 */
- (void)willPrompt NS_SWIFT_NAME(willPrompt());



#pragma mark - LIFECYCLE



/*!
 @method + consentWithMasterBool
 
 @brief Returns a new instance of KVAConsent.
 
 @discussion Internal.
 
 @param masterBool A boolean indicating that this consent object is a master consent object, as opposed to an immutable copy.
 */
+ (nonnull instancetype)consentWithMasterBool:(BOOL)masterBool NS_SWIFT_NAME(init(masterBool:));



/*!
 @method + fromObject:
 
 @brief A method to return an instance of consent from another object.
 
 @discussion Internal.
 
 @return An instance of consent.  A value of nil will be returned if the object is not recognized.
 */
+ (nullable instancetype)fromObject:(nullable id)fromObject NS_SWIFT_NAME(init(fromObject:));



/*!
 @method - invalidate
 
 @brief A method which invalidates the instance.
 
 @discussion Internal.  This prevents timers from firing and callbacks from being made.  The receiver should not be used following a call to this method.
 */
- (void)invalidate;



@end



