#include <nodeml_opencv/utils.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

namespace nodeml_opencv
{
    namespace utils
    {
        template <>
        std::vector<std::int64_t> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<std::int64_t> result;
            for (int i = 0; i < arr.Length(); i++)
            {
                result.push_back(arr.Get(i).As<Napi::Number>().Int64Value());
            }

            return result;
        }

        template <>
        std::vector<float> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<float> result;

            for (int i = 0; i < arr.Length(); i++)
            {
                result.push_back(arr.Get(i).As<Napi::Number>().FloatValue());
            }

            return result;
        }

        template <>
        std::vector<cv::Point> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<cv::Point> result;

            for (int i = 0; i < arr.Length(); i++)
            {
                auto thisArr = arr.Get(i).As<Napi::Array>();
                result.push_back(cv::Point2d(thisArr.Get(uint32_t(0)).ToNumber().DoubleValue(),thisArr.Get(uint32_t(1)).ToNumber().DoubleValue()));
            }

            return result;
        }
        template <>
        std::vector<double> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<double> result;

            for (int i = 0; i < arr.Length(); i++)
            {
                result.push_back(arr.Get(i).As<Napi::Number>().DoubleValue());
            }

            return result;
        }

        template <>
        std::vector<int> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<int> result;

            for (int i = 0; i < arr.Length(); i++)
            {
                result.push_back(arr.Get(i).As<Napi::Number>().Int32Value());
            }

            return result;
        }

        template <>
        std::vector<std::vector<int>> napiArrayToVector(const Napi::Array &arr)
        {
            std::vector<std::vector<int>> result;

            for (int i = 0; i < arr.Length(); i++)
            {
                result.push_back(napiArrayToVector<int>(arr.Get(i).As<Napi::Array>()));
            }

            return result;
        }

        template <typename T>
        std::vector<T> vectorToNapiArray(const Napi::CallbackInfo &info)
        {
            return std::vector<T>;
        }

        template <>
        Napi::Array vectorToNapiArray(Napi::Env env, std::vector<cv::Point> vec)
        {
            auto arr = Napi::Array::New(env, vec.size());

            for (auto i = 0; i < vec.size(); i++)
            {
                auto current = vec.at(i);
                auto point = Napi::Array::New(env,2);
                point.Set(uint32_t(0),current.x);
                point.Set(uint32_t(1),current.y);
                arr.Set(uint32_t(i), point);
            }

            return arr;
        }

        template <>
        Napi::Array vectorToNapiArray(Napi::Env env, std::vector<std::vector<cv::Point>> vec)
        {
            auto arr = Napi::Array::New(env, vec.size());

            for (auto i = 0; i < vec.size(); i++)
            {
                
                arr.Set(uint32_t(i), vectorToNapiArray(env,vec.at(i)));
            }

            return arr;
        }

        template <>
        Napi::Array vectorToNapiArray(Napi::Env env, std::vector<std::vector<int>> vec)
        {
            auto arr = Napi::Array::New(env, vec.size());

            for (auto i = 0; i < vec.size(); i++)
            {
                auto current = vec.at(i);
                auto point = Napi::Array::New(env,2);
                point.Set(uint32_t(0),current.at(0));
                point.Set(uint32_t(1),current.at(1));
                arr.Set(uint32_t(i), point);
            }

            return arr;
        }

        Napi::Object Init(Napi::Env env, Napi::Object exports)
        {
            return exports;
        }
    }
}