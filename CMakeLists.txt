
cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} 
"BWpreProc.h" 
"filterbase.h"  
"filterBlur.h" 
"filterBW.h"
"filterConv.h"
"filterEdge.h"
"filterRed.h"
"filters.h"
"filterThreshold.h"
"preProcessor.h"
"filterbase.h"
"main.cpp"
"png_toolkit.cpp"
"png_toolkit.h"
"stb_image.h"
"stb_image_write.h")
