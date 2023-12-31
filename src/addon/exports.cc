#include <napi.h>
#include <addon/utils.h>
#include <addon/Mat.h>
#include <addon/cvimpl.h>
#include <addon/globals.h>

Napi::Object InitModule(Napi::Env env, Napi::Object exports)
{
    nodeml_opencv::utils::Init(env, exports);
    nodeml_opencv::Mat::Init(env, exports);
    nodeml_opencv::cvimpl::Init(env, exports);
    nodeml_opencv::globals::Init(env,exports);
    
    return exports;
}

NODE_API_MODULE(nodeml_opencv, InitModule);