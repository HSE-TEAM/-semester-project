add_library(
        Calculator
        STATIC
        i_updateable.h
        i_nameable.h
        i_costable.h
        value_interfaces/i_value.h
        value_interfaces/i_value_enumerable.h
        value_interfaces/parameter_interfaces/i_parameter.h
        value_interfaces/parameter_interfaces/i_parameter_enumerable.h
        window_group/window/window.cpp
        window_group/window/window.h
        window_group/window/parameters/enumerable_parameter/enumerable_value/enumerable_value.cpp
        window_group/window/parameters/enumerable_parameter/enumerable_value/enumerable_value.h
        window_group/window/parameters/single_parameter/single_value/single_value.cpp
        window_group/window/parameters/single_parameter/single_value/single_value.h
        window_group/window/parameters/enumerable_parameter/enumerable_parameter.cpp
        window_group/window/parameters/enumerable_parameter/enumerable_parameter.h
        window_group/window/parameters/single_parameter/single_parameter.cpp
        window_group/window/parameters/single_parameter/single_parameter.h
        window_group/window_group.cpp
        window_group/window_group.h
        window_group/window/glassy_object.cpp
        window_group/window/glassy_object.h
        value_interfaces/value_visitor/i_value_visitor.h
        window_group/window/glassy_object_visitor/i_glassy_object_visitor.h
        window_group/window/glassy_object_visitor/concrete_visitors/glassy_object_printing_visitor/glassy_object_printing_visitor.cpp
        window_group/window/glassy_object_visitor/concrete_visitors/glassy_object_printing_visitor/glassy_object_printing_visitor.h
        window_group/window/parameters/concrete_parameters/glass_meter_price_single_parameter/glass_meter_price_single_parameter.cpp
        window_group/window/parameters/concrete_parameters/glass_meter_price_single_parameter/glass_meter_price_single_parameter.h
        window_group/window/parameters/concrete_visitors/value_printing_visitor/value_printing_visitor.cpp
        window_group/window/parameters/concrete_visitors/value_printing_visitor/value_printing_visitor.h
        window_group/window/parameters/concrete_parameters/square_multiply_enumerable_parameter/square_multiply_enumerable_parameter.cpp
        window_group/window/parameters/concrete_parameters/square_multiply_enumerable_parameter/square_multiply_enumerable_parameter.h
        window_group/window/parameters/concrete_parameters/just_multiply_enumerable_parameter/just_multiply_enumerable_parameter.cpp
        window_group/window/parameters/concrete_parameters/just_multiply_enumerable_parameter/just_multiply_enumerable_parameter.h
        window_group/window/parameters/concrete_parameters/bottom_square_multiply_enumerable_parameter/bottom_square_multiply_enumerable_parameter.cpp
        window_group/window/parameters/concrete_parameters/bottom_square_multiply_enumerable_parameter/bottom_square_multiply_enumerable_parameter.h
        window_group/window/parameters/concrete_parameters/top_square_multiply_enumerable_parameter/top_square_multiply_enumerable_parameter.cpp
        window_group/window/parameters/concrete_parameters/top_square_multiply_enumerable_parameter/top_square_multiply_enumerable_parameter.h
        window_group/window/parameters/concrete_parameters/handles_enumerable_parameter/handles_enumerable_parameter.cpp
        window_group/window/parameters/concrete_parameters/handles_enumerable_parameter/handles_enumerable_parameter.h)


target_include_directories(Calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Calculator PUBLIC Calc_DB_ Calc_Common_)
