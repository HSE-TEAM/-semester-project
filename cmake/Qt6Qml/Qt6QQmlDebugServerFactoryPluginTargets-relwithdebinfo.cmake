#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QQmlDebugServerFactoryPlugin" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::QQmlDebugServerFactoryPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::QQmlDebugServerFactoryPlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELWITHDEBINFO ""
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/./plugins/qmltooling/qmldbg_server.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::QQmlDebugServerFactoryPlugin )
list(APPEND _cmake_import_check_files_for_Qt6::QQmlDebugServerFactoryPlugin "${_IMPORT_PREFIX}/./plugins/qmltooling/qmldbg_server.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
