add_library(
        document_creator
        STATIC
        document_creator/parameter_holder/parameter_holder.cpp
        document_creator/parameter_holder/parameter_holder.h
        document_creator/parameter_holder/parameter/parameter.h
        document_creator/parameter_holder/parameter/parameter.cpp
        document_creator/text_replacer/text_replacer.h
        document_creator/text_replacer/text_replacer.cpp)


target_include_directories(document_creator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})