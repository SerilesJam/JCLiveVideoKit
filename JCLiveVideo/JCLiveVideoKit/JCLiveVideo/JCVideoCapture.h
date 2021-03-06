//
//  JCVideoCapture.h
//  JCLiveVideo
//
//  Created by 贾淼 on 16/6/25.
//  Copyright © 2016年 Jam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

//采样分辨率
typedef NS_ENUM(NSUInteger, JCCaptureVideoQuality) {
    JCCaptureVideo640x480,
    JCCaptureVideo960x540,
    JCCaptureVideo1280x720
};

//摄像头位置
typedef NS_ENUM(NSInteger, JCVideoCaptureDevicePosition) {
    JCVideoCaptureDevicePositionBack    = 1,
    JCVideoCaptureDevicePositionFront   = 2
};

//视频采集属性
@interface JCVideoCaptureProperty : NSObject

@property (nonatomic, assign) JCCaptureVideoQuality videoQualityLevel;
@property (nonatomic, assign) JCVideoCaptureDevicePosition videoDevicePosition;
//采集帧率 单位帧
@property (nonatomic, assign) NSInteger videoCaptureFrameRate;

////如果JCCaptureVideoQuality为640*480需要添加一个剪裁滤镜否则图像会变形
@property (nonatomic, assign) BOOL isNeedClip;

+ (JCVideoCaptureProperty *)defaultCaptureProperty;

@end

typedef void(^cameraCaptureOriginDataBlock)(CVImageBufferRef sampleBufferRef);

@interface JCVideoCapture : NSObject

- (instancetype)initWithJCCaptureVideoProperty:(JCVideoCaptureProperty *)captureProperty;

//开启美颜效果默认开启
@property (nonatomic, assign) BOOL beautyFace;

- (void)startRunning;
- (void)stopRunning;

- (void)embedPreviewInView:(UIView *)aView;

//获取原始视频流
- (void)carmeraScanOriginBlock:(cameraCaptureOriginDataBlock)cameraCaptureOriginBlock;

//前后摄像头切换
- (void)swapFrontAndBackCameras;

@end
