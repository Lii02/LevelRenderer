struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float2 Tex : TEXCOORD0;
    float3 Norm : NORMAL;
};

struct VS_INPUT
{
    float3 Pos : POSITION;
    float2 Tex : TEXCOORD0;
    float3 Norm : NORMAL;
};

struct LevelMeshMaterial
{
    float3 Kd;
    float d;
    float3 Ks;
    float Ns;
    float3 Ka;
    float sharpness;
    float3 Tf;
    float Ni;
    float3 Ke;
	int illum;
};

#define MAX_MESH_COUNT 5
struct SceneData
{
    matrix view;
    matrix projection;
    matrix model;
    float4 cameraPosition;
    LevelMeshMaterial materials[MAX_MESH_COUNT];
};

StructuredBuffer<SceneData> sceneData;

[[vk::push_constant]]
cbuffer MeshIndex
{
    int meshIndex;
    int padding[31];
};

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    matrix mvp = mul(mul(sceneData[0].projection, sceneData[0].view), sceneData[0].model);
    output.Pos = mul(mvp, position);
    output.Tex = input.Tex;
    output.Norm = input.Norm;
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    return float4(sceneData[0].materials[meshIndex].Kd, 1);
}