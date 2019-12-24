#pragma once
#include "filterConv.h"

class FilterBlur : public FilterConv
{
public: 
	FilterBlur()
	{
		static  int defMatrix[9] = { 1, 1, 1,
									 1, 1, 1,
									 1, 1, 1 };
		for (int i = 0; i < 9; i++)
			convolutionMatrix[i] = defMatrix[i];
	}
};