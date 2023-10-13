#include "utils.h"
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

        template <typename T>
        std::vector<T> vectorToNapiArray(const Napi::CallbackInfo &info)
        {
            return std::vector<T>;
        }

        Napi::Object Init(Napi::Env env, Napi::Object exports)
        {
            return exports;
        }
    }
}