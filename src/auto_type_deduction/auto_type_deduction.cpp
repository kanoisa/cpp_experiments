/**
 * @brief A series of tests to develop intuition about how the type of auto object is deduced. Tests are split into
 * sections based on the set of qualifiers being used with auto. For each `TEST_F` replace `not_answered` with the
 * type you think will be deduced. When the test passes you have determined the correct type deduced by auto.
 *
 * Note some of the answer will probably really surprise you. Consider the following resources:
 * https://en.cppreference.com/w/cpp/language/auto
 *      in the type specifier sequence of a variable: auto x = expr; as a type specifier. The type is deduced from the
 *      initializer. If the placeholder type specifier is auto or type-constraint auto (since C++20), the variable type
 *      is deduced from the initializer using the rules for template argument deduction from a function call (see
 *      template argument deduction — other contexts for details). For example, given const auto& i = expr;, the type
 *      of i is exactly the type of the argument u in an imaginary `template template<class U> void f(const U& u)`
 *      if the function call f(expr) was compiled. Therefore, auto&& may be deduced either as an lvalue reference or
 *      rvalue reference according to the initializer, which is used in range-based for loop.
 *
 * Video resources:
 * Jason Turner C++ Weekly - Ep 287: https://www.youtube.com/watch?v=tn69TCMdYbQ
 *
 */

#include <type_traits>

#include <gtest/gtest.h>

template<typename T>
struct value_holder {
    T value;

    T get_T() {
        return value;
    }
    T& get_T_ref() {
        return value;
    }
    T const& get_T_const_ref() {
        return value;
    }
    T* get_T_ptr() {
        return &value;
    }
    T const* get_T_ptr_to_const() {
        return &value;
    }
};

struct not_answered {
    float x;
};

class AutoTypeDeduction : public ::testing::Test {
protected:
    value_holder<int> vh;
};


/**********************************************************************************************************************
 * Examples.
 *
 * Shows how to fill in the vlues for your answers into std::is_same_v.
 *
 */
TEST_F(AutoTypeDeduction, DirectReturnTypes) {
    ASSERT_TRUE((std::is_same_v<decltype(vh.get_T()), int>));
    ASSERT_TRUE((std::is_same_v<decltype(vh.get_T_ref()), int&>));
    ASSERT_TRUE((std::is_same_v<decltype(vh.get_T_const_ref()), int const&>));
    ASSERT_TRUE((std::is_same_v<decltype(vh.get_T_ptr()), int*>));
    ASSERT_TRUE((std::is_same_v<decltype(vh.get_T_ptr_to_const()), int const*>));
}


/**********************************************************************************************************************
 * Plain auto
 * auto x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoReturnByValue) {
    auto value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoReturnByReference) {
    auto value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoReturnByConstReference) {
    auto value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoReturnByPointer) {
    auto value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoReturnByPointerToConst) {
    auto value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto const (East side cost)
 * auto const x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoEastConstReturnByValue) {
    auto const value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoEastConstReturnByReference) {
    auto const value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoEastConstReturnByConstReference) {
    auto const value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoEastConstReturnByPointer) {
    auto const value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoEastConstReturnByPointerToConst) {
    auto const value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto const (West side cost)
 * const auto x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoWestConstReturnByValue) {
    const auto value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoWestConstReturnByReference) {
    const auto value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoWestConstReturnByConstReference) {
    const auto value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoWestConstReturnByPointer) {
    const auto value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoWestConstReturnByPointerToConst) {
    const auto value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto ref
 * auto& x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoRefReturnByReference) {
    auto& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoRefReturnByConstReference) {
    auto& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto const ref
 * auto const& x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoConstRefReturnByValue) {
    auto const& value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoConstRefReturnByReference) {
    auto const& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoConstRefReturnByConstReference) {
    auto const& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoConstRefReturnByPointer) {
    auto const& value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoConstRefReturnByPointerToConst) {
    auto const& value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto universal ref
 * auto && x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoUniversalRefReturnByValue) {
    auto&& value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoUniversalRefReturnByReference) {
    auto&& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoUniversalRefReturnByConstReference) {
    auto&& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoUniversalRefReturnByPointer) {
    auto&& value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoUniversalRefReturnByPointerToConst) {
    auto&& value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}


/**********************************************************************************************************************
 * Auto pointer
 * auto * x = ...
 *
 */
TEST_F(AutoTypeDeduction, AutoPointerReturnByPointer) {
    auto* value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}

TEST_F(AutoTypeDeduction, AutoPointerReturnByPointerToConst) {
    auto* value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), not_answered>));
}
