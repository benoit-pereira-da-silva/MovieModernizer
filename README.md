# MovieModernizer

Apple has dropped the QTKit support in macOS11. So if you need to convert some movies from Quicktime legacy format you can use this framework.

- **It is an Objc Cocoa Framework that allows to call in swift 2 to 4.*
- **Compliant with targets from macOS9 to macOS1X** with no restriction. 


# Carthage Compatible

Add  `github "benoit-pereira-da-silva/MovieModernizer"` to your Cartfile


[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)


# Swift 4 integration sample.

You need to create a bridging header. Refer to [ MixandMatch ](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) on developer.apple.com

## Import MovieModernizer in your Bridging header

```
#import <MovieModernizer/Modernizer.h>
```

## You can now modernize legacy QuickTime Movies


```swift

    import MovieModernizer
    
    ...

 	///  Returns true if the URL is modernizable.
    ///  Even when returning true you have no guarantee it will succeed
    /// - Parameter url: the url
    /// - Returns:  true if the URL is modernizable.
    open func canBeModernized(_ url:URL)->Bool{
        return Modernizer.canBeModernized(url)
    }


    public enum ModernizerStatus:String{
        case unknown
        case preparing
        case running
        case cancelled
        case failed
        case completedWithSuccess
        case notRequired
    }

    /// Tries to modernize
    /// - Parameters:
    ///   - sourceURL: the source URL
    ///   - destinationURL: its destination
    ///   - completionHandler: the completion handler is called with ModernizerStatus.unknown if the modernizer fails to be initialized
    /// - Returns: the modernizer
    open func modernize(_ sourceURL:URL, destinationURL:URL, completionHandler:@escaping(_ status:ModernizerStatus)->())->Modernizer?{
        if let modernizer = Modernizer(sourceURL: sourceURL, destinationURL: destinationURL){
            modernizer.modernize(completionHandler: {
                let s = modernizer.status
                if s == "QTMovieModernizerStatusPreparing"{
                    completionHandler(ModernizerStatus.preparing)
                }else if s == "QTMovieModernizerStatusRunning"{
                    completionHandler(ModernizerStatus.running)
                }else if s == "QTMovieModernizerStatusCancelled"{
                    completionHandler(ModernizerStatus.cancelled)
                }else if s == "QTMovieModernizerStatusFailed"{
                    completionHandler(ModernizerStatus.failed)
                }else if s == "QTMovieModernizerStatusCompletedWithSuccess"{
                    completionHandler(ModernizerStatus.completedWithSuccess)
                }else if s == "QTMovieModernizerStatusNotRequired"{
                    completionHandler(ModernizerStatus.notRequired)
                }else{
                    completionHandler(ModernizerStatus.unknown)
                }
            })
            return modernizer
        }else{
            completionHandler(ModernizerStatus.unknown)
        }
        return nil
    }


```

