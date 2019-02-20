


#### 自动removeObserver （KVO与通知）

> 自动移除observer的原理很简单，因为我们一般在dealloc方法里面做remove observer的操作。那么就hook dealloc方法就好了




```objc

// 替换dealloc方法，自动注销observer
+ (void)load
{
static dispatch_once_t onceToken;
dispatch_once(&onceToken, ^{
Method originalDealloc = class_getInstanceMethod(self, NSSelectorFromString(@"dealloc"));
Method newDealloc = class_getInstanceMethod(self, @selector(autoRemoveObserverDealloc));
method_exchangeImplementations(originalDealloc, newDealloc);
});
}

- (void)autoRemoveObserverDealloc
{
if (objc_getAssociatedObject(self, &KTKvoObserversKey) || objc_getAssociatedObject(self, &KTNotificationObserversKey)) {
[self removeAllObserverBlocks];
[self removeAllNotificationBlocks];
}
// 下面这句相当于直接调用dealloc
[self autoRemoveObserverDealloc];
}

```



