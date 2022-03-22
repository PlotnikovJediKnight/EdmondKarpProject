#pragma once
#include <Windows.h>

namespace Images {

	class ImageResource {
	public:
		ImageResource(size_t macroID);
		ImageResource(const ImageResource&) = delete;
		ImageResource& operator=(const ImageResource&) = delete;
		ImageResource(ImageResource&&);
		operator HGDIOBJ() const;
		~ImageResource();
	private:
		HBITMAP hBitmap_;
	};

}
