//
//  BusinessesRepository.h
//  Business Finder
//
//  Created by Michael Johnson on 8/2/16.
//  Copyright © 2016 Michael Johnson. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "FourSquareGateway.h"
@class Business;
@class FourSquareGateway;
@class LocationGateway;

@interface BusinessesRepository : NSObject
@property (readonly) NSArray<Business *> *businesses;
@property (strong, nonatomic) FourSquareGateway *fourSquareGateway;
@property (nonatomic, readonly) double latitude;
@property (nonatomic, readonly) double longitude;
@property (strong, nonatomic) LocationGateway *locationGateway;
//-(void) initializeLocationGatewayOnCurrentThread;
-(void)updateBusinessesAndCallBlock: (void (^)(void)) block;
@end