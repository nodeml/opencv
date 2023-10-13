#include <napi.h>
#include "utils.h"
#include "Mat.h"
#include "cvimpl.h"

Napi::Object InitModule(Napi::Env env, Napi::Object exports)
{
    nodeml_opencv::utils::Init(env, exports);
    nodeml_opencv::Mat::Init(env, exports);
    nodeml_opencv::cvimpl::Init(env, exports);

    return exports;
}

NODE_API_MODULE(nodeml_opencv, InitModule);