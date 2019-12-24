#pragma once
#include "filterbase.h"
class FilterRed : public FilterBase {
	void ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds) override {
		int check;
		stbi_uc* currPixel;
		currPixel = img.pixels + i * img.w * img.compPerPixel + j * img.compPerPixel;
		check = (int)currPixel;
		*currPixel = 255;
		*(currPixel + 1) = *(currPixel + 2) = 0;
	}
};

/*void FilterRed::ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds)
{
	stbi_uc* currPixel;
	currPixel = newPixels + i * img.w * img.compPerPixel + j * img.compPerPixel;
	*currPixel = 255;
	*(currPixel + 1) = *(currPixel + 2) = 0;
}*/