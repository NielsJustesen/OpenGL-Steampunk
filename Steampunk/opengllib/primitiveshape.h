#pragma once

class primitiveshape
{
public:
	__declspec(dllexport) void Triangle(float red, float green, float blue, float xpos, float ypos, float size);
	__declspec(dllexport) void Square(float red, float green, float blue, float xpos, float ypos, float size);
	__declspec(dllexport) void Player(float red, float green, float blue, float xpos, float ypos, float size);
	__declspec(dllexport) primitiveshape();
	__declspec(dllexport) ~primitiveshape();


private:

};

primitiveshape::primitiveshape()
{
}

primitiveshape::~primitiveshape()
{
}


