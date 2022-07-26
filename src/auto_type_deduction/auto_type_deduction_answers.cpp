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

class AutoTypeDeductionAnswer : public ::testing::Test {
protected:
    value_holder<int> vh;
};

/**********************************************************************************************************************
 * Plain auto
 * auto x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoReturnByValue) {
    auto value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int>));
}

TEST_F(AutoTypeDeductionAnswer, AutoReturnByReference) {
    auto value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int>));
}

TEST_F(AutoTypeDeductionAnswer, AutoReturnByConstReference) {
    auto value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int>));
}

TEST_F(AutoTypeDeductionAnswer, AutoReturnByPointer) {
    auto value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int*>));
}

TEST_F(AutoTypeDeductionAnswer, AutoReturnByPointerToConst) {
    auto value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const*>));
}


/**********************************************************************************************************************
 * Auto const (East side cost)
 * auto const x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoEastConstReturnByValue) {
    auto const value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoEastConstReturnByReference) {
    auto const value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoEastConstReturnByConstReference) {
    auto const value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoEastConstReturnByPointer) {
    auto const value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int *const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoEastConstReturnByPointerToConst) {
    auto const value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const* const>));
}


/**********************************************************************************************************************
 * Auto const (West side cost)
 * const auto x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoWestConstReturnByValue) {
    const auto value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoWestConstReturnByReference) {
    const auto value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoWestConstReturnByConstReference) {
    const auto value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoWestConstReturnByPointer) {
    const auto value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int * const>));
}

TEST_F(AutoTypeDeductionAnswer, AutoWestConstReturnByPointerToConst) {
    const auto value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const * const>));
}


/**********************************************************************************************************************
 * Auto ref
 * auto& x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoRefReturnByReference) {
    auto& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int &>));
}

TEST_F(AutoTypeDeductionAnswer, AutoRefReturnByConstReference) {
    auto& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const&>));
}


/**********************************************************************************************************************
 * Auto const ref
 * auto const& x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoConstRefReturnByValue) {
    auto const& value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoConstRefReturnByReference) {
    auto const& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoConstRefReturnByConstReference) {
    auto const& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoConstRefReturnByPointer) {
    auto const& value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int * const&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoConstRefReturnByPointerToConst) {
    auto const& value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const * const&>));
}


/**********************************************************************************************************************
 * Auto universal ref
 * auto && x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoUniversalRefReturnByValue) {
    auto&& value{vh.get_T()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int&&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoUniversalRefReturnByReference) {
    auto&& value{vh.get_T_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoUniversalRefReturnByConstReference) {
    auto&& value{vh.get_T_const_ref()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoUniversalRefReturnByPointer) {
    auto&& value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int * &&>));
}

TEST_F(AutoTypeDeductionAnswer, AutoUniversalRefReturnByPointerToConst) {
    auto&& value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const * &&>));
}


/**********************************************************************************************************************
 * Auto pointer
 * auto * x = ...
 *
 */
TEST_F(AutoTypeDeductionAnswer, AutoPointerReturnByPointer) {
    auto* value{vh.get_T_ptr()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int *>));
}

TEST_F(AutoTypeDeductionAnswer, AutoPointerReturnByPointerToConst) {
    auto* value{vh.get_T_ptr_to_const()};

    ASSERT_TRUE((std::is_same_v<decltype(value), int const *>));
}
