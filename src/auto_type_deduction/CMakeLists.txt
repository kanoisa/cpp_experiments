add_executable(auto_type_deduction
        auto_type_deduction.cpp
        auto_type_deduction_answers.cpp
        )
target_link_libraries(auto_type_deduction
        PRIVATE
        cpp_experiments_options
        cpp_experiments_warnings
        gtest_main
        )
target_compile_features(auto_type_deduction INTERFACE cxx_std_17)
add_test(auto_type_deduction auto_type_deduction)
