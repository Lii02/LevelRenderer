// "low_buildingM.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "low_buildingM.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _low_buildingM_version_
const char low_buildingM_version[4] = { '0','1','9','d' };
#define _low_buildingM_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _low_buildingM_vertexcount_
const unsigned low_buildingM_vertexcount = 148;
#define _low_buildingM_vertexcount_
#endif
#ifndef _low_buildingM_indexcount_
const unsigned low_buildingM_indexcount = 180;
#define _low_buildingM_indexcount_
#endif
#ifndef _low_buildingM_materialcount_
const unsigned low_buildingM_materialcount = 2; // can be used for batched draws
#define _low_buildingM_materialcount_
#endif
#ifndef _low_buildingM_meshcount_
const unsigned low_buildingM_meshcount = 2;
#define _low_buildingM_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _low_buildingM_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT low_buildingM_vertices[148] =
{
	{	{ -0.200000f, 1.500000f, 0.200000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.200000f, 1.000000f, 0.200000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.200000f, 1.500000f, 0.200000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.200000f, 1.500000f, -0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.500000f, 0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, -0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.500000f, -0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.500000f, -0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 1.000000f, -0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 1.500000f, -0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 1.500000f, -0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, 0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.500000f, 0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.500000f, 0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.500000f, -0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, 0.100000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, 0.100000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, -0.100000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, -0.100000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.150000f, 1.500000f, 0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.150000f, 1.500000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.150000f, 1.500000f, 0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 1.500000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 1.500000f, 0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 1.500000f, -0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 1.975000f, -0.100000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 1.975000f, 0.100000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, -0.100000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 1.975000f, -0.100000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 1.500000f, -0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 1.500000f, 0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, 0.150000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 2.000000f, -0.150000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.150000f, 1.500000f, -0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, 0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 1.975000f, 0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 1.975000f, 0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 1.975000f, -0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 1.975000f, 0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 1.975000f, 0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 1.975000f, 0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 2.000000f, 0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 2.000000f, 0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.100000f, 1.975000f, -0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.100000f, 1.975000f, -0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.100000f, 1.975000f, -0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.100000f, 2.000000f, -0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.100000f, 2.000000f, -0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 1.500000f, -0.150000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 1.500000f, -0.150000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 1.500000f, -0.150000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 2.000000f, -0.150000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 2.000000f, -0.150000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, 0.200000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, 0.200000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, -0.200000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, -0.200000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.000000f, 0.200000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.000000f, -0.200000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.250000f, 0.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, 1.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.250000f, 0.000000f, 0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, 0.250000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.250000f, 1.000000f, -0.250000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.250000f, 0.000000f, -0.250000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.500000f, 0.200000f },	{ -7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 1.500000f, -0.200000f },	{ -7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 1.500000f, 0.150000f },	{ -5.905512f, 6.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.500000f, 0.200000f },	{ 7.874016f, 8.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 1.500000f, 0.150000f },	{ 5.905512f, 6.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.150000f, 1.500000f, -0.150000f },	{ 5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.150000f, 1.500000f, -0.150000f },	{ -5.905512f, -4.905512f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.200000f, 1.500000f, -0.200000f },	{ 7.874016f, -6.874016f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 1.975000f, 0.100000f },	{ 3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 1.975000f, 0.100000f },	{ -3.937008f, 4.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 1.975000f, -0.100000f },	{ -3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 1.975000f, -0.100000f },	{ 3.937008f, -2.937008f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
};
#define _low_buildingM_vertices_
#endif
#ifndef _low_buildingM_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int low_buildingM_indices[180] =
{
	 0, 1, 2,
	 2, 3, 0,
	 4, 5, 6,
	 7, 8, 9,
	 10, 11, 12,
	 13, 14, 15,
	 16, 17, 18,
	 19, 20, 21,
	 22, 23, 24,
	 25, 26, 27,
	 25, 28, 29,
	 30, 31, 29,
	 32, 33, 34,
	 35, 36, 37,
	 38, 31, 34,
	 38, 26, 39,
	 40, 41, 42,
	 43, 44, 45,
	 46, 47, 48,
	 49, 50, 51,
	 52, 53, 54,
	 55, 56, 57,
	 58, 59, 60,
	 61, 62, 63,
	 64, 65, 66,
	 67, 68, 69,
	 70, 71, 72,
	 73, 74, 75,
	 76, 77, 78,
	 79, 80, 81,
	 82, 83, 84,
	 85, 86, 87,
	 88, 89, 90,
	 91, 92, 93,
	 94, 95, 96,
	 97, 98, 99,
	 100, 101, 102,
	 103, 104, 105,
	 103, 106, 107,
	 108, 109, 107,
	 110, 111, 112,
	 113, 114, 115,
	 116, 109, 112,
	 116, 104, 117,
	 118, 119, 120,
	 121, 122, 123,
	 124, 125, 126,
	 127, 128, 129,
	 130, 131, 132,
	 133, 134, 135,
	 136, 137, 138,
	 138, 139, 136,
	 138, 140, 139,
	 140, 141, 139,
	 142, 138, 137,
	 137, 143, 142,
	 143, 141, 142,
	 143, 139, 141,
	 144, 145, 146,
	 146, 147, 144,
};
#define _low_buildingM_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _low_buildingM_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL low_buildingM_materials[2] =
{
	{
		{{ 0.764151f, 0.764151f, 0.764151f },
		1.000000f,
		{ 0.200000f, 0.200000f, 0.200000f },
		500.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.500000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"_defaultMat",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
	{
		{{ 0.560784f, 0.568627f, 0.600000f },
		1.000000f,
		{ 0.200000f, 0.200000f, 0.200000f },
		500.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.500000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"border",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _low_buildingM_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _low_buildingM_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int low_buildingM_batches[2][2] =
{
	{ 150, 0 },
	{ 30, 150 },
};
#define _low_buildingM_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _low_buildingM_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH low_buildingM_meshes[2] =
{
	{
		"low_buildingM",
		150,
		0,
		0,
	},
	{
		"low_buildingM",
		30,
		150,
		1,
	},
};
#define _low_buildingM_meshes_
#endif
