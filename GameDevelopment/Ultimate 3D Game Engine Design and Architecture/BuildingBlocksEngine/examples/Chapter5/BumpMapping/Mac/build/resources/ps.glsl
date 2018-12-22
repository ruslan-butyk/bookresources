/*
   Ultimate Game Engine Design and Architecture
   Allen Sherrod
*/


varying vec2 texCoords;
varying vec4 pos;
varying vec3 normal;
varying vec4 sTangent;

uniform sampler2D decal;
uniform sampler2D bump;
uniform vec4 lightPos;
uniform vec4 lightColor;


void main()
{
   vec3 lightVec = vec3(lightPos.xyz) - vec3(pos.xyz);
   vec3 n = normalize(normal);

   vec3 binormal = cross(vec3(sTangent.xyz), n);
   mat3 tbnMatrix = mat3(sTangent, binormal, n);

   lightVec = tbnMatrix * lightVec;
   lightVec = normalize(lightVec);

   n = texture2D(bump, texCoords).xyz;
   n.x = (n.x - 0.5) * 2.0;
   n.y = (n.y - 0.5) * 2.0;
   n.z = (n.z - 0.5) * 2.0;
   

   float d = dot(lightVec.xyz, lightVec.xyz);
   float attenuationFactor = 1.0 / (d * d);

   float dp = max(dot(n, lightVec.xyz), 0.0);
   vec4 diffuse = vec4(attenuationFactor * lightColor.xyz * dp, 1.0);

   vec4 col = texture2D(decal, texCoords);

   gl_FragColor = col * (0.3 + diffuse);
}