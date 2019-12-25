#pragma once
class PreProcessor
{
public:
	virtual void PreProcess(image_data& img, const AreaBounds& bounds) = 0;
	virtual ~PreProcessor() {};
};
