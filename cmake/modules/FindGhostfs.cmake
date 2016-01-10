# Find GHOST-FS
#
# Find the ghost-fs includes and library
# 
# if you nee to add a custom library search path, do it via via CMAKE_PREFIX_PATH 
# 
# This module defines
#  GHOST_FS_INCLUDE_DIRS, where to find header, etc.
#  GHOST_FS_LIBRARIES, the libraries needed to use GHOST_FS.
#  GHOST_FS_FOUND, If false, do not try to use GHOST_FS.

# only look in default directories
find_path(
	GHOST_FS_INCLUDE_DIR 
	NAMES ghost_fs.h
	DOC "ghostfs include dir"
)

find_library(
	GHOST_FS_LIBRARY
	# names from cmake's FindGHOST_FS
	NAMES ghostfs ghostfs_lib libghostfs_imp ghostfs_lib_static libghostfs_lib
	DOC "ghostfs library"
)

set(GHOST_FS_INCLUDE_DIRS ${GHOST_FS_INCLUDE_DIR})
set(GHOST_FS_LIBRARIES ${GHOST_FS_LIBRARY})

# debug library on windows
# same naming convention as in qt (appending debug library with d)
# boost is using the same "hack" as us with "optimized" and "debug"
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	find_library(
		GHOST_FS_LIBRARY_DEBUG
		NAMES GHOST_FSd libghostfs_libd
		DOC "GHOST_FS debug library"
	)
	
	set(GHOST_FS_LIBRARIES optimized ${GHOST_FS_LIBRARIES} debug ${GHOST_FS_LIBRARY_DEBUG})

endif()

# handle the QUIETLY and REQUIRED arguments and set GHOST_FS_FOUND to TRUE
# if all listed variables are TRUE, hide their existence from configuration view
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GHOST_FS DEFAULT_MSG
	GHOST_FS_INCLUDE_DIR GHOST_FS_LIBRARY)
mark_as_advanced (GHOST_FS_INCLUDE_DIR GHOST_FS_LIBRARY)

