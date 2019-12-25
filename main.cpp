#include <iostream>
#include <fstream>
#include <string>
#include "filters.h"
#include "png_toolkit.h"

int main(int argc, char* argv[])
{
	// toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
	// toolkit near test images!
	try
	{
		if (argc != 4)
			throw "Not enough arguments";
	std::string filterName;
	std::ifstream configStream;
	size_t u, l, b, r;
	configStream.open(argv[1], std::ifstream::in);
	png_toolkit studTool;
	studTool.load(argv[2]);
	image_data image = studTool.getPixelData();
	AreaBounds bounds;
	while (!configStream.eof())
	{
		configStream >> filterName;
		configStream >> u >> l >> b >> r;
		bounds.vStart = u == 0 ? 0 : image.h / u;
		bounds.hStart = l == 0 ? 0 : image.w / l;
		bounds.vBound = b == 0 ? 0 : image.h / b;
		bounds.hBound = r == 0 ? 0 : image.w / r;
		if (image.compPerPixel >= 3)
		{
			FilterBase* filter;
			if (filterName == "Red")
				filter = new FilterRed();
			else if (filterName == "Blur")
				filter = new FilterBlur();
			else if (filterName == "Edge")
				filter = new FilterEdge();
			else if (filterName == "Threshold")
				filter = new FilterThreshold();
			else
				continue;
			filter->ApplyFilter(image, bounds);
			delete filter;
		}
		filterName.clear();
	}
	configStream.close();
	studTool.save(argv[3]);

	}
	catch (const char* str)
	{
		std::cout << "Error: " << str << std::endl;
		return 1;
	}

	return 0;
}