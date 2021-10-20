
file(GLOB_RECURSE _test_srcs ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(ndsu_test ${_test_srcs})
unset(_test_srcs)

find_package(GTest)
find_package(Threads)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(ndsu_test ${GTEST_LIBRARIES})

enable_testing()
add_test(NAME ndsu_test
         COMMAND ndsu_test)
