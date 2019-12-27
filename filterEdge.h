#pragma once
#include"filterConv.h"
#include "BWpreProc.h"


class FilterEdge : public FilterConv
{
public:
	void ApplyFilter(image_data& img, const AreaBounds& bounds) override
	{
		preProc->PreProcess(img, bounds);
		ProcessImage(img, bounds);
	}
	FilterEdge() : preProc(new BWpreProc)
	{
		static const int defMatrix[9] = { -1, -1, -1,
										  -1,  9, -1,
										  -1, -1, -1 };
		for (int i = 0; i < 9; i++)
			convolutionMatrix[i] = defMatrix[i];
	};
	~FilterEdge() { delete preProc; }
protected:
	PreProcessor* preProc;
};