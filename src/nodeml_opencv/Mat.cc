#include <nodeml_opencv/Mat.h>
#include <opencv2/core.hpp>
#include "Mat.h"
namespace nodeml_opencv
{

	Napi::FunctionReference Mat::constructor;

	Napi::Object Mat::Init(Napi::Env env, Napi::Object exports)
	{
		auto func = DefineClass(env, "Mat", {Mat::InstanceAccessor("shape", &Mat::Shape, nullptr), Mat::InstanceMethod("clone", &Mat::Clone), Mat::InstanceMethod("toArray", &Mat::ToArray)});

		constructor = Napi::Persistent(func);
		constructor.SuppressDestruct();
		exports.Set("Mat", func);
		return exports;
	}

	Mat::Mat(const Napi::CallbackInfo &info) : ObjectWrap(info)
	{
		auto isTyped = info[0].IsTypedArray();
		auto offset = isTyped ? 1 : 0;

		auto width = info[0 + offset].ToNumber().Int32Value();
		auto height = info[1 + offset].ToNumber().Int32Value();
		auto channels = info[2 + offset].ToNumber().Int32Value();
		auto type = CV_8UC(channels);

		mat = cv::Mat(height,width, type);

		if (isTyped)
		{
			auto data = info[0].As<Napi::TypedArrayOf<uint8_t>>();

			auto env = info.Env();

			memcpy(mat.data, data.Data(), sizeof(uint8_t) * data.ElementLength());
		}
	}

	Napi::Value Mat::Clone(const Napi::CallbackInfo &info)
	{
		try
		{
			return Mat::FromCv2Mat(info.Env(), mat.clone());
		}
		catch (const std::exception &e)
		{
			throw Napi::Error::New(info.Env(), e.what());
		}
	}

	Napi::Value Mat::ToArray(const Napi::CallbackInfo &info)
	{
		try
		{
			auto env = info.Env();

			Napi::EscapableHandleScope scope(env);
			assert(mat.isContinuous());
			auto typed_array = Napi::TypedArrayOf<uint8_t>::New(env, mat.total() * mat.channels());
			memcpy(typed_array.Data(), mat.data, sizeof(uint8_t) * mat.total() * mat.channels());
			return scope.Escape(typed_array);
		}
		catch (const std::exception &e)
		{
			throw Napi::Error::New(info.Env(), e.what());
		}
	}

	Napi::Value Mat::Shape(const Napi::CallbackInfo &info)
	{
		auto env = info.Env();

		auto arr = Napi::Array::New(env, 2);
		auto size = mat.size();
		arr.Set(uint32_t(0), mat.channels());
		arr.Set(uint32_t(1), size.width);
		arr.Set(uint32_t(2), size.height);
		return arr;
	}

	Napi::Value Mat::toString(const Napi::CallbackInfo &info)
	{
		return Napi::String::New(info.Env(), "YO");
	}

	Napi::Value Mat::GetSection(const Napi::CallbackInfo &info)
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

	Napi::Object Mat::FromCv2Mat(Napi::Env env, cv::Mat &cvMat)
	{
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
	}
	Mat *Mat::FromObject(Napi::Value value)
	{
		return Napi::ObjectWrap<Mat>::Unwrap(value.ToObject());
	}
	Napi::Value Mat::FromTypedArray(const Napi::CallbackInfo &info)
	{
		return Napi::Value();
	}
}