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
	virtual void ApplyFilter(image_data& img, const AreaBounds& bounds) { ProcessImage(img, bounds); };
	virtual ~FilterBase() {};
protected:
	virtual void ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds) = 0;
	void ProcessImage(image_data& img, const AreaBounds& bounds);
};

void FilterBase::ProcessImage(image_data& img, const AreaBounds& bounds)
{
	size_t imageSize = (size_t)img.w * img.h * img.compPerPixel;
	stbi_uc* newPixels = new stbi_uc[imageSize];
	for (size_t i = 0; i < imageSize; i++)
		newPixels[i] = img.pixels[i];

	for (size_t i = bounds.vStart; i < bounds.vBound; i++)
		for (size_t j = bounds.hStart; j < bounds.hBound; j++)
			ProcessPixel(img, newPixels, i, j, bounds);

	delete[] newPixels;
}