#pragma once

#include <napi.h>

namespace nodeml_opencv
{
    namespace utils
    {
        template <typename T>
        std::vector<T> napiArrayToVector(const Napi::Array &arr);

        template <typename T>
        std::vector<T> vectorToNapiArray(const Napi::CallbackInfo &info);

        Napi::Object Init(Napi::Env env, Napi::Object exports);
    }
}
