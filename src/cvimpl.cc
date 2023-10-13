#include "cvimpl.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "Mat.h"
#include "utils.h"

namespace nodeml_opencv
{
    namespace cvimpl
    {
        Napi::Value imread(const Napi::CallbackInfo &info)
        {
            auto mat = cv::imread(info[0].ToString().Utf8Value());
            return Mat::FromCv2Mat(info, mat);
        }

        Napi::Value imwrite(const Napi::CallbackInfo &info)
        {
            auto result = cv::imwrite(info[1].ToString().Utf8Value(), Napi::ObjectWrap<Mat>::Unwrap(info[0].ToObject())->mat);
            return Napi::Boolean::New(info.Env(), result);
        }

        Napi::Value resize(const Napi::CallbackInfo &info)
        {
            auto mat = Napi::ObjectWrap<Mat>::Unwrap(info[0].ToObject())->mat;
            auto resultingDims = utils::napiArrayToVector<int>(info[1].As<Napi::Array>());
            auto mode = info.Length() >= 3 && info[2].IsString() ? info[2].ToString().Utf8Value() : "linear";
            auto actualMode = cv::INTER_LINEAR;

            if (mode == "area")
            {
                actualMode = cv::INTER_AREA;
            }
            else if (mode == "cubic")
            {
                actualMode = cv::INTER_CUBIC;
            }

            cv::Mat out;

            cv::resize(mat, out, cv::Size(resultingDims[0], resultingDims[1]), 0.0, 0.0, actualMode);

            return Mat::FromCv2Mat(info, out);
        }

        Napi::Object Init(Napi::Env env, Napi::Object exports)
        {
            exports.Set("imread", Napi::Function::New(env, imread));
            exports.Set("imwrite", Napi::Function::New(env, imwrite));
            exports.Set("resize", Napi::Function::New(env, resize));
            return exports;
        }
    }
}