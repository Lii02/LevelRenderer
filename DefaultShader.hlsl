#pragma pack_matrix(row_major)

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

StructuredBuffer<LevelMeshMaterial> material;

[[vk::push_constant]]
cbuffer MatrixPushConstant
{
    matrix viewProjectionMatrix;
    matrix modelMatrix;
};

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    matrix mvp = mul(modelMatrix, viewProjectionMatrix);
    output.Pos = mul(position, mvp);
    output.Tex = input.Tex;
    output.Norm = input.Norm;
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    return float4(input.Norm, 1);
}