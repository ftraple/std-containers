find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(THIS ${PROJECT_NAME}-vector-test)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/container/source/vector.c
    unit/at-test.cpp
    unit/back-test.cpp
    unit/capacity-test.cpp
    unit/clear-test.cpp
    unit/data-test.cpp
    unit/emplace-back-test.cpp
    unit/empty-test.cpp
    unit/erase-range-test.cpp
    unit/erase-test.cpp
    unit/front-test.cpp
    unit/insert-test.cpp
    unit/object-test.cpp
    unit/pop-back-test.cpp
    unit/push-back-test.cpp
    unit/reserve-test.cpp
    unit/resize-test.cpp
    unit/shrink-to-fit-test.cpp
    unit/size-test.cpp
    unit/swap-test.cpp
)

add_executable(${THIS} ${SOURCE_FILES})

target_include_directories(${THIS} PRIVATE ${PROJECT_SOURCE_DIR}/container/include)

target_link_libraries(${THIS} PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

add_test(NAME ${THIS} COMMAND ${THIS})
    