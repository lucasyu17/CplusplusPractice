# remember to add -I/usr/include/python2.7 -lpython2.7 in the cmake options when building
cmake_minimum_required(VERSION 3.16)
project(test_C_template_class CXX C)
set(CMAKE_CXX_STANDARD 17)

find_package(GTSAM REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${GTSAM_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
set(GTSAM_LIBRARIES gtsam)

find_package(GTSAMCMakeTools)
include(GtsamMakeConfigFile)
include(GtsamBuildTypes)
include(GtsamTesting)

add_executable(main src/main.cpp)

add_executable(test_functional src/test_functional.cpp)
target_link_libraries(test_functional ${GTSAM_LIBRARIES} )

add_executable(test_bind src/test_bind.cpp)

add_executable(test_lambda src/test_lambda.cpp)

add_executable(test_changable_lambda src/test_changable_lambda.cpp)

add_executable(test_inheritance_template src/test_inheritance_template.cpp)

add_executable(test_virtual_overload src/virtual_overload.cpp)

add_executable(test_loop_initializer src/test_loop_initializer.cpp)
target_link_libraries(test_loop_initializer ${GTSAM_LIBRARIES} )

add_executable(test_struct src/test_struct.cpp)
target_link_libraries(test_struct ${EIGEN3_INCLUDE_DIRS} )

add_executable(test_static_instantiate_class src/test_static_instantiate_class.cpp)

add_executable(test_make_shared src/test_make_shared.cpp)
