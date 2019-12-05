#pragma once
#include "png_toolkit.h"

class Painter
{
	virtual char* paint(const image_data& img, size_t vBound, size_t hBound);
};

class FilterBase
{
public:
	FilterBase() = 0;
	~FilterBase();
	virtual void ApplyFilter(image_data &img, size_t vBound, size_t hBound);
protected:
	Painter* _painter;
};