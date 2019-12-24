#pragma once
#include "filterbase.h"
class FilterBW : public FilterBase 
{
protected:
	void FilterBW::ProcessPixel(const image_data& img, stbi_uc* copyPixels, size_t i, size_t j, const AreaBounds& bounds) override
	{
		stbi_uc* currPixel;
		stbi_uc x;
		currPixel = img.pixels + i * img.w * img.compPerPixel + j * img.compPerPixel;
		x = (*currPixel * 3 + *(currPixel + 1) * 6 + *(currPixel + 2)) / 10;
		*currPixel = *(currPixel + 1) = *(currPixel + 2) = x;
	}
};



