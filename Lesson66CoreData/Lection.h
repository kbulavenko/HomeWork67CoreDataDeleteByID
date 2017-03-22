//
//  Lection.h
//  Lesson66CoreData
//
//  Created by Z on 21.03.17.
//  Copyright © 2017 Константин В. Булавенко. All rights reserved.
//

#ifndef Lection_h
#define Lection_h


//
//  main.m
//  Lesson66CoreData
//
//  Created by Константин В. Булавенко on 16.03.17.
//  Copyright © 2017 Константин В. Булавенко. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyDataController.h"
#import "MyManagedObjectProductMO.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        // NSLog(@"Hello, World!");
        
        MyDataController    *MDC      = [[MyDataController alloc] init];
        
        //  Создание объекта продукт на основании EntityDescription (создали его визуально)
        
        for (int i = 1; i < 2; i++)
        {
            
            
            MyManagedObjectProductMO    *product   =
            [NSEntityDescription
             insertNewObjectForEntityForName:@"Product"
             inManagedObjectContext: [MDC managedObjectContext]
             ];
            
            // Заполнение полями
            
            [product setName:   @"Snickers"];
            [product setPrice:   @12.5];
            [product setWeight:   @45];
            //[product setName:   @"Snickers"];
            
            
            [product setName:  [NSString stringWithFormat: @"Mars-%i",i]];
            [product setPrice:   @(7.9 + 5 * i)];
            [product setWeight:   @(100+5*i)];
            //
            //        [product setName:   @"ChocoBoom"];
            //        [product setPrice:   @12.2];
            //        [product setWeight:   @35];
            //
            
            //        [product setName:   @"Alenka"];
            //        [product setPrice:   @24.6];
            //        [product setWeight:   @155];
            //
            
            // ----- Сохранение объекта "Продукт" ---------------------
            NSError			*error		= nil;
            if ([[MDC managedObjectContext] save : nil] == false)   //  save   to DB
            {
                NSLog(@"Error saving context: %@\n%@",
                      [error localizedDescription], [error userInfo]);
            }
            else
            {
                NSLog(@"Saved OK");
            }
            
        }
        // Lesson 67
        //Выборка всех сникерсов
        
        // Создаем запрос
        NSFetchRequest    *request   = [NSFetchRequest fetchRequestWithEntityName: @"Product"];
        // Содержит критерии выборки из БД
        /*
         Конструкторы :
         + (instancetype)fetchRequestWithEntityName:(NSString*)entityName NS_AVAILABLE(10_7, 4_0);
         
         - (instancetype)init NS_DESIGNATED_INITIALIZER;
         - (instancetype)initWithEntityName:(NSString*)entityName NS_AVAILABLE(10_7, 4_0);
         
         
         
         //  Массивы сущностей
         @property (nullable, nonatomic, strong) NSEntityDescription *entity;
         @property (nullable, nonatomic, readonly, strong) NSString *entityName NS_AVAILABLE(10_7, 4_0);
         
         
         
         @property (nullable, nonatomic, strong) NSPredicate *predicate;   - позволяет задать условие для поиска, (выборки данных),  аналог WHERE
         
         // Parse predicateFormat and return an appropriate predicate
         + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat argumentArray:(nullable NSArray *)arguments;
         + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat, ...;
         + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat arguments:(va_list)argList;
         
         
         
         
         @property (nullable, nonatomic, strong) NSArray<NSSortDescriptor *> *sortDescriptors;
         
         Specifies a collection of either NSPropertyDescriptions or NSString property names that should be fetched. The collection may represent attributes, to-one relationships, or NSExpressionDescription.  If NSDictionaryResultType is set, the results of the fetch will be dictionaries containing key/value pairs where the key is the name of the specified property description.  If NSManagedObjectResultType is set, then NSExpressionDescription cannot be used, and the results are managed object faults partially pre-populated with the named properties
         //   @property (nullable, nonatomic, copy) NSArray *propertiesToFetch NS_AVAILABLE(10_6, 3_0);
         // указываем какие столбцы мы хотим выбрать
         
         
         
         Returns/sets if the fetch request returns only distinct values for the fields specified by propertiesToFetch. This value is only used for NSDictionaryResultType. Defaults to NO.
         //   @property (nonatomic) BOOL returnsDistinctResults NS_AVAILABLE(10_6, 3_0);  // Удаляются строки с повторяющимися значениями  если true
         
         Specifies the way in which data should be grouped before a select statement is run in an SQL database.
         Values passed to propertiesToGroupBy must be NSPropertyDescriptions, NSExpressionDescriptions, or keypath strings; keypaths can not contain
         any to-many steps.
         If GROUP BY is used, then you must set the resultsType to NSDictionaryResultsType, and the SELECT values must be literals, aggregates,
         or columns specified in the GROUP BY. Aggregates will operate on the groups specified in the GROUP BY rather than the whole table.
         // @property (nullable, nonatomic, copy) NSArray *propertiesToGroupBy NS_AVAILABLE(10_7,  5_0);
         // Названия столбцов по которыма мы будем группировать
         
         
         
         
         
         
         @property (nonatomic) NSUInteger fetchOffset NS_AVAILABLE(10_6, 3_0);    // Смещение для ограничения
         @property (nonatomic) NSUInteger fetchLimit;   // ограничить количеством строк
         
         
         @property (nullable, nonatomic, strong) NSArray<NSPersistentStore *> *affectedStores;
         
         Returns/sets the result type of the fetch request (the instance type of objects returned from executing the request.)  Setting the value to NSManagedObjectIDResultType will demote any sort orderings to "best effort" hints if property values are not included in the request.  Defaults to NSManagedObjectResultType.
         */
        // @property (nonatomic) NSFetchRequestResultType resultType NS_AVAILABLE(10_5,3_0);
        
        
        /* Returns/sets if the fetch request includes subentities.  If set to NO, the request will fetch objects of exactly the entity type of the request;  if set to YES, the request will include all subentities of the entity for the request.  Defaults to YES.
         */
        // @property (nonatomic) BOOL includesSubentities NS_AVAILABLE(10_5,3_0);
        
        
        /* Returns/sets if, when the fetch is executed, property data is obtained from the persistent store.  If the value is set to NO, the request will not obtain property information, but only information to identify each object (used to create NSManagedObjectIDs.)  If managed objects for these IDs are later faulted (as a result attempting to access property values), they will incur subsequent access to the persistent store to obtain their property values.  Defaults to YES.
         */
        //  @property (nonatomic) BOOL includesPropertyValues NS_AVAILABLE(10_5,3_0);
        
        
        /* Returns/sets if the objects resulting from a fetch request are faults.  If the value is set to NO, the returned objects are pre-populated with their property values (making them fully-faulted objects, which will immediately return NO if sent the -isFault message.)  If the value is set to YES, the returned objects are not pre-populated (and will receive a -didFireFault message when the properties are accessed the first time.)  This setting is not utilized if the result type of the request is NSManagedObjectIDResultType, as object IDs do not have property values.  Defaults to YES.
         */
        //  @property (nonatomic) BOOL returnsObjectsAsFaults NS_AVAILABLE(10_5,3_0);
        
        /* Returns/sets an array of relationship keypaths to prefetch along with the entity for the request.  The array contains keypath strings in NSKeyValueCoding notation, as you would normally use with valueForKeyPath.  (Prefetching allows Core Data to obtain developer-specified related objects in a single fetch (per entity), rather than incurring subsequent access to the store for each individual record as their faults are tripped.)  Defaults to an empty array (no prefetching.)
         */
        // @property (nullable, nonatomic, copy) NSArray<NSString *> *relationshipKeyPathsForPrefetching NS_AVAILABLE(10_5,3_0);
        
        
        /* Results accommodate the currently unsaved changes in the NSManagedObjectContext.  When disabled, the fetch request skips checking unsaved changes and only returns objects that matched the predicate in the persistent store.  Defaults to YES.
         */
        //   @property (nonatomic) BOOL includesPendingChanges NS_AVAILABLE(10_6, 3_0);
        
        /* Returns/sets if the fetch request returns only distinct values for the fields specified by propertiesToFetch. This value is only used for NSDictionaryResultType. Defaults to NO. */
        //   @property (nonatomic) BOOL returnsDistinctResults NS_AVAILABLE(10_6, 3_0);
        
        /* Specifies a collection of either NSPropertyDescriptions or NSString property names that should be fetched. The collection may represent attributes, to-one relationships, or NSExpressionDescription.  If NSDictionaryResultType is set, the results of the fetch will be dictionaries containing key/value pairs where the key is the name of the specified property description.  If NSManagedObjectResultType is set, then NSExpressionDescription cannot be used, and the results are managed object faults partially pre-populated with the named properties */
        //   @property (nullable, nonatomic, copy) NSArray *propertiesToFetch NS_AVAILABLE(10_6, 3_0);
        
        /* Allows you to specify an offset at which rows will begin being returned.  Effectively, the request will skip over 'offset' number of matching entries.  For example, given a fetch which would normally return a, b, c, and d, specifying an offset of 1 will return b, c, and d and an offset of 4  will return an empty array. Offsets are ignored in nested requests such as subqueries.  Default value is 0.  */
        //  @property (nonatomic) NSUInteger fetchOffset NS_AVAILABLE(10_6, 3_0);
        
        /* This breaks the result set into batches.  The entire request will be evaluated, and the identities of all matching objects will be recorded, but no more than batchSize objects' data will be fetched from the persistent store at a time.  The array returned from executing the request will be a subclass that transparently faults batches on demand.  For purposes of thread safety, the returned array proxy is owned by the NSManagedObjectContext the request is executed against, and should be treated as if it were a managed object registered with that context.  A batch size of 0 is treated as infinite, which disables the batch faulting behavior.  The default is 0. */
        
        // @property (nonatomic) NSUInteger fetchBatchSize NS_AVAILABLE(10_6, 3_0);
        
        // @property (nonatomic) BOOL shouldRefreshRefetchedObjects NS_AVAILABLE(10_7,  5_0);
        
        /* Specifies the way in which data should be grouped before a select statement is run in an SQL database.
         Values passed to propertiesToGroupBy must be NSPropertyDescriptions, NSExpressionDescriptions, or keypath strings; keypaths can not contain
         any to-many steps.
         If GROUP BY is used, then you must set the resultsType to NSDictionaryResultsType, and the SELECT values must be literals, aggregates,
         or columns specified in the GROUP BY. Aggregates will operate on the groups specified in the GROUP BY rather than the whole table. */
        // @property (nullable, nonatomic, copy) NSArray *propertiesToGroupBy NS_AVAILABLE(10_7,  5_0);
        
        /* Specifies a predicate that will be used to filter rows being returned by a query containing a GROUP BY. If a having predicate is
         supplied, it will be run after the GROUP BY.  Specifying a HAVING predicate requires that a GROUP BY also be specified. */
        // @property (nullable, nonatomic, strong) NSPredicate *havingPredicate NS_AVAILABLE(10_7,  5_0);
        /*
         
         */
        
