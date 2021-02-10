add_executable(is_unique_test)
target_sources(is_unique_test
    PRIVATE is_unique.test.cpp
)
target_link_libraries(is_unique_test
    PRIVATE is_unique boost::ut
)
add_test(NAME is_unique_test COMMAND is_unique_test)
