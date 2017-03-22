//
//  main.m
//  Lesson66CoreData
//
//  Created by Константин В. Булавенко on 16.03.17.
//  Copyright © 2017 Константин В. Булавенко. All rights reserved.
//    https://github.com/kbulavenko/HomeWork67CoreDataDeleteByID/archive/master.zip

#import <Foundation/Foundation.h>
#import "MyDataController.h"
#import "MyManagedObjectProductMO.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
       // NSLog(@"Hello, World!");
        srand((unsigned int)time(NULL));
        MyDataController    *MDC      = [[MyDataController alloc] init];
        
        //  Создание объекта продукт на основании EntityDescription (создали его визуально)
        //  NSEntityDescription
        for (int i = 1; i < 2; i++)
        {
            MyManagedObjectProductMO    *product   =      [NSEntityDescription   insertNewObjectForEntityForName:@"Product"   inManagedObjectContext: [MDC managedObjectContext]  ];
            // Заполнение полями
            [product setName:   [NSString stringWithFormat: @"Mars-%i", rand() %1000 + i *100]];
            [product setPrice:   @(12.5 + (double)(rand() % 100)/10.0 )];
            [product setWeight:   @(20+(rand() % 10) * 5)];
            
            // ----- Сохранение объекта "Продукт" ---------------------
            NSError			*error		= nil;
            if ([[MDC managedObjectContext] save : nil] == false)   //  save   to DB
            {
                NSLog(@"Error saving context: %@\n%@",  [error localizedDescription], [error userInfo]);
            }
            else
            {
                NSLog(@"Saved OK");
            }
        }
        for (int i = 1; i < 2; i++)
        {
            MyManagedObjectProductMO    *product   =   [NSEntityDescription insertNewObjectForEntityForName:@"Product"  inManagedObjectContext: [MDC managedObjectContext]  ];
            // Заполнение полями
            [product setName:   [NSString stringWithFormat: @"Snickers"]];
            [product setPrice:   @(12.5 + (double)(rand() % 100)/10.0 )];
            [product setWeight:   @(20+(rand() % 10) * 5)];
            
            // ----- Сохранение объекта "Продукт" ---------------------
            NSError			*error		= nil;
            if ([[MDC managedObjectContext] save : nil] == false)   //  save   to DB
            {
                NSLog(@"Error saving context: %@\n%@",   [error localizedDescription], [error userInfo]);
            }
            else
            {
                NSLog(@"Saved OK");
            }
        }
        
        for (int i = 1; i < 2; i++)
        {
            MyManagedObjectProductMO    *product   = [NSEntityDescription insertNewObjectForEntityForName:@"Product" inManagedObjectContext: [MDC managedObjectContext] ];
            // Заполнение полями
            [product setName:   [NSString stringWithFormat: @"ChockoBoom"]];
            [product setPrice:   @(12.5 + (double)(rand() % 100)/10.0 )];
            [product setWeight:   @(20+(rand() % 10) * 5)];
                  // ----- Сохранение объекта "Продукт" ---------------------
            NSError			*error		= nil;
            if ([[MDC managedObjectContext] save : nil] == false)   //  save   to DB
            {
                NSLog(@"Error saving context: %@\n%@",    [error localizedDescription], [error userInfo]);
            }
            else
            {
                NSLog(@"Saved OK");
            }
            
        }
        
#pragma mark   Request
#pragma mark   ____

        
        
         // Создаем запрос
        NSFetchRequest    *request   = [NSFetchRequest fetchRequestWithEntityName: @"Product"];
   
#pragma mark   predicate begin
#pragma mark   ____
        
        
        NSError  *error1   = nil;
        
        NSString  *attributeName = @"name";  //  Название столбца
        NSString   *attributeValue = @"Mars";   // Значение для сравнения
        
        NSString  *attributeName1 = @"weight";  //  Название столбца
        int   attributeValue1 = 30;   // Значение для сравнения
        NSPredicate   *predicate   = [NSPredicate   predicateWithFormat: @"(name contains 'Mars' ) AND (weight = 35)"];
       // NSPredicate   *predicate   = [NSPredicate   predicateWithFormat: @"%K like '%@'", attributeName, attributeValue];
        //request.predicate  = predicate;
    
#pragma mark   predicate
#pragma mark   ____
        

        NSArray  *results   = [[MDC managedObjectContext] executeFetchRequest: request error: &error1 ];
        if(!results)
        {
            NSLog(@"Error fetching Products objects: %@\n%@",  [error1 localizedDescription], [error1 userInfo]);
            exit(0);
        }
        
        for (int i =0; i < results.count; i++)
        {
            MyManagedObjectProductMO   *product  =
            (MyManagedObjectProductMO *) [results objectAtIndex:i];
            
            NSString   *strID  = [[[[[product objectID] URIRepresentation]  lastPathComponent] componentsSeparatedByCharactersInSet:[[NSCharacterSet  decimalDigitCharacterSet] invertedSet]] componentsJoinedByString:@""];
            
            NSLog(@"ID: %@ Name : %@\tPrice :  %f\tWeight : %i", strID, product.name, product.price.doubleValue, product.weight.intValue);
            //NSLog(@"%@", );
            
        }

