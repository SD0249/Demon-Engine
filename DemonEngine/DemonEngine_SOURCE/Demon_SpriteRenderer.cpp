#include "Demon_SpriteRenderer.h"

namespace Demon {
	SpriteRenderer::SpriteRenderer() : image(nullptr), width(0), height(0)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		// Get Transform of this object
		Transform* tr = GetOwner()->GetComponent<Transform>();

		// Retrieve position vector from transform
		Vector2 pos = tr->GetPosition();

		// Create a graphics object and use that to draw loaded image
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(image, Gdiplus::Rect(pos._x, pos._y, width, height));
	}


	/// <summary>
	/// Loads image for this sprite renderer to draw from given path
	/// </summary>
	/// <param name="path">Path to retrieve sprite to be assigned</param>
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		image = Gdiplus::Image::FromFile(path.c_str());	// c_str(): converts c++ style string to traditional C string
		width = image->GetWidth();
		height = image->GetHeight();
	}


}