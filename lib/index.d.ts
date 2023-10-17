
export declare class Mat {
  constructor(data: Uint8Array, width: number, height: number, channels: number)
  constructor(width: number, height: number, channels: number)
  shape: [number, number,number];

  clone: () => Mat;

  toArray: () => Uint8Array;
}

export declare function imread(path: string): Mat;

export declare function imwrite(mat: Mat, path: string): Boolean;

export declare function resize(
  mat: Mat,
  dSize: [number, number],
  mode: number
);

export declare function findContours(mat: Mat,mode: number,method: number): [number,number][][]

export declare function approxPolyDp(curve: [number,number][], epsilon: number, isClosed: boolean): [number,number][]

export declare function arcLength(curve: [number,number][],isClosed: boolean): number

export declare function cvtColor(mat: Mat,conversionCode: number, destinationChanels?: number): Mat

// Resize Modes
export declare const INTER_NEAREST: number
export declare const INTER_LINEAR: number
export declare const INTER_CUBIC: number
export declare const INTER_AREA: number
export declare const INTER_LANCZOS4: number
export declare const INTER_LINEAR_EXACT: number
export declare const INTER_NEAREST_EXACT: number
export declare const INTER_MAX: number
export declare const WARP_FILL_OUTLIERS: number
export declare const WARP_INVERSE_MAP: number

// Find Countours Modes
export declare const RETR_LIST: number
export declare const RETR_TREE: number
export declare const RETR_CCOMP: number
export declare const RETR_EXTERNAL: number
export declare const CHAIN_APPROX_NONE: number
export declare const CHAIN_APPROX_SIMPLE: number
export declare const CHAIN_APPROX_TC89_KCOS: number
export declare const CHAIN_APPROX_TC89_L1: number

