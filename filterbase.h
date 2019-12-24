#pragma once
#include "png_toolkit.h"

struct AreaBounds {
	size_t hStart;
	size_t vStart;
	size_t hBound;
	size_t vBound;
};

class FilterBase
{
public:
	FilterBase() = 0;
	~FilterBase() = 0;
	virtual void ApplyFilter(image_data& img, const AreaBounds& bounds) { ProcessImage(img, bounds); };
protected:
	void ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds) = 0;
	void ProcessImage(image_data& img, const AreaBounds& bounds);
};