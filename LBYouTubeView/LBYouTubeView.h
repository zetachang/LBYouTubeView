//
//  LBYouTubeViewController.h
//  LBYouTubeViewController
//
//  Created by Laurin Brandner on 27.05.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import "LBYouTubeVideoQuality.h"

@protocol LBYouTubeViewDelegate;

@interface LBYouTubeView : UIView

@property (nonatomic, strong, readonly) MPMoviePlayerController *controller;
@property (nonatomic, unsafe_unretained) IBOutlet id <LBYouTubeViewDelegate> delegate;
@property (nonatomic) LBYouTubeVideoQuality videoQuality;

- (id)initWithYouTubeURL:(NSURL *)URL;

- (void)loadYouTubeURL:(NSURL *)URL;
- (void)loadYouTubeVideoWithID:(NSString *)videoID;
- (void)play;
- (void)stop;

@end


@protocol LBYouTubeViewDelegate <NSObject>

@optional
- (void)youTubeView:(LBYouTubeView *)youTubeView didSuccessfullyExtractYouTubeURL:(NSURL *)videoURL;
- (void)youTubeView:(LBYouTubeView *)youTubeView didStopPlayingYouTubeVideo:(MPMoviePlaybackState)state;
- (void)youTubeView:(LBYouTubeView *)youTubeView failedExtractingYouTubeURLWithError:(NSError *)error;

@end
