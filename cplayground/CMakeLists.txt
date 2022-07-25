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
target_link_libraries(test_struct ${GTSAM_LIBRARIES} )

add_executable(test_static_instantiate_class src/test_static_instantiate_class.cpp)

add_executable(test_make_shared src/test_make_shared.cpp)