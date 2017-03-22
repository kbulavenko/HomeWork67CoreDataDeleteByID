//
//  MyDataController.h
//  Lesson66CoreData
//
//  Created by Константин В. Булавенко on 16.03.17.
//  Copyright © 2017 Константин В. Булавенко. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <Cocoa/Cocoa.h>

@interface MyDataController : NSObject


@property  (strong)   NSManagedObjectContext *managedObjectContext;

-(void)initializeCoreData;



@end
