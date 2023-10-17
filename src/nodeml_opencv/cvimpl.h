#pragma once

#include <napi.h>

namespace nodeml_opencv
{
    namespace cvimpl
    {
        Napi::Value imread(const Napi::CallbackInfo &info);

        Napi::Value imwrite(const Napi::CallbackInfo &info);

        Napi::Value cvtColor(const Napi::CallbackInfo &info);

        Napi::Value resize(const Napi::CallbackInfo &info);

        Napi::Value findContours(const Napi::CallbackInfo &info);

        Napi::Value approxPolyDP(const Napi::CallbackInfo &info);

        Napi::Value arcLength(const Napi::CallbackInfo &info);

            Napi::Object Init(Napi::Env env, Napi::Object exports);
    }
}
