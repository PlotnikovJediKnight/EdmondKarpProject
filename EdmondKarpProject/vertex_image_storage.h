#pragma once
#include <vector>

namespace Images {

	#define COLOR_TO_BE_TRANSPARENT RGB(153, 255, 204)

	class ImageResource;
	enum class VertexTokenKind { REGULAR, MONO, SELECTED };

	class VertexImageStorage {
	public:
		static const VertexImageStorage& Instance(VertexTokenKind kind);
		const ImageResource& operator[](int vertexIndex) const;
	private:
		VertexImageStorage();
		VertexTokenKind kind_;

		std::vector<ImageResource> images_regular_;
		std::vector<ImageResource> images_mono_;
		std::vector<ImageResource> images_selected_;
		static const size_t MAX_IMAGES_PER_VECTOR;
	};

}