#pragma mark   deleting
#pragma mark   ____
        
        // Удаление записи
        int ID;
        printf("Input ID for delete :");
        scanf("%i", &ID);
        
        NSFetchRequest   *request2   = [NSFetchRequest fetchRequestWithEntityName:@"Product"];
        
        
        NSString    *attributeName2  = @"ObjectID";
        NSString    *attributeValue2  = [NSString stringWithFormat:@"%i", ID];
        
        
        NSPredicate   *predic2  = [NSPredicate predicateWithFormat:@"id contains %@", attributeValue2];
        
      //  request2.predicate   = predic2;
        
        
        NSError   *error2   = nil;
        NSArray  *results2  = [[MDC managedObjectContext]  executeFetchRequest: request2 error: &error2];
        if(!results2)
        {
            NSLog(@"Error fetching Products objects : %@\n%@", [error2 localizedDescription], [error2 userInfo]);
            exit(0);
        }
        
        for (NSInteger i = 0; i<results2.count; i++)
        {
            MyManagedObjectProductMO  *product  = (MyManagedObjectProductMO *) [results2 objectAtIndex:i];
            
            NSString   *strID  = [[[[[product objectID] URIRepresentation]  lastPathComponent] componentsSeparatedByCharactersInSet:[[NSCharacterSet  decimalDigitCharacterSet] invertedSet]] componentsJoinedByString:@""];
            
            
            if(strID.intValue ==  ID)
            {
                NSLog(@"Удаление");
                NSLog(@"ID: %@ Name: %@\tPrice : %f\tWeight: %i",strID, product.name, product.price.doubleValue, product.weight.intValue);
              [ [MDC managedObjectContext]  deleteObject: [[MDC managedObjectContext] objectWithID: product.objectID    ]];
                [ [MDC managedObjectContext]  deleteObject: product];
                NSError  *error3 = nil;

                if ([[MDC managedObjectContext] save : &error3] == false)   //  save   to DB
                {
                    NSLog(@"Error saving context: %@\n%@",    [error3 localizedDescription], [error3 userInfo]);
                }
                else
                {
                    NSLog(@"Saved OK");
                }
                break;
            }
        }
        
        
        
        
    }
    return 0;
}


/*
 NSPredicate
 -----------
 
 + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat, ...;
 
 Пример для конспекта :
 NSString *attributeName  = @"firstName";	// Название столбца
 NSString *attributeValue = @"Adam";		// Значение для сравнения
 NSPredicate *predicate   = [NSPredicate predicateWithFormat:
	@"%K like %@", attributeName, attributeValue];

 
 
 
 
 ###
 ---
 
 NSString *attributeName  = @"name";	// Название столбца
 NSString *attributeValue = @"Mars";	// Значение для сравнения
 NSString *attributeName1 = @"weight";
 int	 attributeValue1 = 50;
 
 NSPredicate *predicate   = [NSPredicate predicateWithFormat:
	@"%K = %@ AND %K = %i",
	attributeName, attributeValue,
	attributeName1, attributeValue1];
 
 request.predicate	= predicate;
 
 
 ============
 NSManagedObjectContext
 ----------------------
 
 - (NSArray *)executeFetchRequest:(NSFetchRequest *)request
 error:(NSError * _Nullable *)error;  // Выполняет запрос  находящиййся в объекте NSFetchRequest и возвращает массив объектов производных от NSMangedObject,   который является строками результирующей таблицы.
 
 
 
 ###
 ---
 
 NSString *attributeName  = @"name";	// Название столбца
 NSString *attributeValue = @"Mars";	// Значение для сравнения
 NSString *attributeName1 = @"weight";
 int	 attributeValue1 = 50;
 
 NSPredicate *predicate   = [NSPredicate predicateWithFormat:
	@"%K = %@ AND %K = %i",
	attributeName, attributeValue,
	attributeName1, attributeValue1];
 
 request.predicate	= predicate;
 
 
 ============
 NSManagedObjectContext
 ----------------------
 
 - (NSArray *)executeFetchRequest:(NSFetchRequest *)request
 error:(NSError * _Nullable *)error;
 
 - (__kindof NSManagedObject *)objectWithID:(NSManagedObjectID *)objectID;
 - (void)insertObject:(NSManagedObject *)object;
 - (void)deleteObject:(NSManagedObject *)object;
 - (void)refreshObject:(NSManagedObject *)object
 mergeChanges:(BOOL)flag;
 
 
 @interface NSManagedObjectID : NSObject <NSCopying> {
 }
 
 @property (readonly, strong) NSEntityDescription *entity;    // entity for the object identified by an ID   - Сущность для этого объекта
 @property (nullable, readonly, weak) NSPersistentStore *persistentStore;    // persistent store that fetched the object identified by an ID
 
 @property (getter=isTemporaryID, readonly) BOOL temporaryID;    // indicates whether or not this ID will be replaced later, such as after a save operation (temporary IDs are assigned to newly inserted objects and replaced with permanent IDs when an object is written to a persistent store); most IDs return NO
 
 - (NSURL *)URIRepresentation;    // URI which provides an archivable reference to the object which this ID refers
 

 
 
 Доделать пример  удаление
 
 
 
 IOS Приложение работает со списком продуктов   
 Выводить список продуктов в UITableView   
 Добавлять   
 продукт
 Удалять  
 Редактировать продукт  
 
 Через диалоговые окна  
 
 
 
 
 
 */
