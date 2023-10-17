#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <napi.h>

namespace nodeml_opencv
{
    class Mat : public Napi::ObjectWrap<Mat>
    {

    public:
        static Napi::FunctionReference constructor;

        cv::Mat mat;

        static Napi::Object Init(Napi::Env env, Napi::Object exports);

        Mat(const Napi::CallbackInfo &info);

        Napi::Value Clone(const Napi::CallbackInfo &info);

        Napi::Value ToArray(const Napi::CallbackInfo &info);

        Napi::Value Shape(const Napi::CallbackInfo &info);

        Napi::Value toString(const Napi::CallbackInfo &info);

        Napi::Value GetSection(const Napi::CallbackInfo &info);

        static Napi::Object FromCv2Mat(Napi::Env env, cv::Mat &cvMat);

        static Mat *FromObject(Napi::Value value);

        static Napi::Value FromTypedArray(const Napi::CallbackInfo &info);
    };
}