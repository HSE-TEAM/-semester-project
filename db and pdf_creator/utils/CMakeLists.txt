add_library(
        Calc_Utils_
        STATIC
        utils/database/database_creator/i_database_creator.h
        utils/database/database_creator/table_creator/i_table_creator.h
        utils/database/database_creator/table_creator/data_creator/i_data_creator.h
        utils/database/database_creator/filesystem_database_creator/filesystem_database_creator.h
        utils/database/database_creator/filesystem_database_creator/filesystem_database_creator.cpp
        utils/database/database_creator/table_creator/filesystem_table_creator/filesystem_table_creator.cpp
        utils/database/database_creator/table_creator/filesystem_table_creator/filesystem_table_creator.h
        utils/database/database_creator/table_creator/data_creator/filesystem_data_creator/filesystem_data_creator.cpp
        utils/database/database_creator/table_creator/data_creator/filesystem_data_creator/filesystem_data_creator.h
        utils/database/database_creator/postgres_database_creator/postgres_database_creator.cpp
        utils/database/database_creator/postgres_database_creator/postgres_database_creator.h
        utils/database/database_creator/postgres_database_creator/postgres_database_creator.h
        utils/database/database_creator/postgres_database_creator/postgres_database_creator.h
        utils/database/database_creator/table_creator/postgres_table_creator/postgres_table_creator.cpp
        utils/database/database_creator/table_creator/postgres_table_creator/postgres_table_creator.h
        utils/database/database_creator/table_creator/data_creator/postgres_data_creator/postgres_data_creator.cpp
        utils/database/database_creator/table_creator/data_creator/postgres_data_creator/postgres_data_creator.h)

target_include_directories(Calc_Utils_ PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Calc_Utils_ PUBLIC Calc_Common_ pqxx -lpq)