#pragma mark   ____
        
#pragma mark   predicate
        
        
        NSError  *error1   = nil;
        
        NSString  *attributeName = @"name";  //  Название столбца
        NSString   *attributeValue = @"Mars%%";   // Значение для сравнения
        
        NSString  *attributeName1 = @"weight";  //  Название столбца
        int   attributeValue1 = 135;   // Значение для сравнения
        
        
        // NSPredicate   *predicate   = [NSPredicate   predicateWithFormat: @"%K=%@ AND %K=%i", attributeName, attributeValue, attributeName1, attributeValue1];
        NSPredicate   *predicate   = [NSPredicate   predicateWithFormat: @"%K like '%@'", attributeName, attributeValue];
        
        
        request.predicate  = predicate;
        
        
        
        NSArray  *results   = [[MDC managedObjectContext] executeFetchRequest: request error: &error1 ];
        
        if(!results)
        {
            NSLog(@"Error fetching Products objects: %@\n%@",
                  [error1 localizedDescription], [error1 userInfo]);
            exit(0);
        }
        
        
        
        for (int i =0; i < results.count; i++)
        {
            MyManagedObjectProductMO   *product  =
            (MyManagedObjectProductMO *) [results objectAtIndex:i];
            NSLog(@"Name : %@\tPrice :  %f\tWeight : %i", product.name, product.price.doubleValue, product.weight.intValue);
        }
        
        
        // Удаление зхаписи
        int ID;
        printf("Input ID for delete :");
        scanf("%i", &ID);
        
        
        
        NSFetchRequest   *request2   = [NSFetchRequest fetchRequestWithEntityName:@"Product"];
        
        NSError   *error2   = nil;
        
        
        
        NSArray  *results1  = [[MDC managedObjectContext]  executeFetchRequest:request2 error:&error2];
        
        
        
        //productF
        
        
        
    }
    return 0;
}


