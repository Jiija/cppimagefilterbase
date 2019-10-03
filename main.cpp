#include <iostream>
#include "png_toolkit.h"

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 3)
            throw "Not enough arguments";

        png_toolkit studTool;
        studTool.load(argv[1]);
		image_data image = studTool.getPixelData();
		if (image.compPerPixel >= 3)
		{
			size_t image_size = (size_t)image.w * image.h * image.compPerPixel;
			unsigned char* p = NULL;
			for (p = image.pixels; p < image.pixels + image_size / 2; p += image.compPerPixel);
			for (; p < image.pixels + image_size; p += image.compPerPixel)
			{
				*p = 255;
				*(p + 1) = *(p + 2) = 0;
			}
		}
        studTool.save(argv[2]);

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
