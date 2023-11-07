#pragma once

#include <napi.h>

namespace nodeml_opencv
{
    namespace globals
    {
        Napi::Object Init(Napi::Env env, Napi::Object exports);
    }
}
