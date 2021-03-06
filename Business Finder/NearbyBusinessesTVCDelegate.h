//
//  NearbyBusinessesTVCDelegate.h
//  Business Finder
//
//  Created by Michael Johnson on 9/24/16.
//  Copyright © 2016 Michael Johnson. All rights reserved.
//

#import <Foundation/Foundation.h>
@class NearbyBusinessesTableViewController;
#import "NearbyBusinessesDataSource.h"

@interface NearbyBusinessesTVCDelegate : NSObject<NearbyBusinessesDataSourceDelegate>
-(void)startInitialLoad;
@property (strong, nonatomic) UIRefreshControl *refreshControl;
// This property is weak because `NearbyBusinessesTableViewController` maintains a strong
// reference to its `NearbyBusinessesTVCDelegate`, and we want to avoid a retain cycle.
@property (weak, nonatomic) NearbyBusinessesTableViewController* nearbyBusinessesTableViewController;
@property (strong, nonatomic) NearbyBusinessesDataSource *dataSource;
@end
