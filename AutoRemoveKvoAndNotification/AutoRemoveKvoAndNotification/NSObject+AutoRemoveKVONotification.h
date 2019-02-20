//
//  NSObject+AutoRemoveKVONotification.h
//  AutoRemoveKvoAndNotification
//
//  Created by PlatoJobs on 2019/2/20.
//  Copyright © 2019 David. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^PJKvoBlock)(__weak id obj, id oldValue, id newValue);
typedef void (^PJNotificationBlock)(NSNotification *notification);

@interface NSObject (AutoRemoveKVONotification)

- (void)addObserverForKeyPath:(NSString *)keyPath block:(PJKvoBlock)block;
- (void)removeObserverBlocksForKeyPath:(NSString *)keyPath;
- (void)removeAllObserverBlocks;
- (void)addNotificationForName:(NSString *)name block:(PJNotificationBlock)block;
- (void)removeNotificationBlocksForName:(NSString *)name;
- (void)removeAllNotificationBlocks;

@end

NS_ASSUME_NONNULL_END
