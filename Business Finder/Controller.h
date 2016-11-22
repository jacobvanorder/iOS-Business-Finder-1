//
//  Controller.h
//  Business Finder
//
//  Created by Michael Johnson on 9/24/16.
//  Copyright © 2016 Michael Johnson. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;
@class NearbyBusinessesTableViewController;
#import "NearbyBusinessesDataSource.h"

@interface Controller : NSObject<NearbyBusinessesDataSourceDelegate>
-(void)installRefreshControlOnTableView:(UITableView *) tableView selector:(SEL)selector;
-(void)beginRefreshing;
-(void)endRefreshing;
-(void)startInitialLoad;
-(void)nearbyBusinessesDataSourceDidUpdateLocationAndBusinesses;
-(void)nearbyBusinessesDataSourceDidFailWithError:(NSError *) error;
-(void)waitForInitialLoadToComplete;
@property (strong, nonatomic) UIRefreshControl *refreshControl;
@property (weak, nonatomic) NearbyBusinessesTableViewController* nearbyBusinessesTableViewController;
@property (strong,nonatomic) NearbyBusinessesDataSource *dataSource;
@property (nonatomic, strong) dispatch_semaphore_t loadSemaphore;
@end
