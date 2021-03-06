//
//  GDAppCrashHandle.h
//  Swizzling
//
//  Created by moqing on 2018/2/24.
//  Copyright © 2018年 guoda. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NSObject+Swizzling.h"
//一下类是category
#import "NSMutableArray+Swizzling.h"
#import "NSObject+AvoidCrash.h"
#import "NSArray+Swizzling.h"
#import "NSDictionary+Swizzling.h"
#import "NSMutableDictionary+Swizzling.h"
#import "NSString+Swizzling.h"
#import "NSMutableString+Swizzling.h"
#import "NSAttributedString+Swizzling.h"
#import "NSMutableAttributedString+Swizzling.h"

#define key_errorName        @"errorName"
#define key_errorReason      @"errorReason"
#define key_errorPlace       @"errorPlace"
#define key_defaultToDo      @"defaultToDo"
#define key_callStackSymbols @"callStackSymbols"
#define key_exception        @"exception"


#define AvoidCrashNotification @"AvoidCrashNotification"

#define AvoidCrashIsiOS(version) ([[UIDevice currentDevice].systemVersion floatValue] >= version)

//user can ignore below define
#define AvoidCrashDefaultReturnNil  @"AvoidCrash default is to return nil to avoid crash."
#define AvoidCrashDefaultIgnore     @"AvoidCrash default is to ignore this operation to avoid crash."

#define AvoidCrashSeparator         @"================================================================"
#define AvoidCrashSeparatorWithFlag @"========================AvoidCrash Log=========================="

//崩溃Log
#ifdef DEBUG
#define  AvoidCrashLog(...) NSLog(@"%@",[NSString stringWithFormat:__VA_ARGS__])
#else
#define AvoidCrashLog(...)
#endif


@interface GDAppCrashHandle : NSObject

//catch到崩溃信息打新出来
+ (void)noteErrorWithCustomMessage:(NSString *)defaultToLog;
+ (void)noteErrorWithException:(NSException *)exception defaultToDo:(NSString *)defaultToDo;
+ (NSString *)getMainCallStackSymbolMessageWithCallStackSymbols:(NSArray<NSString *> *)callStackSymbols;

@end
