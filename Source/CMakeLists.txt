include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
        CANInterface
        GIT_REPOSITORY  git@github.com:purifymywater/CANInterface.git
        GIT_TAG         v0.1.1
)
FetchContent_MakeAvailable(CANInterface)

add_library(LocalCANNetwork STATIC)

file(GLOB LocalCANNetwork_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

target_sources(LocalCANNetwork PRIVATE ${LocalCANNetwork_SOURCES})
target_include_directories(LocalCANNetwork PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(LocalCANNetwork PUBLIC CANInterface)
