#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QuickDialogs2QuickImpl" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::QuickDialogs2QuickImpl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Qt6::QuickDialogs2QuickImpl PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libQt6QuickDialogs2QuickImpl.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "Qt6::QuickTemplates2;Qt6::QuickDialogs2Utils;Qt6::Qml;Qt6::Core"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/Qt6QuickDialogs2QuickImpl.dll"
  )

list(APPEND _cmake_import_check_targets Qt6::QuickDialogs2QuickImpl )
list(APPEND _cmake_import_check_files_for_Qt6::QuickDialogs2QuickImpl "${_IMPORT_PREFIX}/lib/libQt6QuickDialogs2QuickImpl.a" "${_IMPORT_PREFIX}/bin/Qt6QuickDialogs2QuickImpl.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
