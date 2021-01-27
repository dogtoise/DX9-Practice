#pragma once
struct Vertex
{
	Vertex() {}

	Vertex(float x, float y, float z)
	{
		_x = x; _y = y; _z = z;
	}
	float _x, _y, _z;

	static const DWORD FVF;
};

struct ColorVertex
{
	ColorVertex() {}

	ColorVertex(float x, float y, float z, D3DCOLOR c)
	{
		_x = x; 
		_y = y;
		_z = z;
		_color = c;
	}

	float _x, _y, _z;
	D3DCOLOR _color;

	static const DWORD FVF;
};

struct PyramidVertex
{
	PyramidVertex() {}

	PyramidVertex(float x, float y, float z, float nx, float ny, float nz)
	{
		_x = x;  _y = y;	_z = z;
		_nx = nx; _ny = ny; _nz = nz;
	}
	float  _x, _y, _z;
	float _nx, _ny, _nz;

	static const DWORD FVF;
};

struct TextureVertex
{
	TextureVertex() {}
	TextureVertex(
		float x, float y, float z,
		float nx, float ny, float nz,
		float u, float v)
	{
		_x = x;  _y = y;  _z = z;
		_nx = nx; _ny = ny; _nz = nz;
		_u = u;  _v = v;
	}
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v; // texture coordinates

	static const DWORD FVF;
};
