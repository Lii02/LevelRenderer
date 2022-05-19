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

struct StorageBuffer
{
    matrix projectionMatrix;
    matrix viewMatrix;
    matrix modelMatrix;
};

StructuredBuffer<StorageBuffer> SceneData;

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    matrix viewProjection = mul(SceneData[0].projectionMatrix, SceneData[0].viewMatrix);
    matrix mvp = mul(viewProjection, SceneData[0].modelMatrix);
    output.Pos = mul(position, mvp);
    output.Norm = input.Norm;
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    return float4(1, 0, 0, 1);
}