add_executable(simple_target
        main.cpp)

target_link_libraries(simple_target PUBLIC document_creator)