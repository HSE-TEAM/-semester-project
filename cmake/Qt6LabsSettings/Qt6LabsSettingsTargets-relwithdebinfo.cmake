#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::LabsSettings" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::LabsSettings APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::LabsSettings PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6LabsSettings.a"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6LabsSettings.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::LabsSettings )
list(APPEND _cmake_import_check_files_for_Qt6::LabsSettings "${_IMPORT_PREFIX}/lib/libQt6LabsSettings.a" "${_IMPORT_PREFIX}/bin/Qt6LabsSettings.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
