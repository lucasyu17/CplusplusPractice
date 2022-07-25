# remember to add -I/usr/include/python2.7 -lpython2.7 in the cmake options 
# when building
# ##############################################################################
# * 1. To create your own project, replace "gtsam_example" with the actual name
#   of your project
cmake_minimum_required(VERSION 3.16)
project(cplayground CXX C)
set(CMAKE_CXX_STANDARD 17)

# ##############################################################################
# * 2. Find GTSAM components so we have access to the GTSAM Cython install path
find_package(GTSAM REQUIRED) # Uses installed package
# Note: Since Jan-2019, GTSAMConfig.cmake defines exported CMake targets that
# automatically do include the include_directories() without the need to call
# include_directories(), just target_link_libraries(NAME gtsam)
# include_directories(${GTSAM_INCLUDE_DIR})

find_package(GTSAM REQUIRED)

include_directories(${GTSAM_INCLUDE_DIRS})
set(GTSAM_LIBRARIES gtsam)

find_package(GTSAMCMakeTools)
include(GtsamMakeConfigFile)
include(GtsamBuildTypes)
include(GtsamTesting)

# ##############################################################################
# * 3. Find Boost components
find_package(Boost 1.50 REQUIRED)
find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(Boost COMPONENTS serialization REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

# ##############################################################################
# * 3. Add the local source directory for CMake Ensure that local folder is
#   searched before library folders
include_directories(BEFORE "${PROJECT_SOURCE_DIR}")

add_subdirectory(cplayground)

# Build static library
set(cplayground_subdirs cplayground/include)
set(cplayground_srcs)

foreach(subdir ${cplayground_subdirs})
    file(GLOB subdir_srcs "${subdir}/*.h")
    list(APPEND cplayground_srcs ${subdir_srcs})
    # add_subdirectory(${subdir})
endforeach(subdir)

message(STATUS "cplayground_srcs ${cplayground_srcs}")

add_library(${PROJECT_NAME} SHARED ${cplayground_srcs})
target_link_libraries(${PROJECT_NAME} gtsam)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


# Install library
install(
TARGETS ${PROJECT_NAME}
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION bin)


# ##############################################################################
# Upto this point, we've only focused on building the C++ library. For details
# on how to build the python wrapper, please see the CMakeLists.txt file in the
# `python` directory.
add_subdirectory(python)

