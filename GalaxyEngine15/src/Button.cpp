#include "..\include\Button.h"

Button::Button() :isOver(false), lastOver(false)
{
}

Button::~Button()
{
}

bool Button::Init(float _width, float _height)
{
	// Make material
	mat = Material(ShaderManager::GetShaderInstance(SHADER_UV_TEXTURE), "..\\res\\black.png");

	hover_mat = Material(ShaderManager::GetShaderInstance(SHADER_UV_TEXTURE), "..\\res\\white.png");

	// Make quad
	quad = TextureQuad(_width, _height, &mat);
	mat.SetRepeat(true);

	SetSize(_width, _height);

	return true;
}

bool Button::Update()
{
	// Get the current state of mouse over
	isOver = IsMouseOver(GlobalCustomVariables::GetCursorPos());

	// Keep from assigning the new material over and over again. 
	// Mouse over only needs to fire once per change
	if (isOver == lastOver)
	{
		// Nothing changed
		return true;
	}
	else
	{
		// Something changed
		if (isOver)
			quad.SetMaterial(&hover_mat);
		if (!isOver)
			quad.SetMaterial(&mat);

		lastOver = isOver;
		return false;
	}
}

bool Button::Draw()
{
	// Draw some stuff(buttonText)
	quad.SetMatrix(ViewMatrix);
	quad.Draw(position.x,ScreenHeight-position.y);

	return true;
}

void Button::SetPositionF(Vector2f pos)
{
	SetPosition(Vector2f(pos.x*ScreenWidth, pos.y*ScreenHeight));
}

void Button::SetPositionF(float x, float y)
{
	SetPosition(Vector2f(x*ScreenWidth, y*ScreenHeight));
}

void Button::SetOriginF(Vector2f pos)
{
	SetOrigin(Vector2f(pos.x*width, pos.y*height));
}

void Button::SetOriginF(float x, float y)
{
	SetOrigin(Vector2f(x*width, y*height));
}