if (DEFINED ENV{GLM_ROOT_DIR})
    SET(GLM_ROOT_DIR "$ENV{GLM_ROOT_DIR}")
else()
    SET(GLM_ROOT_DIR ${GLG_EXTERNALS_DIR})
endif()

if (DEFINED ENV{DOCTEST_ROOT_DIR})
    SET(DOCTEST_ROOT_DIR "$ENV{DOCTEST_ROOT_DIR}")
else()
    SET(DOCTEST_ROOT_DIR ${GLG_EXTERNALS_DIR})
endif()

find_package(GLM REQUIRED)
find_package(DOCTEST REQUIRED)

file(GLOB_RECURSE TEST_FILES */*.cpp *.cpp)

add_executable(glg_test ${TEST_FILES})

target_link_libraries(glg_test glg)

include_directories(glg_test ${DOCTEST_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})