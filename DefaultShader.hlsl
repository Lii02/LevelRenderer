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

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    output.Pos = position;
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    return float4(0.25f, 0.6f, 0.1f, 1);
}