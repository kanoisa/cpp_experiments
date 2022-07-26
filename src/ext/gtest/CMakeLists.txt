include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG f079775276a99fd4373569bf5761052a01844270
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
if (NOT googletest_POPULATED)
    FetchContent_MakeAvailable(googletest)
endif ()

if (ENABLE_SANITIZER_MEMORY)
    # When building gtest / gmock with msan enabled you will get false positives all over the show unless everything is
    # built with msan instrumentation. hackpp_options should be properly configured with extra compiler and linker
    # flags and options, so linking to that should be enough.
    target_link_libraries(gtest PRIVATE hackpp_options)
    target_link_libraries(gmock PRIVATE hackpp_options)
endif ()
