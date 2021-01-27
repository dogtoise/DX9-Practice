#include "stdafx.h"
#include "..\Headers\LitPyramid.h"
#include "VertexTypes.h"


LitPyramid::LitPyramid()
{
}


LitPyramid::~LitPyramid()
{
}

void LitPyramid::Setup()
{
	DEVICE->SetRenderState(D3DRS_LIGHTING, true);


}

void LitPyramid::Cleanup()
{
}

void LitPyramid::Display()
{
}
