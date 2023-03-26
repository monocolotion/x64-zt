#include <std_include.hpp>
#include "zonetool/s1/converter/h1/include.hpp"
#include "computeshader.hpp"

#include "zonetool/h1/assets/computeshader.hpp"

namespace zonetool::s1
{
	namespace converter::h1
	{
		namespace computeshader
		{
			zonetool::h1::ComputeShader* convert(ComputeShader* asset, ZoneMemory* mem)
			{
				auto* new_asset = mem->Alloc<zonetool::h1::ComputeShader>();

				std::memcpy(new_asset, asset, sizeof(ComputeShader));
				new_asset->name = mem->StrDup(asset->name + TECHSET_PREFIX);

				return new_asset;
			}

			void dump(ComputeShader* asset, ZoneMemory* mem)
			{
				auto* converted_asset = convert(asset, mem);
				zonetool::h1::IComputeShader::dump(converted_asset);
			}
		}
	}
}