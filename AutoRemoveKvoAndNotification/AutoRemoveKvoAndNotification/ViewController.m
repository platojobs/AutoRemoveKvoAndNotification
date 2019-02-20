//
//  ViewController.m
//  AutoRemoveKvoAndNotification
//
//  Created by PlatoJobs on 2019/2/20.
//  Copyright © 2019 David. All rights reserved.
//

#import "ViewController.h"
#import "NSObject+AutoRemoveKVONotification.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addObserverForKeyPath:NSStringFromSelector(@selector(contentOffset)) block:^(__weak id obj, id oldValue, id newValue) {
        NSLog(@"old value:%@ new value:%@", NSStringFromCGPoint([oldValue CGPointValue]), NSStringFromCGPoint([newValue CGPointValue]));
    }];
    [self addNotificationForName:UIApplicationWillEnterForegroundNotification block:^(NSNotification *notification) {
        NSLog(@"will enter forground");
    }];
    
    
    
    // Do any additional setup after loading the view, typically from a nib.
}


@end
