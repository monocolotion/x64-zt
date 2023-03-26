#include <std_include.hpp>
#include "zonetool/iw6/converter/h1/include.hpp"
#include "xmodel.hpp"

#include "zonetool/h1/assets/xmodel.hpp"

#include "zonetool/iw6/functions.hpp"

namespace zonetool::iw6
{
	namespace converter::h1
	{
		namespace xmodel
		{
			zonetool::h1::XModel* convert(XModel* asset, ZoneMemory* mem)
			{
				auto* new_asset = mem->Alloc<zonetool::h1::XModel>();

				REINTERPRET_CAST_SAFE(name);

				COPY_VALUE(numBones);
				COPY_VALUE(numRootBones);
				COPY_VALUE(numsurfs);
				COPY_VALUE(numReactiveMotionParts);
				new_asset->lodRampType = asset->__pad0[0]; // ?
				new_asset->numBonePhysics = 0;
				COPY_VALUE(scale);
				memcpy(new_asset->noScalePartBits, asset->noScalePartBits, sizeof(int[6])); // 6 -> 8
				REINTERPRET_CAST_SAFE(boneNames);
				REINTERPRET_CAST_SAFE(parentList);
				REINTERPRET_CAST_SAFE(tagAngles);
				REINTERPRET_CAST_SAFE(tagPositions);
				REINTERPRET_CAST_SAFE(partClassification);
				REINTERPRET_CAST_SAFE(baseMat);
				REINTERPRET_CAST_SAFE(reactiveMotionParts);
				new_asset->reactiveMotionTweaks = nullptr;
				REINTERPRET_CAST_SAFE(materialHandles);
				COPY_ARR(lodInfo);
				COPY_VALUE(numLods);
				COPY_VALUE(collLod);
				new_asset->numCompositeModels = 0;
				new_asset->u1 = 0;
				new_asset->flags = static_cast<short>(asset->flags); // convert?
				new_asset->numCollSurfs = static_cast<short>(asset->numCollSurfs);
				REINTERPRET_CAST_SAFE(collSurfs);
				COPY_VALUE(contents);
				REINTERPRET_CAST_SAFE(boneInfo);
				COPY_VALUE(radius);
				COPY_ARR(bounds);
				REINTERPRET_CAST_SAFE(invHighMipRadius);
				COPY_VALUE(memUsage);
				new_asset->bad = 0;
				new_asset->pad = 0;
				new_asset->targetCount = 0;
				new_asset->numberOfWeights = 0;
				new_asset->numberOfWeightMaps = 0;
				memset(new_asset->__pad2, 0, sizeof(new_asset->__pad2));
				new_asset->weightNames = nullptr;
				new_asset->blendShapeWeightMap = nullptr;
				if (asset->physPreset)
				{
					new_asset->physPreset = mem->Alloc<zonetool::h1::PhysPreset>();
					new_asset->physPreset->name = asset->physPreset->name;
				}
				if (asset->physCollmap)
				{
					new_asset->physCollmap = mem->Alloc<zonetool::h1::PhysCollmap>();
					new_asset->physCollmap->name = asset->physCollmap->name;
				}
				new_asset->mdaoVolumeCount = 0;
				new_asset->mdaoVolumes = nullptr;
				new_asset->u3 = 0;
				new_asset->u4 = 0;
				new_asset->u5 = 0;
				new_asset->skeletonScript = nullptr;
				new_asset->compositeModels = nullptr;
				new_asset->bonePhysics = nullptr;
				COPY_VALUE(quantization);

				return new_asset;
			}

			void dump(XModel* asset, ZoneMemory* mem)
			{
				auto* converted_asset = convert(asset, mem);
				zonetool::h1::IXModel::dump(converted_asset, 
					reinterpret_cast<decltype(zonetool::h1::SL_ConvertToString.get())>(zonetool::iw6::SL_ConvertToString.get()));
			}
		}
	}
}