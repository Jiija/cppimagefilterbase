#pragma once
#include "filterbase.h"
class FilterConv : public FilterBase
{
protected:
	int convolutionMatrix[9];
	void ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds);
private:
	stbi_uc clamp(int);
};

stbi_uc FilterConv::clamp(int val)
{
	if (val < 0)
		return 0;
	else if (val > 255)
		return 255;
	else
		return (stbi_uc)val;
}

void FilterConv::ProcessPixel(const image_data& img, stbi_uc* copyPixels, size_t i, size_t j, const AreaBounds& bounds)
{
	int pixelValues[9];
	stbi_uc* currPixel;
	currPixel = img.pixels + i * img.w * img.compPerPixel + j * img.compPerPixel;
	size_t hBeg, hEnd, vBeg, vEnd;
	hBeg = j < bounds.hStart + 1 ? bounds.hStart : j - 1;
	vBeg = i < bounds.vStart + 1 ? bounds.vStart : i - 1;
	hEnd = j + 2 > bounds.hBound - 1 ? bounds.hBound - 1 : j + 1;
	vEnd = i + 2 > bounds.vBound - 1 ? bounds.vBound - 1 : i + 1;
	int sum, div;
	for (size_t l = 0; l < 3; l++)
	{
		sum = div = 0;
		for (int k = -1; k < 2; k++)
		{
			if (k == -1 && vBeg == bounds.vStart || k == 1 && vEnd == bounds.vBound - 1)
				pixelValues[(k + 1) * 3] = pixelValues[(k + 1) * 3 + 1] = pixelValues[(k + 1) * 3 + 2] = 0;
			else
				for (int m = -1; m < 2; m++)
				{
					if (m == -1 && hBeg == bounds.hStart || m == 1 && hEnd == bounds.hBound - 1)
						pixelValues[(k + 1) * 3 + (m + 1)] = 0;
					else
						pixelValues[(k + 1) * 3 + (m + 1)] = copyPixels[(size_t)((int)i + k) * img.w * img.compPerPixel + (size_t)((int)j + m) * img.compPerPixel + l];
				}
		}
		for (int t = 0; t < 9; t++)
		{
			sum += pixelValues[t] * convolutionMatrix[t];
			div += convolutionMatrix[t];
		}
		*(currPixel + l) = clamp(sum / div);
	}
}