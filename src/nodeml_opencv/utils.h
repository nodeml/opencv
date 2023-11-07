

#include <napi.h>

namespace nodeml_opencv
{
    namespace utils
    {
        template <typename T>
        std::vector<T> napiArrayToVector(const Napi::Array &arr);

        template <typename T>
        Napi::Array vectorToNapiArray(Napi::Env env, std::vector<T> vec);

        Napi::Object Init(Napi::Env env, Napi::Object exports);
    }
}
