find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(THIS ${PROJECT_NAME}-list-test)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/container/source/list.c
    case/example-test.cpp
    unit/back-test.cpp
    unit/front-test.cpp
    unit/object-test.cpp
    unit/at-test.cpp
)

add_executable(${THIS} ${SOURCE_FILES})

target_include_directories(${THIS} PRIVATE ${PROJECT_SOURCE_DIR}/container/include)

target_link_libraries(${THIS} PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_test(NAME ${THIS} COMMAND ${THIS})
    