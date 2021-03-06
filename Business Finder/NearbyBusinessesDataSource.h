//
//  NearbyBusinessesDataSource.h
//  Business Finder
//
//  Created by Michael Johnson on 8/3/16.
//  Copyright © 2016 Michael Johnson. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;
#import "BusinessesDataController.h"

@protocol NearbyBusinessesDataSourceDelegate <NSObject>
- (void) nearbyBusinessesDataSourceDidUpdateLocationAndBusinesses;
- (void) nearbyBusinessesDataSourceDidFailWithError:(NSError *)error;
@end

@interface NearbyBusinessesDataSource : NSObject <UITableViewDataSource,BusinessesDataControllerDelegate>
@property (strong,nonatomic) BusinessesDataController* businessesDataController;
@property (weak,nonatomic) id<NearbyBusinessesDataSourceDelegate> delegate;
-(void)updateBusinesses;
@end
