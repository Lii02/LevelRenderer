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

struct Light
{
    float3 color;
    float3 positionDirection;
    float intensity;
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
    int lightsUsed;
};

StructuredBuffer<SceneData> sceneData;

[[vk::push_constant]]
cbuffer MiscData
{
    int index;
    int materialIndex;
	matrix model;
    float4 cameraPosition;
    bool usesDiffuseMap;
    bool useSpecularMap;
};

VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    float4 position = float4(input.Pos, 1);
    matrix mvp = mul(sceneData[0].viewProjection, model);
    output.Pos = mul(mvp, position);
    output.Norm = mul(model, input.Norm);
    output.Tex = input.Tex;
    output.FragPos = mul(model, position);
    return output;
}

const float PI = 3.141592;
const float3 Fdielectric = float3(0.04);

float DistributionGGX(float3 N, float3 H, float roughness)
{
    float a = roughness * roughness;
    float a2 = a * a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH * NdotH;

    float num = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return num / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;

    float num = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return num / denom;
}

float GeometrySmith(float3 N, float3 V, float3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}

float3 FresnelSchlick(float cosTheta, float3 F0)
{
    return F0 + (1.0 - F0) * max(pow(1.0 - cosTheta, 5.0), 0.0f);
}

float mix(float3 x, float3 y, float3 a)
{
    return x * (1 - a) + y * a;
}

Texture2D diffuseTexture : register(t1);
SamplerState dlinearSampler : register(s1);
Texture2D specularTexture : register(t2);
SamplerState slinearSampler : register(s2);

float4 PS(VS_OUTPUT input) : SV_TARGET
{
    float3 N = normalize(input.Norm);
    float3 materialDiffuse;
    float materialSpecular = 0;
    if (usesDiffuseMap)
    {
        materialDiffuse = diffuseTexture.Sample(dlinearSampler, input.Tex).bgr;
    }
    else
    {
        materialDiffuse = sceneData[0].materials[materialIndex].Kd;
    }
    
    if (useSpecularMap)
    {
        materialSpecular = specularTexture.Sample(slinearSampler, input.Tex).r;
    }
    else
    {
        materialSpecular = sceneData[0].materials[materialIndex].Ns;
    }
    
    float3 diffuse = float3(0);
    float3 specular = float3(0);
    float3 V = normalize(-cameraPosition - input.FragPos);
    float3 F0 = Fdielectric;
    F0 = mix(F0, materialDiffuse, materialSpecular);
    float3 Lo = float3(0.0);
    float roughness = 0.15f;
    
    for (int i = 0; i < sceneData[0].lightsUsed; i++)
    {
        Light light = sceneData[0].lights[i];
        float3 lightDirection = normalize(light.positionDirection - input.FragPos);
        float dist = length(light.positionDirection - input.FragPos);
        float attenuate = 1.0 / (dist * dist);
        float3 H = normalize(V + lightDirection);
        float3 radiance = light.color * attenuate * light.intensity;
        
        float NDF = DistributionGGX(N, H, roughness);
        float G = GeometrySmith(N, V, lightDirection, roughness);
        float3 F = FresnelSchlick(max(dot(H, V), 0.0), F0);
        
        float3 nominator = NDF * G * F;
        float denominator = 4 * max(dot(N, V), 0.0) * max(dot(N, lightDirection), 0.0) + 0.001;
        float3 specular = nominator / denominator;
        
        float3 kS = F;
        float3 kD = float3(1.0) - kS;
        kD *= 1.0 - materialSpecular;
        float NdotL = max(dot(N, lightDirection), 0.0);
        Lo += (kD * materialDiffuse / PI + specular) * radiance * NdotL;
    }
    
    // Final calculation
    float3 ambient = float3(0.03) * materialDiffuse;
    float3 color = ambient + Lo;
    color = color / (color + float3(1.0));
    color = pow(color, float3(1.0 / 2.2));
    return float4(color, 1);
}