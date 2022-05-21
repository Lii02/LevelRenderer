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
    matrix mvp = mul(viewProjectionMatrix, modelMatrix);
    output.Pos = mul(mvp, position);
    output.Tex = input.Tex;
    output.Norm = input.Norm;
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    return float4(input.Tex, 0, 1);
}