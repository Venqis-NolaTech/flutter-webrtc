// AudioProcessingAdapter.h

#import <Foundation/Foundation.h>

#if __has_include(<WebRTC/RTCAudioRenderer.h>)
#import <WebRTC/WebRTC.h>

@protocol ExternalAudioProcessingDelegate
- (void)audioProcessingInitializeWithSampleRate:(size_t)sampleRateHz channels:(size_t)channels;
- (void)audioProcessingProcess:(RTC_OBJC_TYPE(RTCAudioBuffer) * _Nonnull)audioBuffer;
- (void)audioProcessingRelease;
@end

@interface AudioProcessingAdapter : NSObject <RTCAudioCustomProcessingDelegate>
- (nonnull instancetype)init;
- (void)addProcessing:(id<ExternalAudioProcessingDelegate> _Nonnull)processor;
- (void)removeProcessing:(id<ExternalAudioProcessingDelegate> _Nonnull)processor;
- (void)addAudioRenderer:(nonnull id<RTCAudioRenderer>)renderer;
- (void)removeAudioRenderer:(nonnull id<RTCAudioRenderer>)renderer;
@end

#else

// Fallback vacío cuando el WebRTC de Jitsi no expone estas APIs
@protocol ExternalAudioProcessingDelegate
- (void)audioProcessingInitializeWithSampleRate:(size_t)sampleRateHz channels:(size_t)channels;
- (void)audioProcessingProcess:(void * _Nonnull)audioBuffer;
- (void)audioProcessingRelease;
@end

@interface AudioProcessingAdapter : NSObject
- (nonnull instancetype)init;
- (void)addProcessing:(id<ExternalAudioProcessingDelegate> _Nonnull)processor;
- (void)removeProcessing:(id<ExternalAudioProcessingDelegate> _Nonnull)processor;
- (void)addAudioRenderer:(id)renderer;
- (void)removeAudioRenderer:(id)renderer;
@end

#endif