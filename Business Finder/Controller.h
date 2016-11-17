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

@interface Controller : NSObject
-(void)installRefreshControlOnTableView:(UITableView *) tableView selector:(SEL)selector;
-(void)beginRefreshing;
-(void)endRefreshing;
-(void)startInitialLoadForNearbyBusinessesTVC: (NearbyBusinessesTableViewController *)tableViewController;
@property (strong, nonatomic) UIRefreshControl *refreshControl;
@end
