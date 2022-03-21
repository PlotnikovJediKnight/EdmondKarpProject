#pragma once
#include <vector>

namespace Images {

	class ImageResource;
	enum class VertexTokenKind { REGULAR, MONO, SELECTED };

	class VertexImageStorage {
	public:
		static const VertexImageStorage& Instance(VertexTokenKind kind);
		const ImageResource& operator[](int vertexIndex);
	private:
		VertexImageStorage();
		VertexTokenKind kind_;

		std::vector<ImageResource> images_regular_;
		std::vector<ImageResource> images_mono_;
		std::vector<ImageResource> images_selected_;
		static size_t MAX_IMAGES_PER_VECTOR;
	};

}
