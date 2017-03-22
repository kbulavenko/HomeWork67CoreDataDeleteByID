//
//  MyManagedObjectProductMO+CoreDataProperties.h
//  Lesson66CoreData
//
//  Created by Константин В. Булавенко on 16.03.17.
//  Copyright © 2017 Константин В. Булавенко. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "MyManagedObjectProductMO.h"

NS_ASSUME_NONNULL_BEGIN

@interface MyManagedObjectProductMO (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSNumber *price;
@property (nullable, nonatomic, retain) NSNumber *weight;

@end

NS_ASSUME_NONNULL_END
