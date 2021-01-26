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

class Triangle
{

public:
	Triangle();
	~Triangle();


public :
	bool Setup();
	void Cleanup();

	bool Display(float timeDelta);

private :
	IDirect3DVertexBuffer9* triangleBuffer = nullptr;
};

