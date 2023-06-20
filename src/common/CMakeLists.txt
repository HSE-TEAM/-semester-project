add_library(
        Calc_Common_
        STATIC
        common/dimensions.h
        common/dimensions.cpp
)

target_include_directories(Calc_Common_ PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})