/*
 
 Lesson 66
 
 CoreData
 ----------
 
 Managed Object Model   -   Объект представляющий одну запись таблицы.
 
 Родительский класс NSManagedObject
 
 
 
 Managed Object Context  -  Объект "взаимодействующий" с БД  (берет на себя функциональность извлечения данных и их сохранения)
 
 Создаем сущность
 
 
 MyManagedObjectProductMO
 
 
 Lesson 67
 ============
 
 initializeCoreData
 -----------------
 
 NSURL					*modelURL	= [[NSBundle mainBundle] URLForResource : @"MyCoreDataModel" withExtension : @"momd"];
 
 
 
 NSManagedObjectModel	*mom		= [[NSManagedObjectModel alloc] initWithContentsOfURL : modelURL];
 Загружаем
 
 
 
 NSManagedObjectModel   - описывает структуру модели данных, которая является коллекцией сущностей,
 с которыми работает наше приложение - аналогом коллекциии сущностей является таблица в БД
 1 сущность это по сути строка в таблице бд
 
 NSManagedObjectModel   - с одержит в себе набор объектов NSEntityDescription -  каждый из которых описывает  сущность (описание таблицы),  (  MOM аналог структуры БД)
 
 Свойства
 
 @property (readonly, copy) NSDictionary<NSString *, NSEntityDescription *> *entitiesByName;
 Возвращает коллекцию имен сущностей и  описаний сущностей
 
 
 @property (strong) NSArray<NSEntityDescription *> *entities;   -  Колекция описаний сущностей
 
 @property (readonly, strong) NSArray<NSString *> *configurations;    // returns all available configuration names
 
 NSEntityDescription   -  описание "таблицы БД"
 -------------------
 @property (nullable, copy) NSString *name;     Название таблицы
 @property (strong) NSArray<__kindof NSPropertyDescription *> *properties;
 @property (readonly, copy) NSDictionary<NSString *, __kindof NSPropertyDescription *> *propertiesByName;
 
 
 
 @property (getter=isAbstract) BOOL abstract;
 @property (readonly, copy) NSDictionary<NSString *, NSEntityDescription *> *subentitiesByName;
 @property (strong) NSArray<NSEntityDescription *> *subentities;
 @property (nullable, readonly, assign) NSEntityDescription *superentity;
 
 
 
 Является коллекцией NSPropertyDescription
 NSPropertyDescription   - описывает 1 столбец  - столбец таблицы БД .
 
 
 
 NSManagedObjectModel   -  описывает БД
 
 
 NSAssert(mom != nil,  @"Error initializing Managed Object Model");
 
 //  Создание объекта NSPersistentStoreCoordinator  - это объект, который связывает хранилище (файл на диске) с моделью БД
 чтобы затем, способствовать созданию объекта NSManagedObjectContext  - мостик между моделью и контекстом
 
 
 NSPersistentStoreCoordinator	*psc	= [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel : mom];
 
 
 //  Создание объекта NSManagedObjectContext  - главный объект, с помощью которого происходит взаимодействие с базой данных
 (аналог СУБД)
 
 NSManagedObjectContext			*moc	= [[NSManagedObjectContext alloc] initWithConcurrencyType : NSMainQueueConcurrencyType];
 [moc setPersistentStoreCoordinator : psc];
 
 [self setManagedObjectContext : moc];
 
 NSFileManager			*fileManager	= [NSFileManager defaultManager];
 
 // Получение пути к БД
 
 
 //  Получение пути к Документам
 NSURL					*documentsURL	= [[fileManager URLsForDirectory : NSDocumentDirectory inDomains : NSUserDomainMask] lastObject];
 // добавить имя базы
 NSURL					*storeURL		= [documentsURL URLByAppendingPathComponent : @"DataModel.sqlite"];
 
 
 
 
 dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
 ^(void)
 {
 
 //   Открываем во вторичном потоке так как доступ к базе может быть долог и это вызовет снижение отзывчивости интерфейса
 
 NSLog(@"Hello World!");
 NSError							*error	= nil;
 //  Извлекаем NSPersistentStoreCoordinator (см выше)  из managedObjectContext
 
 NSPersistentStoreCoordinator	*psc	= [[self managedObjectContext] persistentStoreCoordinator];
 
 NSPersistentStore   -  Хранилище  по сути сама БД  - может быть не только SQLITE
 
 
 NSPersistentStore				*store	=
 [psc addPersistentStoreWithType : NSSQLiteStoreType configuration : nil
 URL : storeURL options : options nil error : &error];
 
 NSAssert(store != nil, @"Error initializing PSC: %@\n%@", [error localizedDescription], [error userInfo]);
 });
 }
 
 
 
 NSFetchRequest - Запрос на выборку данных
 -----------------------------------------
 
 + (instancetype)fetchRequestWithEntityName:(NSString *)entityName;
 - (instancetype)initWithEntityName:(NSString *)entityName;
 @property(nonatomic, readonly, strong) NSString *entityName;
 @property(nonatomic, strong) NSEntityDescription *entity;
 
 @property(nonatomic) NSUInteger fetchOffset;
 @property(nonatomic) NSUInteger fetchLimit;
 
 @property(nonatomic, copy) NSArray *propertiesToFetch;
 @property(nonatomic) BOOL returnsDistinctResults;
 
 @property(nonatomic, copy) NSArray *propertiesToGroupBy;
 
 @property(nonatomic, strong) NSPredicate *predicate;
 
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



#endif /* Lection_h */
