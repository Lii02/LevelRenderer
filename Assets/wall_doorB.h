// "wall_doorB.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "wall_doorB.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _wall_doorB_version_
const char wall_doorB_version[4] = { '0','1','9','d' };
#define _wall_doorB_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _wall_doorB_vertexcount_
const unsigned wall_doorB_vertexcount = 55;
#define _wall_doorB_vertexcount_
#endif
#ifndef _wall_doorB_indexcount_
const unsigned wall_doorB_indexcount = 144;
#define _wall_doorB_indexcount_
#endif
#ifndef _wall_doorB_materialcount_
const unsigned wall_doorB_materialcount = 4; // can be used for batched draws
#define _wall_doorB_materialcount_
#endif
#ifndef _wall_doorB_meshcount_
const unsigned wall_doorB_meshcount = 4;
#define _wall_doorB_meshcount_
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
#ifndef _wall_doorB_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT wall_doorB_vertices[55] =
{
	{	{ -0.070000f, 0.250000f, 0.020000f },	{ -2.755906f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.070000f, 0.050000f, 0.020000f },	{ -2.755906f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.050000f, 0.020000f },	{ -3.937008f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.100000f, 0.250000f, 0.020000f },	{ -3.937008f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.050000f, 0.250000f, 0.020000f },	{ 1.968504f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.050000f, 0.020000f, 0.020000f },	{ 1.968504f, 0.212598f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.050000f, 0.020000f, 0.020000f },	{ -1.968504f, 0.212598f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.050000f, 0.250000f, 0.020000f },	{ -1.968504f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.250000f, 0.020000f },	{ 3.937008f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.100000f, 0.050000f, 0.020000f },	{ 3.937008f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.070000f, 0.050000f, 0.020000f },	{ 2.755906f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.070000f, 0.250000f, 0.020000f },	{ 2.755906f, -8.842520f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.120000f, 0.270000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.120000f, 0.270000f, 0.020000f },	{ 0.787402f, -9.629920f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.120000f, 0.000000f, 0.020000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.120000f, 0.000000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 1.000000f, 0.000000f, -0.000000f }	},
	{	{ -0.120000f, 0.270000f, -0.000000f },	{ -4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.120000f, 0.270000f, -0.000000f },	{ 4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.120000f, 0.270000f, 0.020000f },	{ 4.724410f, 1.787402f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ -0.120000f, 0.270000f, 0.020000f },	{ -4.724410f, 1.787402f, 0.000000f },	{ 0.000000f, -1.000000f, -0.000000f }	},
	{	{ 0.200000f, 0.050000f, -0.000000f },	{ 7.874016f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.000000f, -0.000000f },	{ 7.874016f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.120000f, 0.000000f, -0.000000f },	{ 4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.050000f, -0.000000f },	{ 5.905512f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.120000f, 0.270000f, -0.000000f },	{ 4.724410f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.300000f, -0.000000f },	{ 5.905512f, -10.811020f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.120000f, 0.270000f, -0.000000f },	{ -4.724410f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.300000f, -0.000000f },	{ -5.905512f, -10.811020f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.050000f, -0.000000f },	{ -5.905512f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.120000f, 0.000000f, -0.000000f },	{ -4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.000000f, -0.000000f },	{ -7.874016f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.050000f, -0.000000f },	{ -7.874016f, -0.968504f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.120000f, 0.000000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.120000f, 0.000000f, 0.020000f },	{ -0.787402f, 1.000000f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.120000f, 0.270000f, 0.020000f },	{ -0.787402f, -9.629920f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.120000f, 0.270000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ -1.000000f, 0.000000f, -0.000000f }	},
	{	{ 0.200000f, 0.400000f, -0.000000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.050000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.050000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.050000f, -0.000000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.300000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.400000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.150000f, 0.300000f, -0.000000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.300000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.050000f, -0.000000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.050000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.400000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.200000f, 0.400000f, -0.000000f },	{ 0.787402f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.050000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.200000f, 0.400000f, -0.000000f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.150000f, 0.300000f, -0.000000f },	{ 0.000000f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.120000f, 0.000000f, 0.020000f },	{ 4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.120000f, 0.000000f, 0.020000f },	{ -4.724410f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.120000f, 0.270000f, 0.020000f },	{ 4.724410f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.120000f, 0.270000f, 0.020000f },	{ -4.724410f, -9.629920f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _wall_doorB_vertices_
#endif
#ifndef _wall_doorB_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int wall_doorB_indices[144] =
{
	 0, 1, 2,
	 2, 3, 0,
	 4, 5, 6,
	 6, 7, 4,
	 8, 9, 10,
	 10, 11, 8,
	 12, 13, 14,
	 14, 15, 12,
	 16, 17, 18,
	 18, 19, 16,
	 20, 21, 22,
	 22, 23, 20,
	 22, 24, 23,
	 24, 25, 23,
	 24, 26, 25,
	 27, 25, 26,
	 28, 27, 26,
	 28, 26, 29,
	 29, 30, 28,
	 30, 31, 28,
	 32, 33, 34,
	 34, 35, 32,
	 36, 37, 38,
	 39, 40, 41,
	 42, 43, 41,
	 44, 45, 46,
	 47, 43, 48,
	 47, 49, 50,
	 5, 4, 10,
	 10, 9, 5,
	 4, 11, 10,
	 4, 7, 11,
	 7, 0, 11,
	 0, 3, 11,
	 5, 9, 51,
	 51, 52, 5,
	 9, 53, 51,
	 9, 8, 53,
	 8, 11, 53,
	 6, 5, 52,
	 2, 6, 52,
	 52, 54, 2,
	 54, 3, 2,
	 54, 11, 3,
	 54, 53, 11,
	 2, 1, 6,
	 7, 6, 1,
	 1, 0, 7,
};
#define _wall_doorB_indices_
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
#ifndef _wall_doorB_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL wall_doorB_materials[4] =
{
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
};
#define _wall_doorB_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _wall_doorB_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int wall_doorB_batches[4][2] =
{
	{ 18, 0 },
	{ 48, 18 },
	{ 18, 66 },
	{ 60, 84 },
};
#define _wall_doorB_batches_
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
#ifndef _wall_doorB_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH wall_doorB_meshes[4] =
{
	{
		"wall_doorB",
		18,
		0,
		0,
	},
	{
		"wall_doorB",
		48,
		18,
		1,
	},
	{
		"wall_doorB",
		18,
		66,
		2,
	},
	{
		"wall_doorB",
		60,
		84,
		3,
	},
};
#define _wall_doorB_meshes_
#endif
