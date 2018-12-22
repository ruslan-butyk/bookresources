// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#include "Wm3RipplingOceanPShader.h"
using namespace Wm3;

WM3_IMPLEMENT_RTTI(Wm3,RipplingOceanPShader,PixelShader);
WM3_IMPLEMENT_STREAM(RipplingOceanPShader);
WM3_IMPLEMENT_DEFAULT_STREAM(RipplingOceanPShader,PixelShader);
WM3_IMPLEMENT_DEFAULT_NAME_ID(RipplingOceanPShader,PixelShader);

//----------------------------------------------------------------------------
RipplingOceanPShader::RipplingOceanPShader ()
{
    // shader program (load the type of the current renderer)
    m_acProgram = ms_aacProgram[Renderer::GetType()];
}
//----------------------------------------------------------------------------
RipplingOceanPShader::~RipplingOceanPShader ()
{
}
//----------------------------------------------------------------------------
const char* RipplingOceanPShader::ms_aacProgram[Renderer::RT_QUANTITY] =
{
"!!ARBfp1.0\n"
"# ARB_fragment_program generated by NVIDIA Cg compiler\n"
"# cgc version 1.1.0003, build date Mar  4 2003  12:32:10\n"
"# command line args: -q -profile arbfp1 -entry pmain\n"
"#vendor NVIDIA Corporation\n"
"#version 1.0.02\n"
"#profile arbfp1\n"
"#program pmain\n"
"#semantic pmain.kBump\n"
"#semantic pmain.kWater\n"
"#semantic pmain.kEnv\n"
"#var float2 i_f2Tex0 : $vin.TEXCOORD0 : TEXCOORD0 : 0 : 1\n"
"#var float2 i_f2Tex1 : $vin.TEXCOORD1 : TEXCOORD1 : 1 : 1\n"
"#var float3 i_f3View : $vin.TEXCOORD2 : TEXCOORD2 : 2 : 1\n"
"#var float3 i_f3Tangent : $vin.TEXCOORD3 : TEXCOORD3 : 3 : 1\n"
"#var float3 i_f3Binormal : $vin.TEXCOORD4 : TEXCOORD4 : 4 : 1\n"
"#var float3 i_f4Normal : $vin.TEXCOORD5 : TEXCOORD5 : 5 : 1\n"
"#var float4 i_f4LightDir : $vin.TEXCOORD6 : TEXCOORD6 : 6 : 1\n"
"#var float4 o_f4Color : $vout.COLOR : COLOR : 7 : 1\n"
"#var sampler2D kBump :  : texunit 0 : 8 : 1\n"
"#var sampler2D kWater :  : texunit 1 : 9 : 1\n"
"#var sampler2D kEnv :  : texunit 2 : 10 : 1\n"
"PARAM c0 = {0, 0, 3, 1};\n"
"PARAM c1 = {2, 0.5, 0.69999999, 0.2};\n"
"TEMP R0;\n"
"TEMP R1;\n"
"TEMP R2;\n"
"TEX R0.xyz, fragment.texcoord[0], texture[0], 2D;\n"
"TEX R1.xyz, fragment.texcoord[1], texture[0], 2D;\n"
"MOV R2.w, c0.w;\n"
"MAD R0.xyz, R0, c1.x, -R2.w;\n"
"MOV R2.w, c0.w;\n"
"MAD R1.xyz, R1, c1.x, -R2.w;\n"
"ADD R1.xyz, R0, R1;\n"
"MUL R1.xyz, R1, c1.y;\n"
"MOV R0.w, c0.w;\n"
"MAD R0.xyz, fragment.texcoord[4], c1.x, -R0.w;\n"
"MUL R0.xyz, R1.y, R0;\n"
"MOV R2.w, c0.w;\n"
"MAD R2.xyz, fragment.texcoord[3], c1.x, -R2.w;\n"
"MAD R0.xyz, R1.x, R2, R0;\n"
"MOV R2.w, c0.w;\n"
"MAD R2.xyz, fragment.texcoord[5], c1.x, -R2.w;\n"
"MAD R0.xyz, R1.z, R2, R0;\n"
"MOV R1.w, c0.w;\n"
"MAD R1.xyz, fragment.texcoord[2], c1.x, -R1.w;\n"
"DP3 R0.w, R2, R1;\n"
"MOV_SAT R0.w, -R0.w;\n"
"ADD R0.w, c0.w, -R0.w;\n"
"POW R0.w, R0.w, c0.z;\n"
"DP3 R1.w, R1, R0;\n"
"MUL R1.xyz, c1.x, R1;\n"
"MAD R1.xyz, -R1, R1.w, R0;\n"
"MAD R1.xyz, R1, c1.y, c1.y;\n"
"MOV R2.x, R1;\n"
"MAD R1.x, R1.z, c1.z, c1.w;\n"
"MOV R2.z, R1.x;\n"
"TEX R1.xyz, R2.xzxx, texture[2], 2D;\n"
"MOV R2.w, c0.w;\n"
"MAD R2.xyz, fragment.texcoord[6], c1.x, -R2.w;\n"
"DP3 R0.x, R0, -R2;\n"
"POW R0.y, R1.y, c1.x;\n"
"MUL R0.y, R0.y, R0.w;\n"
"MUL R1.xyz, R1, R0.y;\n"
"MOV R2.x, R0.w;\n"
"MOV R2.y, c0.y;\n"
"TEX R2.xyz, R2, texture[1], 2D;\n"
"ADD R0.y, c0.w, -fragment.texcoord[6].w;\n"
"MAD R0.x, R0.y, R0.x, fragment.texcoord[6].w;\n"
"MAD R1.xyz, R2, R0.x, R1;\n"
"MOV result.color.xyz, R1;\n"
"END\n"
"# 44 instructions, 3 R-regs, 0 H-regs.\n"
"# End of program\n"
,
"// DX9 Pixel Shader by NVIDIA Cg compiler\n"
"	ps_2_0\n"
"// cgc version 1.1.0003, build date Mar  4 2003  12:32:10\n"
"// command line args: -q -profile ps_2_0 -entry pmain -profileopts dcls -strict\n"
"//vendor NVIDIA Corporation\n"
"//version 1.0.02\n"
"//profile ps_2_0\n"
"//program pmain\n"
"//semantic pmain.kBump\n"
"//semantic pmain.kWater\n"
"//semantic pmain.kEnv\n"
"//var float2 i_f2Tex0 : $vin.TEXCOORD0 : TEXCOORD0 : 0 : 1\n"
"//var float2 i_f2Tex1 : $vin.TEXCOORD1 : TEXCOORD1 : 1 : 1\n"
"//var float3 i_f3View : $vin.TEXCOORD2 : TEXCOORD2 : 2 : 1\n"
"//var float3 i_f3Tangent : $vin.TEXCOORD3 : TEXCOORD3 : 3 : 1\n"
"//var float3 i_f3Binormal : $vin.TEXCOORD4 : TEXCOORD4 : 4 : 1\n"
"//var float3 i_f4Normal : $vin.TEXCOORD5 : TEXCOORD5 : 5 : 1\n"
"//var float4 i_f4LightDir : $vin.TEXCOORD6 : TEXCOORD6 : 6 : 1\n"
"//var float4 o_f4Color : $vout.COLOR : COLOR : 7 : 1\n"
"//var sampler2D kBump :  : texunit 0 : 8 : 1\n"
"//var sampler2D kWater :  : texunit 1 : 9 : 1\n"
"//var sampler2D kEnv :  : texunit 2 : 10 : 1\n"
"	dcl_2d	s0\n"
"	dcl_2d	s1\n"
"	dcl_2d	s2\n"
"	def	c0,	0.000000, 0.000000, 0.000000, 1.000000\n"
"	def	c1,	3.000000, 2.000000, 0.500000, 0.700000\n"
"	def	c2,	0.200000, 0.000000, 0.000000, 0.000000\n"
"	dcl	t0.xy\n"
"	dcl	t1.xy\n"
"	dcl	t2.xyz\n"
"	dcl	t3.xyz\n"
"	dcl	t4.xyz\n"
"	dcl	t5.xyz\n"
"	dcl	t6\n"
"texld   r0, t0, s0\n"
"texld   r1, t1, s0\n"
"mov     r2.w, c0.w\n"
"mad     r0.xyz, r0, c1.y, -r2.w\n"
"mov     r2.w, c0.w\n"
"mad     r1.xyz, r1, c1.y, -r2.w\n"
"add     r1.xyz, r0, r1\n"
"mul     r1.xyz, r1, c1.z\n"
"mov     r0.w, c0.w\n"
"mad     r0.xyz, t4, c1.y, -r0.w\n"
"mul     r0.xyz, r1.y, r0\n"
"mov     r2.w, c0.w\n"
"mad     r2.xyz, t3, c1.y, -r2.w\n"
"mad     r0.xyz, r1.x, r2, r0\n"
"mov     r2.w, c0.w\n"
"mad     r2.xyz, t5, c1.y, -r2.w\n"
"mad     r0.xyz, r1.z, r2, r0\n"
"mov     r1.w, c0.w\n"
"mad     r1.xyz, t2, c1.y, -r1.w\n"
"dp3     r0.w, r2, r1\n"
"mov_sat r0.w, -r0.w\n"
"add     r0.w, c0.w, -r0.w\n"
"pow     r1.w, r0.w, c1.x\n"
"dp3     r0.w, r1.x, r0.x\n"
"mul     r1.xyz, c1.y, r1\n"
"mad     r1.xyz, -r1, r0.w, r0\n"
"mad     r1.xyz, r1, c1.z, c1.z\n"
"mov     r0.w, c2.x\n"
"mad     r0.w, r1.z, c1.w, r0.w\n"
"mov     r1.z, r0.w\n"
"mov     r2.xzw, r1.x\n"
"mov     r2.y, r1.z\n"
"mov     r1.xy, r2\n"
"texld   r2, r1, s2\n"
"mov     r3.w, c0.w\n"
"mad     r1.xyz, t6, c1.y, -r3.w\n"
"dp3     r0.x, r0, -r1\n"
"pow     r0.y, r2.y, c1.y\n"
"mul     r0.y, r0.y, r1.w\n"
"mul     r1.xyz, r2, r0.y\n"
"mov     r2.x, r1.w\n"
"mov     r2.y, c0.y\n"
"texld   r2, r2, s1\n"
"add     r0.y, c0.w, -t6.w\n"
"mad     r0.x, r0.y, r0.x, t6.w\n"
"mad     r1.xyz, r2, r0.x, r1\n"
"mov     r0.w, c0.w\n"
"mov     r0.xyz, r1\n"
"mov     oC0, r0\n"
"// 49 instructions, 4 R-regs.\n"
"// End of program\n"
};