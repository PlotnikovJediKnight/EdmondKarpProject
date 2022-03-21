#include "image_resource.h"

namespace Images {

	ImageResource::ImageResource(ImageResource&& rhs) {
		this->hBitmap_ = rhs.hBitmap_;
		rhs.hBitmap_ = NULL;
	}

	ImageResource::ImageResource(size_t macroID) {
		hBitmap_ = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(macroID));
	}

	ImageResource::~ImageResource() {
		if (hBitmap_ != NULL) {
			DeleteObject(hBitmap_);
		}
	}
}