#pragma once
class Cube
{
public:
	Cube();
	~Cube();

	void Setup();

	void Cleanup();

	void Display();
private :
	IDirect3DVertexBuffer9 * VB = 0;
	IDirect3DIndexBuffer9* IB = 0;
};

