//
//  EZMacroDefinition.h
//  <#Project name#>
//
//  Created by 卢天翊 on 2017/8/1.
//  Copyright © 2017年 卢天翊. All rights reserved.
//

#ifndef EZMacroDefinition_h
#define EZMacroDefinition_h

/* –––––––––––––––––––– Version –––––––––––––––––––– */
# pragma mark -

// Get build Verison number
#define VERSION_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

// Get system version number
#define VERSION_SYSTEM [[UIDevice currentDevice] systemVersion]

// Get build number
#define VERSION_BUILD [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]


/* –––––––––––––––––––– ReferenceTypes –––––––––––––––––––– */
# pragma mark -

// Weak self
#define TYPE_WEAK(type)  __weak typeof(type) weak##type = type;

// Strong self
#define TYPE_STRONG(type)  __strong typeof(type) strong##type = weak##type;


/* –––––––––––––––––––– SandboxDirectory –––––––––––––––––––– */
# pragma mark -

// Get sandbox document directory
#define PATH_DOUCMENT [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

// Get sandbox tmp directory
#define PATH_TMP NSTemporaryDirectory()

// Get sandbox cache directory
#define PATH_CACHE [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]


/* –––––––––––––––––––– Print –––––––––––––––––––– */
# pragma mark -

// Debug print log
#ifdef DEBUG

#define NSLog(...) NSLog(@"\nClass  : %@,\nMethod : 第%d行 %s,\nObject : %@\n\n", NSStringFromClass([self class]), __LINE__, __func__, [NSString stringWithFormat:__VA_ARGS__])

#else

#define NSLog(...)

#endif


/* –––––––––––––––––––– Screen –––––––––––––––––––– */
# pragma mark -

// Get Screen Size
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height


/* –––––––––––––––––––– Color –––––––––––––––––––– */
# pragma mark -

// Get Hex color
#define COLOR_HEX(HexColor) COLOR_HEX_ALPHA(HexColor, 1.0)

#define COLOR_HEX_ALPHA(HexColor, Alpha) [UIColor colorWithRed:((float)((HexColor & 0xFF0000) >> 16))/255.0 green:((float)((HexColor & 0xFF00) >> 8))/255.0 blue:((float)(HexColor & 0xFF))/255.0 alpha:(Alpha)]

// Get RGB color
#define COLOR_RGB(R, G, B) COLOR_RGBA(R, G, B, 1.0)

#define COLOR_RGBA(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// Get background color
#define COLOR_BACKGROUND [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

// Get random color
#define COLOR_RANDOM [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

// Get clear color
#define COLOR_CLEAR [UIColor clearColor]


/* –––––––––––––––––––– UserDefaults –––––––––––––––––––– */
# pragma mark -

// NSUserDefaults
#define USER_DEFAULTS [NSUserDefaults standardUserDefaults]
#define USER_DEFAULTS_SYNCHRONIZE [USER_DEFAULTS synchronize];


/* –––––––––––––––––––– Singleton –––––––––––––––––––– */
# pragma mark -

// Singleton interface
#define SINGLETON_FOR_INTERFACE \
\
+ (instancetype)sharedInstance;

// Singleton implementation
#define SINGLETON_FOR_IMPLEMENTATION(ClassName) \
\
static id s_##ClassName; \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
\
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
\
    s_##ClassName = [super allocWithZone:zone]; \
    }); \
    return s_##ClassName; \
} \
\
+ (instancetype)sharedInstance { \
\
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
\
    s_##ClassName = [[self alloc] init]; \
    }); \
    return s_##ClassName; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
\
    return s_##ClassName; \
} \

#endif /* EZColorMacro_h */
