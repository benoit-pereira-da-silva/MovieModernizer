//
//  Modernizer.h
//  LvcLib
//
//  Created by Benoit Pereira da silva on 31/08/2017.
//  Copyright © 2017 Lylo Media Group. All rights reserved.
//

#import <Foundation/Foundation.h>


// Let's do what Apple refuse to do!
// Allows to access to the adapted  QTMovieModernizer API
// For video conversion
@interface Modernizer : NSObject

/*!
 @property       sourceURL
 @abstract       The source URL provided to the initWithSourceURL:destinationURL: method.
 */
@property (nonatomic, readonly, copy) NSURL * _Nonnull sourceURL;

/*!
 @property        destinationURL
 @abstract        The destination URL provided to the initWithSourceURL:destinationURL: method.
 */
@property (nonatomic, readonly, copy) NSURL * _Nonnull destinationURL;

/*!
 @property        modernizeError
 @abstract        An NSError object that indicates the error, if any, that occurred during the operation of modernizeWithCompletionHandler:.
 */
@property (atomic, readonly) NSError * _Nullable error;

/*!
 "QTMovieModernizerStatusUnknown"
 "QTMovieModernizerStatusPreparing"
 "QTMovieModernizerStatusRunning"
 "QTMovieModernizerStatusCancelled"
 "QTMovieModernizerStatusFailed"
 "QTMovieModernizerStatusCompletedWithSuccess"
 "QTMovieModernizerStatusNotRequired"
 @property        status
 @abstract        A value that indicates the current status of a modernizing operation.
 */
@property (atomic, readonly, copy) NSString* _Nonnull status;


/*!
 @method         initWithSourceURL:destinationURL:
 @abstract        Initializes an instance of Modernizer with the source and destination media files.
 @param            source
 An NSURL object that specifies a media resource.
 @param            destination
 An NSURL object that specifies the destination for the modernized result.
 @result         A Modernizer object.
 */
- (nullable Modernizer*)initWithSourceURL:(nonnull NSURL *)source destinationURL:(nonnull NSURL *)destination;


/**
 canBeModernized returns YES if the legacy API seems to be able to modernize.
 it uses [QTMovieModernizer requiresModernization:source error:&error]
 and if it encounter an error it returns NO
 @param source the source URL
 @return the ability to modernize
 */
+ (BOOL)canBeModernized:( NSURL * _Nonnull )source;

/*!
 @method         modernizeWithCompletionHandler:
 @abstract        Initiates a modernization operation to write a QuickTime movie file to the destination specified in the destinationURL property and returns.
 @discussion     This method runs the modernization operation asynchronously; the completion handler is executed when the modernization operation is complete or has failed.
 @param            handler
 The handler is a block that will be called when the modernization operation is complete or has failed. The completion status is available by inspecting the status property of the modernizer.
 */
- (void)modernizeWithCompletionHandler:(void (^_Nonnull)(void))handler;

/*!
 @method         cancel
 @abstract        Cancels a modernization operation that was previously initiated with modernizeWithCompletionHandler:.
 @discussion     This method cancels an ongoing modernization operation. Any files being created will be deleted. The completion handler provided to modernizeWithCompletionHandler: will be called unless the modernization operation has already completed.
 */
- (void)cancel;

@end
