add_executable(
        SimpleExample
        simple/main.cpp
)

target_link_libraries(
        SimpleExample
        PUBLIC
        Calculator
        Calc_Utils_
)