#include "cvimpl.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <nodeml_opencv/Mat.h>
#include <nodeml_opencv/utils.h>

namespace nodeml_opencv
{
    namespace cvimpl
    {
        Napi::Value imread(const Napi::CallbackInfo &info)
        {

            try
            {

                auto mat = cv::imread(info[0].ToString().Utf8Value());
                return Mat::FromCv2Mat(info.Env(), mat);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value imwrite(const Napi::CallbackInfo &info)
        {

            try
            {
                auto result = cv::imwrite(info[1].ToString().Utf8Value(), Mat::FromObject(info[0])->mat);
                return Napi::Boolean::New(info.Env(), result);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value cvtColor(const Napi::CallbackInfo &info)
        {
            try
            {
                cv::Mat result;
                cv::cvtColor(Mat::FromObject(info[0])->mat, result, info[1].ToNumber().Int32Value(), info.Length() >= 3 ? info[2].ToNumber().Int32Value() : 0);

                return Mat::FromCv2Mat(info.Env(), result);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value resize(const Napi::CallbackInfo &info)
        {

            try
            {
                auto mat = Mat::FromObject(info[0])->mat;
                auto resultingDims = utils::napiArrayToVector<int>(info[1].As<Napi::Array>());
                auto mode = info[2].ToNumber().Int32Value();

                cv::Mat out;

                cv::resize(mat, out, cv::Size(resultingDims[0], resultingDims[1]), 0.0, 0.0, mode);

                return Mat::FromCv2Mat(info.Env(), out);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value findContours(const Napi::CallbackInfo &info)
        {
            try
            {
                auto mat = Mat::FromObject(info[0])->mat;
                std::vector<std::vector<cv::Point>> result;

                cv::findContours(mat, result, info[1].ToNumber().Int32Value(), info[2].ToNumber());

                return utils::vectorToNapiArray(info.Env(), result);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value approxPolyDP(const Napi::CallbackInfo &info)
        {
            try
            {
                std::vector<cv::Point> result;
                auto contours = utils::napiArrayToVector<cv::Point>(info[0].As<Napi::Array>());
                auto epsilon = info[1].ToNumber().DoubleValue();
                auto isClosed = info[2].ToNumber().ToBoolean().Value();
                cv::approxPolyDP(contours, result, epsilon, isClosed);
                return utils::vectorToNapiArray(info.Env(), result);
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Value arcLength(const Napi::CallbackInfo &info)
        {
            try
            {
                auto curve = utils::napiArrayToVector<cv::Point>(info[0].As<Napi::Array>());

                auto isClosed = info[1].ToNumber().ToBoolean().Value();

                return Napi::Number::New(info.Env(), cv::arcLength(curve, isClosed));
            }
            catch (const std::exception &e)
            {
                throw Napi::Error::New(info.Env(), e.what());
            }
        }

        Napi::Object Init(Napi::Env env, Napi::Object exports)
        {
            exports.Set("imread", Napi::Function::New(env, imread));
            exports.Set("imwrite", Napi::Function::New(env, imwrite));
            exports.Set("resize", Napi::Function::New(env, resize));
            exports.Set("cvtColor", Napi::Function::New(env, cvtColor));
            exports.Set("findContours", Napi::Function::New(env, findContours));
            exports.Set("approxPolyDp", Napi::Function::New(env, approxPolyDP));
            exports.Set("arcLength", Napi::Function::New(env, arcLength));
            return exports;
        }
    }
}