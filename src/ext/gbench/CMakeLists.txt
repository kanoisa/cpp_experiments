include(FetchContent)
FetchContent_Declare(
        googlebench
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.7.0
)

set(BENCHMARK_ENABLE_TESTING OFF CACHE INTERNAL "Disable testing")

FetchContent_MakeAvailable(googlebench)
