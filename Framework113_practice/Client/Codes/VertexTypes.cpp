#include "stdafx.h"
#include "..\Headers\VertexTypes.h"

const DWORD Vertex::FVF = D3DFVF_XYZ;

const DWORD ColorVertex::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

const DWORD PyramidVertex::FVF = D3DFVF_XYZ | D3DFVF_NORMAL;