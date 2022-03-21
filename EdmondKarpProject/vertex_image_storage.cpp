#include "vertex_image_storage.h"
#include "image_resource.h"
#include "resource.h"

using namespace std;

namespace Images {

	size_t VertexImageStorage::MAX_IMAGES_PER_VECTOR = 20;

	#define FILL_VECTOR_WITH_IMAGES(VECTOR_NAME, FILE_NAME_SUFFIX) \
			{\
			VECTOR_NAME##.emplace_back(IDB_BITMAP1##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP2##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP3##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP4##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP5##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP6##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP7##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP8##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP9##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP10##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP11##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP12##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP13##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP14##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP15##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP16##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP17##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAP18##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAPSNK##FILE_NAME_SUFFIX); \
			VECTOR_NAME##.emplace_back(IDB_BITMAPSRC##FILE_NAME_SUFFIX); \
			}\


	VertexImageStorage::VertexImageStorage() : kind_(VertexTokenKind::REGULAR) {
		FILL_VECTOR_WITH_IMAGES(images_regular_, _R);
		FILL_VECTOR_WITH_IMAGES(images_mono_, _M);
		FILL_VECTOR_WITH_IMAGES(images_selected_, _S);
	}

	const VertexImageStorage& 
	VertexImageStorage::Instance(VertexTokenKind kind) {
		static VertexImageStorage _instance;
		_instance.kind_ = kind;
		return _instance;
	}

	const ImageResource&
	VertexImageStorage::operator[](int vertexIndex) {
		vector<ImageResource>* vectorPointer = nullptr;
		switch (kind_) {
		case VertexTokenKind::REGULAR: {
			vectorPointer = &images_regular_;
			break;
		}
		case VertexTokenKind::MONO: {
			vectorPointer = &images_mono_;
			break;
		}
		case VertexTokenKind::SELECTED: {
			vectorPointer = &images_selected_;
			break;
		}
		}

		if (vertexIndex == -1) {
			return vectorPointer->at(MAX_IMAGES_PER_VECTOR - 1);
		}
			else
		if (vertexIndex == -2) {
			return vectorPointer->at(MAX_IMAGES_PER_VECTOR - 2);
		} else {
			return vectorPointer->at(vertexIndex);
		}
	}

}