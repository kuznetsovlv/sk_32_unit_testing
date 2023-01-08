include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
add_library(GTest::GMock INTERFACE IMPORTED)
target_link_libraries(GTest::GMock INTERFACE gmock_main)

add_library(mysql SHARED IMPORTED)
set_property(TARGET mysql PROPERTY IMPORTED_LOCATION ${MYSQL_DIR}libmysqlclient.so)

add_executable(test_app test_app.cpp)

target_link_libraries(test_app
        PRIVATE
        GTest::GTest
        GTest::GMock
        db
        mysql)
target_include_directories(${PROJECT_NAME} PUBLIC ${MYSQL_INCL})

add_test(gtests test_app)