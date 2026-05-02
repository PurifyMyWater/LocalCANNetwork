include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
        CANInterface
        GIT_REPOSITORY  git@github.com:PurifyMyWater/CANInterface.git
        GIT_TAG         adapt-canFrame-to-v2-driver
)
FetchContent_MakeAvailable(CANInterface)

FetchContent_Declare(
        OSInterface
        GIT_REPOSITORY  git@github.com:PurifyMyWater/OSInterface.git
        GIT_TAG         v0.2.1
)
FetchContent_MakeAvailable(OSInterface)

add_library(LocalCANNetwork STATIC)

file(GLOB LocalCANNetwork_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_sources(LocalCANNetwork PRIVATE ${LocalCANNetwork_SOURCES})
target_include_directories(LocalCANNetwork PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(LocalCANNetwork PUBLIC CANInterface)
target_link_libraries(LocalCANNetwork PUBLIC OSInterface)
