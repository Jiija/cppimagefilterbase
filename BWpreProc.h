#pragma once
#include "preProcessor.h"
#include "filterBW.h"
class BWpreProc : public PreProcessor, private FilterBW
{
	void PreProcess(image_data& img, const AreaBounds& bounds) override { ApplyFilter(img, bounds); }
};