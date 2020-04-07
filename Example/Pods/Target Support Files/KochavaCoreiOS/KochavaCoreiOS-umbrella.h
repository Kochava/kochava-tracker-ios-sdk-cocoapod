#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "KochavaCore.h"
#import "KochavaEvent.h"
#import "KVAAsForContextObjectProtocol.h"
#import "KVAConfigureWithObjectProtocol.h"
#import "KVAConsent.h"
#import "KVAContext.h"
#import "KVACoreProduct.h"
#import "KVAFromObjectProtocol.h"
#import "KVALog.h"
#import "KVALogLevel.h"
#import "KVAPartner.h"
#import "KVAProduct.h"
#import "KVASendEventFuncProvider.h"
#import "KVASharedPropertyProvider.h"
#import "KVASystem.h"

FOUNDATION_EXPORT double KochavaCoreiOSVersionNumber;
FOUNDATION_EXPORT const unsigned char KochavaCoreiOSVersionString[];

