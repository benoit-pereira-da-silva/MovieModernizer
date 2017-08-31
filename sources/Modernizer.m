//
//  Modernizer.m
//  LvcLib
//
//  Created by Benoit Pereira da silva on 31/08/2017.
//  Copyright © 2017 Lylo Media Group. All rights reserved.
//

#import "Modernizer.h"
#import <QTKit/QTMovieModernizer.h>

@interface Modernizer(){}
@property (nonatomic,strong)QTMovieModernizer* _internalQTModernizer;
@end

@implementation Modernizer


-(nonnull NSURL*)sourceURL{
    return  self._internalQTModernizer.sourceURL;
}

-(nonnull NSURL*)destinationURL{
    return  self._internalQTModernizer.destinationURL;
}

-(nullable NSError*)error{
    return self._internalQTModernizer.error;
}


-(nonnull NSString*)status{
    if (self._internalQTModernizer.status == QTMovieModernizerStatusUnknown ){
        return @"QTMovieModernizerStatusUnknown";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusPreparing ){
        return @"QTMovieModernizerStatusPreparing";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusRunning ){
        return @"QTMovieModernizerStatusRunning";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusCancelled ){
        return @"QTMovieModernizerStatusCancelled";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusFailed ){
        return @"QTMovieModernizerStatusFailed";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusCompletedWithSuccess ){
        return @"QTMovieModernizerStatusCompletedWithSuccess";
    }else if (self._internalQTModernizer.status == QTMovieModernizerStatusNotRequired ){
        return @"QTMovieModernizerStatusNotRequired";
    }
    return @"QTMovieModernizerStatusUnknown";
}

- (nonnull id)init{
    self=[super init];
    return self;
}


- (nullable Modernizer*)initWithSourceURL:(nonnull NSURL *)source destinationURL:(nonnull NSURL *)destination{
    self=[super init];
    self._internalQTModernizer = [[QTMovieModernizer alloc] initWithSourceURL:source destinationURL:destination];
    if (self._internalQTModernizer){
        return self;
    }else{
        return nil;
    }
}


+ (BOOL)canBeModernized:( NSURL * _Nonnull )source{
    NSError* error = nil;
    BOOL result = [QTMovieModernizer requiresModernization:source error:&error];
    if (error){
        return NO;
    }else{
        return result;
    }
}

- (void)modernizeWithCompletionHandler:(void (^_Nonnull)(void))handler{
    [self._internalQTModernizer modernizeWithCompletionHandler:handler];
}

- (void)cancel{
    [self._internalQTModernizer cancel];
}

@end
