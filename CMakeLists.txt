cmake_minimum_required(VERSION 2.8.3)

project(GhostFS-plugins)

#Define cmake modules location

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#Use ccache if available

find_program(CCACHE_FOUND ccache)

if(CCACHE_FOUND)
    message(STATUS "Using ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

#Find dependencies

find_package(fuse REQUIRED)
find_package(CURL REQUIRED)
find_package(Ghostfs REQUIRED)
find_package(Boost REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

set(
    GHOST_LIBRARIES
    ${FUSE_LIBRARIES}
    ${CURL_LIBRARIES}
    ${GHOST_FS_LIBRARIES}
)

#Define compilation flags

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -fPIC --std=c++11 -Wall -pthread -D_FILE_OFFSET_BITS=64")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -fno-inline -ggdb -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")

#Configure instalation settings

set(INSTALL_BIN_DIR /usr/bin/ghostfs_driver)
set(INSTALL_LIB_DIR /usr/lib/ghostfs_driver)

#Add source codes and generate executables

include_directories(
    ${FUSE_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}
    ${GHOST_FS_INCLUDE_DIRS}
)

add_definitions(-DGHOST_FS_PLUGINS_EXPORT)
set(BUILD_SHARED_LIBS TRUE)

add_library(ghostfs_plugin
    drivers_init.cc
    test/test_protocol.cc
    
    ghostfs_plugins.h
    test/test_protocol.h
)


install(
    TARGETS ghostfs_plugin
    DESTINATION "${INSTALL_BIN_DIR}"
    COMPONENT application
)

#create packages
set(ALLOW_BUILD_PACKAGE ON CACHE BOOL "checkbox")

if (ALLOW_BUILD_PACKAGE)
    set(PACKAGE_MAINTAINER "Péricles Lopes Machado <eu@gogo40.com>")
    set(PACKAGE_LICENSE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")

    set(PACKAGE_VERSION_MAJOR "1")
    set(PACKAGE_VERSION_MINOR "0")
    set(PACKAGE_VERSION_PATCH "0")

    set(PACKAGE_SYSTEM_NAME "amd64")

    set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${PACKAGE_MAINTAINER})
    set(CPACK_PACKAGE_DESCRIPTION_FILE ${PACKAGE_DESCRIPTION_FILE})
    set(CPACK_RESOURCE_FILE_LICENSE ${PACKAGE_LICENSE_FILE})

    set(CPACK_PACKAGE_VERSION_MAJOR ${PACKAGE_VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${PACKAGE_VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${PACKAGE_VERSION_PATCH})

    set(CPACK_SYSTEM_NAME ${PACKAGE_SYSTEM_NAME})

    set(PACKAGE_TYPE "DEB")    # DEB or RPM

    # DEB SPECIFIC
    if (PACKAGE_TYPE STREQUAL "DEB")
        set(CPACK_GENERATOR "DEB")
        set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON) # autogenerate dependency information (package d-shlibs should be installed)
        set(CPACK_DEBIAN_PACKAGE_DEPENDS "fuse (>= 2.6), attr (>= 2.0.0), curl (>= 7.0.0), boost-all (>= 1.57.0)")
    endif (PACKAGE_TYPE STREQUAL "DEB")

    # RPM SPECIFIC
    if (PACKAGE_TYPE STREQUAL "RPM")
        set(CPACK_GENERATOR "RPM")
    endif (PACKAGE_TYPE STREQUAL "RPM")

    include(CPack)
endif (ALLOW_BUILD_PACKAGE)



