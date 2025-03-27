#
# Add test executable
#

add_executable(test_lib_text_ops
    lib_text_ops.cpp
)
target_link_libraries(test_lib_text_ops PRIVATE lib_text)


add_executable(test_lib_text_buffer
    lib_text_buffer.cpp
)
target_link_libraries(test_lib_text_buffer PRIVATE lib_text)


#
# Register tests with CTest
#

add_test(
    NAME test_lib_text_ops
    COMMAND test_lib_text_ops
)


add_test(
    NAME test_lib_text_buffer
    COMMAND test_lib_text_buffer
)

