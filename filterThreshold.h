#pragma once
#include "BWpreProc.h"
#include <algorithm>
class FilterThreshold : public FilterBase
{
public:
	void ApplyFilter(image_data& img, const AreaBounds& bounds) override 
	{ 
		preProc->PreProcess(img, bounds);
		ProcessImage(img, bounds); 
	}
	FilterThreshold() : preProc(new BWpreProc) {};
	~FilterThreshold() { delete preProc; }
protected:
	void ProcessPixel(const image_data& img, stbi_uc* newPixels, size_t i, size_t j, const AreaBounds& bounds);
	PreProcessor* preProc;
};



void FilterThreshold::ProcessPixel(const image_data& img, stbi_uc* copyPixels, size_t i, size_t j, const AreaBounds& bounds)
{
	stbi_uc* currPixel, *copyPixel;
	currPixel = img.pixels + i * img.w * img.compPerPixel + j * img.compPerPixel;
	copyPixel = copyPixels + i * img.w * img.compPerPixel + j * img.compPerPixel;

	size_t hBeg, hEnd, vBeg, vEnd;
	hBeg = j < bounds.hStart + 2 ? bounds.hStart : j - 2;
	vBeg = i < bounds.vStart + 2 ? bounds.vStart : i - 2;
	hEnd = j + 2 >= bounds.hBound ? bounds.hBound - 1 : j + 2;
	vEnd = i + 2 >= bounds.vBound ? bounds.vBound - 1 : i + 2;
	size_t pixelNum = (hEnd - hBeg + 1) * (vEnd - vBeg + 1);
	stbi_uc* intenArr = new stbi_uc[pixelNum];
	size_t l = 0;
	for (size_t k = vBeg; k <= vEnd; k++)
		for (size_t m = hBeg; m <= hEnd; m++)
		{
			intenArr[l] = copyPixels[k * img.w * img.compPerPixel + m * img.compPerPixel];
			l++;
		}
			
	std::sort(intenArr, intenArr + pixelNum);
	if (*copyPixel < intenArr[pixelNum / 2])
		*currPixel = *(currPixel + 1) = *(currPixel + 2) = 0;
	delete[] intenArr;
}
