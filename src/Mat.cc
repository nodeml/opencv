#include "Mat.h"

namespace nodeml_opencv
{

	Napi::FunctionReference Mat::constructor;

	Napi::Object Mat::Init(Napi::Env env, Napi::Object exports)
	{
		auto func = DefineClass(env, "Mat", {Mat::InstanceAccessor("shape", &Mat::Shape, nullptr)});

		constructor = Napi::Persistent(func);
		constructor.SuppressDestruct();
		exports.Set("Mat", func);
		return exports;
	}

	Mat::Mat(const Napi::CallbackInfo &info) : ObjectWrap(info)
	{
		mat = cv::Mat();
	}

	Napi::Value Mat::Shape(const Napi::CallbackInfo &info)
	{
		auto env = info.Env();

		auto arr = Napi::Array::New(env, 2);
		auto size = mat.size();
		arr.Set(uint32_t(0), size.width);
		arr.Set(uint32_t(1), size.height);
		return arr;
	}

	Napi::Value Mat::toString(const Napi::CallbackInfo &info)
	{
		return Napi::String::New(info.Env(), "YO");
	}

	Napi::Object Mat::FromCv2Mat(const Napi::CallbackInfo &info, cv::Mat &cvMat)
	{
		auto env = info.Env();
		try
		{
			Napi::EscapableHandleScope scope(env);
			auto newMat = Mat::constructor.New({});
			Napi::ObjectWrap<Mat>::Unwrap(newMat)->mat = cvMat;
			return scope.Escape(newMat).ToObject();
		}
		catch (const std::exception &e)
		{
			throw Napi::Error::New(env, e.what());
		}

		return Napi::Object();
	}
}