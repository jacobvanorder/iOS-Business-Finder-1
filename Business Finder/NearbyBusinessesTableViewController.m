//
//  NearbyBusinessesTableViewController.m
//  Business Finder
//
//  Created by Michael Johnson on 8/1/16.
//  Copyright © 2016 Michael Johnson. All rights reserved.
//

#import "NearbyBusinessesTableViewController.h"
#import "Business.h"
#import "LocationGateway.h"
#import "Controller.h"

@interface NearbyBusinessesTableViewController ()
@end

@implementation NearbyBusinessesTableViewController

-(instancetype)init {
    self = [super init];
    if (self) {
        _loadSemaphore = dispatch_semaphore_create(0);
        dispatch_semaphore_signal(_loadSemaphore);
        _dataSource = [NearbyBusinessesDataSource new];
        _controller = [Controller new];
    }
    return self;
}

-(instancetype)initWithDataSource:(NearbyBusinessesDataSource *)dataSource {
    self = [super init];
    if (self) {
        _loadSemaphore = dispatch_semaphore_create(0);
        dispatch_semaphore_signal(_loadSemaphore);
        _dataSource = dataSource;
        _controller = [Controller new];
    }
    return self;
}

-(instancetype)initWithDataSource:(NearbyBusinessesDataSource *)dataSource controller: (Controller *) controller {
    self = [super init];
    if (self) {
        _loadSemaphore = dispatch_semaphore_create(0);
        dispatch_semaphore_signal(_loadSemaphore);
        _dataSource = dataSource;
        _controller = controller;
    }
    if(_dataSource == nil) {
        _dataSource = [NearbyBusinessesDataSource new];
    }
    if (_controller == nil) {
        _controller = [Controller new];
    }
    _controller.nearbyBusinessesTableViewController = self;
    return self;
}

-(instancetype)initWithCoder:(NSCoder *)aDecoder {
    self = [super initWithCoder:aDecoder];
    if (self) {
        _loadSemaphore = dispatch_semaphore_create(0);
        dispatch_semaphore_signal(_loadSemaphore);
        _dataSource = [NearbyBusinessesDataSource new];
        _controller = [Controller new];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    [self.controller startInitialLoad];
}

-(void)nearbyBusinessesDataSourceDidUpdateLocationAndBusinesses {
    [self.controller nearbyBusinessesDataSourceDidUpdateLocationAndBusinesses];
}

-(void)nearbyBusinessesDataSourceDidFailWithError:(NSError *) error {
    [self.controller nearbyBusinessesDataSourceDidFailWithError:error];
}

-(void)waitForInitialLoadToComplete {
    dispatch_semaphore_wait(self.loadSemaphore,DISPATCH_TIME_FOREVER);
};
@end