// Color conversions
export declare const COLOR_BGR2BGRA: number
export declare const COLOR_RGB2RGBA: number
export declare const COLOR_BGRA2BGR: number
export declare const COLOR_RGBA2RGB: number
export declare const COLOR_BGR2RGBA: number
export declare const COLOR_RGB2BGRA: number
export declare const COLOR_RGBA2BGR: number
export declare const COLOR_BGRA2RGB: number
export declare const COLOR_BGR2RGB: number
export declare const COLOR_RGB2BGR: number
export declare const COLOR_BGRA2RGBA: number
export declare const COLOR_RGBA2BGRA: number
export declare const COLOR_BGR2GRAY: number
export declare const COLOR_RGB2GRAY: number
export declare const COLOR_GRAY2BGR: number
export declare const COLOR_GRAY2RGB: number
export declare const COLOR_GRAY2BGRA: number
export declare const COLOR_GRAY2RGBA: number
export declare const COLOR_BGRA2GRAY: number
export declare const COLOR_RGBA2GRAY: number
export declare const COLOR_BGR2BGR565: number
export declare const COLOR_RGB2BGR565: number
export declare const COLOR_BGR5652BGR: number
export declare const COLOR_BGR5652RGB: number
export declare const COLOR_BGRA2BGR565: number
export declare const COLOR_RGBA2BGR565: number
export declare const COLOR_BGR5652BGRA: number
export declare const COLOR_BGR5652RGBA: number
export declare const COLOR_GRAY2BGR565: number
export declare const COLOR_BGR5652GRAY: number
export declare const COLOR_BGR2BGR555: number
export declare const COLOR_RGB2BGR555: number
export declare const COLOR_BGR5552BGR: number
export declare const COLOR_BGR5552RGB: number
export declare const COLOR_BGRA2BGR555: number
export declare const COLOR_RGBA2BGR555: number
export declare const COLOR_BGR5552BGRA: number
export declare const COLOR_BGR5552RGBA: number
export declare const COLOR_GRAY2BGR555: number
export declare const COLOR_BGR5552GRAY: number
export declare const COLOR_BGR2XYZ: number
export declare const COLOR_RGB2XYZ: number
export declare const COLOR_XYZ2BGR: number
export declare const COLOR_XYZ2RGB: number
export declare const COLOR_BGR2YCrCb: number
export declare const COLOR_RGB2YCrCb: number
export declare const COLOR_YCrCb2BGR: number
export declare const COLOR_YCrCb2RGB: number
export declare const COLOR_BGR2HSV: number
export declare const COLOR_RGB2HSV: number
export declare const COLOR_BGR2Lab: number
export declare const COLOR_RGB2Lab: number
export declare const COLOR_BGR2Luv: number
export declare const COLOR_RGB2Luv: number
export declare const COLOR_BGR2HLS: number
export declare const COLOR_RGB2HLS: number
export declare const COLOR_HSV2BGR: number
export declare const COLOR_HSV2RGB: number
export declare const COLOR_Lab2BGR: number
export declare const COLOR_Lab2RGB: number
export declare const COLOR_Luv2BGR: number
export declare const COLOR_Luv2RGB: number
export declare const COLOR_HLS2BGR: number
export declare const COLOR_HLS2RGB: number
export declare const COLOR_BGR2HSV_FULL: number
export declare const COLOR_RGB2HSV_FULL: number
export declare const COLOR_BGR2HLS_FULL: number
export declare const COLOR_RGB2HLS_FULL: number
export declare const COLOR_HSV2BGR_FULL: number
export declare const COLOR_HSV2RGB_FULL: number
export declare const COLOR_HLS2BGR_FULL: number
export declare const COLOR_HLS2RGB_FULL: number
export declare const COLOR_LBGR2Lab: number
export declare const COLOR_LRGB2Lab: number
export declare const COLOR_LBGR2Luv: number
export declare const COLOR_LRGB2Luv: number
export declare const COLOR_Lab2LBGR: number
export declare const COLOR_Lab2LRGB: number
export declare const COLOR_Luv2LBGR: number
export declare const COLOR_Luv2LRGB: number
export declare const COLOR_BGR2YUV: number
export declare const COLOR_RGB2YUV: number
export declare const COLOR_YUV2BGR: number
export declare const COLOR_YUV2RGB: number
export declare const COLOR_YUV2RGB_NV12: number
export declare const COLOR_YUV2BGR_NV12: number
export declare const COLOR_YUV2RGB_NV21: number
export declare const COLOR_YUV2BGR_NV21: number
export declare const COLOR_YUV420sp2RGB: number
export declare const COLOR_YUV420sp2BGR: number
export declare const COLOR_YUV2RGBA_NV12: number
export declare const COLOR_YUV2BGRA_NV12: number
export declare const COLOR_YUV2RGBA_NV21: number
export declare const COLOR_YUV2BGRA_NV21: number
export declare const COLOR_YUV420sp2RGBA: number
export declare const COLOR_YUV420sp2BGRA: number
export declare const COLOR_YUV2RGB_YV12: number
export declare const COLOR_YUV2BGR_YV12: number
export declare const COLOR_YUV2RGB_IYUV: number
export declare const COLOR_YUV2BGR_IYUV: number
export declare const COLOR_YUV2RGB_I420: number
export declare const COLOR_YUV2BGR_I420: number
export declare const COLOR_YUV420p2RGB: number
export declare const COLOR_YUV420p2BGR: number
export declare const COLOR_YUV2RGBA_YV12: number
export declare const COLOR_YUV2BGRA_YV12: number
export declare const COLOR_YUV2RGBA_IYUV: number
export declare const COLOR_YUV2BGRA_IYUV: number
export declare const COLOR_YUV2RGBA_I420: number
export declare const COLOR_YUV2BGRA_I420: number
export declare const COLOR_YUV420p2RGBA: number
export declare const COLOR_YUV420p2BGRA: number
export declare const COLOR_YUV2GRAY_420: number
export declare const COLOR_YUV2GRAY_NV21: number
export declare const COLOR_YUV2GRAY_NV12: number
export declare const COLOR_YUV2GRAY_YV12: number
export declare const COLOR_YUV2GRAY_IYUV: number
export declare const COLOR_YUV2GRAY_I420: number
export declare const COLOR_YUV420sp2GRAY: number
export declare const COLOR_YUV420p2GRAY: number
export declare const COLOR_YUV2RGB_UYVY: number
export declare const COLOR_YUV2BGR_UYVY: number
export declare const COLOR_YUV2RGB_Y422: number
export declare const COLOR_YUV2BGR_Y422: number
export declare const COLOR_YUV2RGB_UYNV: number
export declare const COLOR_YUV2BGR_UYNV: number
export declare const COLOR_YUV2RGBA_UYVY: number
export declare const COLOR_YUV2BGRA_UYVY: number
export declare const COLOR_YUV2RGBA_Y422: number
export declare const COLOR_YUV2BGRA_Y422: number
export declare const COLOR_YUV2RGBA_UYNV: number
export declare const COLOR_YUV2BGRA_UYNV: number
export declare const COLOR_YUV2RGB_YUY2: number
export declare const COLOR_YUV2BGR_YUY2: number
export declare const COLOR_YUV2RGB_YVYU: number
export declare const COLOR_YUV2BGR_YVYU: number
export declare const COLOR_YUV2RGB_YUYV: number
export declare const COLOR_YUV2BGR_YUYV: number
export declare const COLOR_YUV2RGB_YUNV: number
export declare const COLOR_YUV2BGR_YUNV: number
export declare const COLOR_YUV2RGBA_YUY2: number
export declare const COLOR_YUV2BGRA_YUY2: number
export declare const COLOR_YUV2RGBA_YVYU: number
export declare const COLOR_YUV2BGRA_YVYU: number
export declare const COLOR_YUV2RGBA_YUYV: number
export declare const COLOR_YUV2BGRA_YUYV: number
export declare const COLOR_YUV2RGBA_YUNV: number
export declare const COLOR_YUV2BGRA_YUNV: number
export declare const COLOR_YUV2GRAY_UYVY: number
export declare const COLOR_YUV2GRAY_YUY2: number
export declare const COLOR_YUV2GRAY_Y422: number
export declare const COLOR_YUV2GRAY_UYNV: number
export declare const COLOR_YUV2GRAY_YVYU: number
export declare const COLOR_YUV2GRAY_YUYV: number
export declare const COLOR_YUV2GRAY_YUNV: number
export declare const COLOR_RGBA2mRGBA: number
export declare const COLOR_mRGBA2RGBA: number
export declare const COLOR_RGB2YUV_I420: number
export declare const COLOR_BGR2YUV_I420: number
export declare const COLOR_RGB2YUV_IYUV: number
export declare const COLOR_BGR2YUV_IYUV: number
export declare const COLOR_RGBA2YUV_I420: number
export declare const COLOR_BGRA2YUV_I420: number
export declare const COLOR_RGBA2YUV_IYUV: number
export declare const COLOR_BGRA2YUV_IYUV: number
export declare const COLOR_RGB2YUV_YV12: number
export declare const COLOR_BGR2YUV_YV12: number
export declare const COLOR_RGBA2YUV_YV12: number
export declare const COLOR_BGRA2YUV_YV12: number
export declare const COLOR_BayerBG2BGR: number
export declare const COLOR_BayerGB2BGR: number
export declare const COLOR_BayerRG2BGR: number
export declare const COLOR_BayerGR2BGR: number
export declare const COLOR_BayerRGGB2BGR: number
export declare const COLOR_BayerGRBG2BGR: number
export declare const COLOR_BayerBGGR2BGR: number
export declare const COLOR_BayerGBRG2BGR: number
export declare const COLOR_BayerRGGB2RGB: number
export declare const COLOR_BayerGRBG2RGB: number
export declare const COLOR_BayerBGGR2RGB: number
export declare const COLOR_BayerGBRG2RGB: number
export declare const COLOR_BayerBG2RGB: number
export declare const COLOR_BayerGB2RGB: number
export declare const COLOR_BayerRG2RGB: number
export declare const COLOR_BayerGR2RGB: number
export declare const COLOR_BayerBG2GRAY: number
export declare const COLOR_BayerGB2GRAY: number
export declare const COLOR_BayerRG2GRAY: number
export declare const COLOR_BayerGR2GRAY: number
export declare const COLOR_BayerRGGB2GRAY: number
export declare const COLOR_BayerGRBG2GRAY: number
export declare const COLOR_BayerBGGR2GRAY: number
export declare const COLOR_BayerGBRG2GRAY: number
export declare const COLOR_BayerBG2BGR_VNG: number
export declare const COLOR_BayerGB2BGR_VNG: number
export declare const COLOR_BayerRG2BGR_VNG: number
export declare const COLOR_BayerGR2BGR_VNG: number
export declare const COLOR_BayerRGGB2BGR_VNG: number
export declare const COLOR_BayerGRBG2BGR_VNG: number
export declare const COLOR_BayerBGGR2BGR_VNG: number
export declare const COLOR_BayerGBRG2BGR_VNG: number
export declare const COLOR_BayerRGGB2RGB_VNG: number
export declare const COLOR_BayerGRBG2RGB_VNG: number
export declare const COLOR_BayerBGGR2RGB_VNG: number
export declare const COLOR_BayerGBRG2RGB_VNG: number
export declare const COLOR_BayerBG2RGB_VNG: number
export declare const COLOR_BayerGB2RGB_VNG: number
export declare const COLOR_BayerRG2RGB_VNG: number
export declare const COLOR_BayerGR2RGB_VNG: number
export declare const COLOR_BayerBG2BGR_EA: number
export declare const COLOR_BayerGB2BGR_EA: number
export declare const COLOR_BayerRG2BGR_EA: number
export declare const COLOR_BayerGR2BGR_EA: number
export declare const COLOR_BayerRGGB2BGR_EA: number
export declare const COLOR_BayerGRBG2BGR_EA: number
export declare const COLOR_BayerBGGR2BGR_EA: number
export declare const COLOR_BayerGBRG2BGR_EA: number
export declare const COLOR_BayerRGGB2RGB_EA: number
export declare const COLOR_BayerGRBG2RGB_EA: number
export declare const COLOR_BayerBGGR2RGB_EA: number
export declare const COLOR_BayerGBRG2RGB_EA: number
export declare const COLOR_BayerBG2RGB_EA: number
export declare const COLOR_BayerGB2RGB_EA: number
export declare const COLOR_BayerRG2RGB_EA: number
export declare const COLOR_BayerGR2RGB_EA: number
export declare const COLOR_BayerBG2BGRA: number
export declare const COLOR_BayerGB2BGRA: number
export declare const COLOR_BayerRG2BGRA: number
export declare const COLOR_BayerGR2BGRA: number
export declare const COLOR_BayerRGGB2BGRA: number
export declare const COLOR_BayerGRBG2BGRA: number
export declare const COLOR_BayerBGGR2BGRA: number
export declare const COLOR_BayerGBRG2BGRA: number
export declare const COLOR_BayerRGGB2RGBA: number
export declare const COLOR_BayerGRBG2RGBA: number
export declare const COLOR_BayerBGGR2RGBA: number
export declare const COLOR_BayerGBRG2RGBA: number
export declare const COLOR_BayerBG2RGBA: number
export declare const COLOR_BayerGB2RGBA: number
export declare const COLOR_BayerRG2RGBA: number
export declare const COLOR_BayerGR2RGBA: number
export declare const COLOR_COLORCVT_MAX: number



