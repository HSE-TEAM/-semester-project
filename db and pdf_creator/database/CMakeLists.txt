add_library(
        Calc_DB_
        STATIC
        database/db_accessor/i_db_accessor.h
        database/data_sheet_handler/i_data_sheet_handler.h
        database/db_accessor/filesystem_db_accessor/filesystem_db_accessor.cpp
        database/db_accessor/filesystem_db_accessor/filesystem_db_accessor.h
        database/data_sheet_handler/filesystem_data_sheet_handler/filesystem_data_sheet_handler.cpp
        database/data_sheet_handler/filesystem_data_sheet_handler/filesystem_data_sheet_handler.h
        database/data_sheet_handler/postgres_data_sheet_handler/postgres_data_sheet_handler.cpp
        database/data_sheet_handler/postgres_data_sheet_handler/postgres_data_sheet_handler.h
        database/db_accessor/postgres_db_accessor/postgres_db_accessor.cpp
        database/db_accessor/postgres_db_accessor/postgres_db_accessor.h)

target_include_directories(Calc_DB_ PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Calc_DB_ PUBLIC Calc_Common_ pqxx -lpq)

