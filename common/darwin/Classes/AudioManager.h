// AudioManager.h
#import <Foundation/Foundation.h>

#if __has_include(<WebRTC/RTCAudioRenderer.h>)
#import <WebRTC/WebRTC.h>
#import "AudioProcessingAdapter.h"

@interface AudioManager : NSObject
@property(nonatomic, strong) RTCDefaultAudioProcessingModule* _Nonnull audioProcessingModule;
@property(nonatomic, strong) AudioProcessingAdapter* _Nonnull capturePostProcessingAdapter;
@property(nonatomic, strong) AudioProcessingAdapter* _Nonnull renderPreProcessingAdapter;
+ (_Nonnull instancetype)sharedInstance;
- (void)addLocalAudioRenderer:(nonnull id<RTCAudioRenderer>)renderer;
- (void)removeLocalAudioRenderer:(nonnull id<RTCAudioRenderer>)renderer;
@end

#else

@interface AudioManager : NSObject
+ (_Nonnull instancetype)sharedInstance;
- (void)addLocalAudioRenderer:(id)renderer;
- (void)removeLocalAudioRenderer:(id)renderer;
@end

#endif