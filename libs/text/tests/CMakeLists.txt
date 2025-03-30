
enable_testing()

# ============================================================
# Testing lib_text_ops
# ============================================================

# Compile lib_text_ops Test Executables

add_executable(test_lib_text_ops lib_text_ops.cpp )
target_link_libraries(test_lib_text_ops PRIVATE lib_text)

# Register lib_text_ops tests with CTest

add_test( NAME lib_text_ops COMMAND test_lib_text_ops )



# ============================================================
# Testing lib_text_buffer
# ============================================================

# Compile lib_text_buffer Test Executables

add_executable(test_lib_text_buffer lib_text_buffer.cpp )
target_link_libraries(test_lib_text_buffer PRIVATE lib_text)

# Register lib_text_buffer tests with CTest

add_test( NAME lib_text_buffer_empty_size COMMAND test_lib_text_buffer 1 )
add_test( NAME lib_text_buffer_thrice_appended_size COMMAND test_lib_text_buffer 2 )
add_test( NAME lib_text_buffer_thrice_appended_content COMMAND test_lib_text_buffer 3 )
add_test( NAME lib_text_buffer_append_insert_size COMMAND test_lib_text_buffer 4 )
add_test( NAME lib_text_buffer_append_insert_contents COMMAND test_lib_text_buffer 5 )
add_test( NAME lib_text_buffer_line_insert_text COMMAND test_lib_text_buffer 6 )


