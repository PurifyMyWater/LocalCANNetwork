if (NOT ESP_PLATFORM) # Only configure tests if we are building in a computer.

    project(LocalCANNetwork_GoogleTests)

    include(FetchContent)
    set(FETCHCONTENT_QUIET OFF)

    FetchContent_Declare(
            googletest
            GIT_REPOSITORY  https://github.com/google/googletest.git
            GIT_TAG         v1.17.0
    )
    FetchContent_Declare(
            LinuxOSInterface
            GIT_REPOSITORY  git@github.com:purifymywater/LinuxOSInterface.git
            GIT_TAG         v0.2.1
    )
    FetchContent_MakeAvailable(googletest)
    FetchContent_MakeAvailable(LinuxOSInterface)

    include_directories("${gtest_SOURCE_DIR}/include" ".")

    file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

    # adding the Google_Tests_run target
    add_executable(LocalCANNetwork_GoogleTests ${TEST_SOURCES} ${TEST_UTILS_SOURCES})
    target_include_directories(LocalCANNetwork_GoogleTests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

    # linking Google_Tests_run with LocalCANNetwork which will be tested
    target_link_libraries(LocalCANNetwork_GoogleTests LocalCANNetwork LinuxOSInterface)

    target_link_libraries(LocalCANNetwork_GoogleTests gtest gtest_main)
endif ()
