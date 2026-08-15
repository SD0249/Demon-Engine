#include "Demon_SpriteRenderer.h"

namespace Demon {
	SpriteRenderer::SpriteRenderer()
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
		// Create color brush
		HBRUSH colorBrush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));

		// Select the color brush on DC and DON'T FORGET TO SAVE THE DEFAULT white brush (Returns Handle of previous brush)
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, colorBrush);

		// Draw a shape with the constantly updated value
		Transform* tr = GetOwner()->GetComponent<Transform>();

		Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		// Select default brush
		SelectObject(hdc, oldBrush);

		// Delete old brush -> No wasting memory
		DeleteObject(colorBrush);
	}
}