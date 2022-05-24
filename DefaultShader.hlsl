#pragma pack_matrix(row_major)

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float2 Tex : TEXCOORD0;
    float3 Norm : NORMAL;
    float3 FragPos : FRAGPOS;
};

struct VS_INPUT
{
    float3 Pos : POSITION;
    float2 Tex : TEXCOORD0;
    float3 Norm : NORMAL;
};

#define POINT_LIGHT 0
#define DIRECTIONAL_LIGHT 1

struct Light
{
    float3 color;
    float3 positionDirection;
    float3 ambient;
    float intensity;
    int type;
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

#define MAX_MATERIAL_COUNT 35
#define MAX_LIGHT_COUNT 5
struct SceneData
{
    matrix viewProjection;
    LevelMeshMaterial materials[MAX_MATERIAL_COUNT];
    Light lights[MAX_LIGHT_COUNT];
};

StructuredBuffer<SceneData> sceneData;

[[vk::push_constant]]
cbuffer MiscData
{
    int index;
    int materialIndex;
	matrix model;
    float4 cameraPosition;
};

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    matrix mvp = mul(model, sceneData[0].viewProjection);
    output.Pos = mul(position, mvp);
    output.Norm = mul(input.Norm, model);
    output.FragPos = mul(model, position);
    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    float3 N = normalize(input.Norm);
    
    float3 diffuse = float3(0);
    float3 specular = float3(0);
    float3 ambient = float3(0);
    for (int i = 0; i < 1; i++)
    {
        Light light = sceneData[0].lights[i];
        // Diffuse calculations
        float3 lightDirection = normalize(-light.positionDirection);
        float3 lightDiffuse = saturate(dot(lightDirection, N)) * light.color * light.intensity;
    
        // Specular calculation
        float3 viewDirection = normalize(cameraPosition - input.FragPos);
        float3 reflectDirection = reflect(-lightDirection, N);
        float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), sceneData[0].materials[materialIndex].Ns);
        float3 lightSpecular = (sceneData[0].materials[materialIndex].Ks + sceneData[0].materials[materialIndex].Ka) * spec * light.color;
        
        diffuse += lightDiffuse;
        ambient += light.ambient;
        specular += lightSpecular;
    }
    
    // Final calculation
    return float4((diffuse + specular) * (ambient + sceneData[0].materials[materialIndex].Kd), 1);
}