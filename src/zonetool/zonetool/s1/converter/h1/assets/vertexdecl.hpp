#pragma once

namespace zonetool::s1
{
	namespace converter::h1
	{
		namespace vertexdecl
		{
			zonetool::h1::MaterialVertexDeclaration* convert(MaterialVertexDeclaration* asset, ZoneMemory* mem);
			void dump(MaterialVertexDeclaration* asset, ZoneMemory* mem);
		}
	}
}