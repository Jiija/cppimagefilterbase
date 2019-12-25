cmake_minimum_required(VERSION 3.15)
project(cppimagefilterbase)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cppimagefilterbase
        BWpreProc.h
        filterbase.h
        filterBlur.h
        filterBW.h
        filterConv.h
        filterEdge.h
        filterRed.h
        filters.h
        filterThreshold.h
        preProcessor.h
        filterbase.h
        main.cpp
        png_toolkit.cpp
        png_toolkit.h
        stb_image.h
        stb_image_write.h)
