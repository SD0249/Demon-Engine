#pragma once
#include "CommonInclude.h"
#include "Demon_Component.h"
#include "Demon_GameObject.h"
#include "Demon_Transform.h"

namespace Demon {
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* image;	// Sprite to be rendered
		UINT width;				// Width 
		UINT height;			// Height
	};
}


