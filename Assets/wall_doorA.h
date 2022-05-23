// "wall_doorA.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "wall_doorA.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _wall_doorA_version_
const char wall_doorA_version[4] = { '0','1','9','d' };
#define _wall_doorA_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _wall_doorA_vertexcount_
const unsigned wall_doorA_vertexcount = 66;
#define _wall_doorA_vertexcount_
#endif
#ifndef _wall_doorA_indexcount_
const unsigned wall_doorA_indexcount = 120;
#define _wall_doorA_indexcount_
#endif
#ifndef _wall_doorA_materialcount_
const unsigned wall_doorA_materialcount = 4; // can be used for batched draws
#define _wall_doorA_materialcount_
#endif
#ifndef _wall_doorA_meshcount_
const unsigned wall_doorA_meshcount = 4;
#define _wall_doorA_meshcount_
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
#ifndef _wall_doorA_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT wall_doorA_vertices[66] =
{
	{	{ 0.070000f, 0.270000f, 0.020000f },	{ 2.755906f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.070000f, 0.000000f, 0.020000f },	{ 2.755906f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.000000f, 0.020000f },	{ -2.755906f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.020000f, 0.180000f, 0.020000f },	{ 0.787402f, -6.086614f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.020000f, 0.220000f, 0.020000f },	{ 0.787402f, -7.661417f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.020000f, 0.220000f, 0.020000f },	{ -0.787402f, -7.661417f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.020000f, 0.180000f, 0.020000f },	{ -0.787402f, -6.086614f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.270000f, 0.020000f },	{ -2.755906f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.270000f, -0.010000f },	{ -0.393701f, -9.629920f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.070000f, 0.270000f, 0.020000f },	{ 0.787402f, -9.629920f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.070000f, 0.000000f, 0.020000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.070000f, 0.000000f, -0.010000f },	{ -0.393701f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.000000f, -0.010000f },	{ 0.393701f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.000000f, 0.020000f },	{ -0.787402f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.270000f, 0.020000f },	{ -0.787402f, -9.629920f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.270000f, -0.010000f },	{ 0.393701f, -9.629920f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.300000f, -0.010000f },	{ -0.393701f, -10.811020f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.300000f, 0.000000f },	{ 0.000000f, -10.811020f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.050000f, 0.000000f },	{ 0.000000f, -0.968504f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.000000f, -0.010000f },	{ -0.393701f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.000000f, -0.010000f },	{ 0.393701f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.000000f, 0.000000f },	{ -0.000000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.050000f, 0.000000f },	{ -0.000000f, -0.968504f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.300000f, 0.000000f },	{ -0.000000f, -10.811020f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.300000f, -0.010000f },	{ 0.393701f, -10.811020f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.300000f, -0.010000f },	{ 3.937008f, -10.811020f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.000000f, -0.010000f },	{ 3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.070000f, 0.000000f, -0.010000f },	{ 2.755906f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.070000f, 0.270000f, -0.010000f },	{ 2.755906f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.270000f, -0.010000f },	{ -2.755906f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.300000f, -0.010000f },	{ -3.937008f, -10.811020f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.000000f, -0.010000f },	{ -3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.000000f, -0.010000f },	{ -2.755906f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.270000f, -0.010000f },	{ -2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.270000f, -0.010000f },	{ 2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.070000f, 0.270000f, 0.020000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.070000f, 0.270000f, 0.020000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.000000f, 0.000000f },	{ -3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.000000f, -0.000000f },	{ -7.874016f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.050000f, -0.000000f },	{ -7.874016f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.050000f, 0.000000f },	{ -3.937008f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.050000f, 0.000000f },	{ 7.874016f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.000000f, 0.000000f },	{ 7.874016f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.000000f, 0.000000f },	{ 3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.050000f, 0.000000f },	{ 3.937008f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.300000f, 0.000000f },	{ -3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.100000f, 0.300000f, -0.010000f },	{ -3.937008f, 0.606299f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.300000f, -0.010000f },	{ 3.937008f, 0.606299f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ -0.100000f, 0.300000f, 0.000000f },	{ 3.937008f, 1.000000f, 0.000000f },	{ 0.000000f, 1.000000f, -0.000000f }	},
	{	{ 0.200000f, 0.400000f, 0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.050000f, 0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.050000f, 0.000000f },	{ -2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.050000f, 0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.300000f, 0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.400000f, 0.000000f },	{ -2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.300000f, 0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.300000f, 0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.300000f, 0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.050000f, 0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.050000f, -0.000000f },	{ -2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.050000f, -0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.400000f, -0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.300000f, 0.000000f },	{ -2.755906f, 0.606299f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.400000f, -0.000000f },	{ 2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.400000f, 0.000000f },	{ -2.755906f, 1.787402f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _wall_doorA_vertices_
#endif
#ifndef _wall_doorA_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int wall_doorA_indices[120] =
{
	 0, 1, 2,
	 2, 3, 0,
	 3, 4, 0,
	 4, 5, 0,
	 6, 3, 2,
	 2, 7, 6,
	 7, 5, 6,
	 7, 0, 5,
	 8, 9, 10,
	 10, 11, 8,
	 12, 13, 14,
	 14, 15, 12,
	 16, 17, 18,
	 18, 19, 16,
	 19, 20, 16,
	 21, 22, 23,
	 23, 24, 21,
	 24, 25, 21,
	 26, 27, 28,
	 28, 29, 26,
	 29, 30, 26,
	 31, 26, 30,
	 32, 31, 30,
	 30, 33, 32,
	 34, 35, 36,
	 36, 37, 34,
	 38, 39, 40,
	 40, 41, 38,
	 42, 43, 44,
	 44, 45, 42,
	 46, 47, 48,
	 48, 49, 46,
	 50, 51, 52,
	 53, 54, 55,
	 56, 57, 55,
	 58, 59, 60,
	 61, 62, 63,
	 64, 65, 63,
	 4, 3, 6,
	 6, 5, 4,
};
#define _wall_doorA_indices_
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
#ifndef _wall_doorA_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL wall_doorA_materials[4] =
{
	{
		{{ 0.388235f, 0.400000f, 0.447059f },
		1.000000f,
		{ 0.200000f, 0.200000f, 0.200000f },
		500.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.500000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"door",
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
		{{ 0.737255f, 0.886275f, 1.000000f },
		1.000000f,
		{ 0.200000f, 0.200000f, 0.200000f },
		500.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.500000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"window",
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
#define _wall_doorA_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _wall_doorA_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int wall_doorA_batches[4][2] =
{
	{ 24, 0 },
	{ 72, 24 },
	{ 18, 96 },
	{ 6, 114 },
};
#define _wall_doorA_batches_
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
#ifndef _wall_doorA_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH wall_doorA_meshes[4] =
{
	{
		"wall_doorA",
		24,
		0,
		0,
	},
	{
		"wall_doorA",
		72,
		24,
		1,
	},
	{
		"wall_doorA",
		18,
		96,
		2,
	},
	{
		"wall_doorA",
		6,
		114,
		3,
	},
};
#define _wall_doorA_meshes_
#endif
