cmake_minimum_required(VERSION 3.25)

include_directories(${PROJECT_SOURCE_DIR})
add_library(db DBConnection.cpp ClassThatUsesDB.cpp)
add_library(mysql SHARED IMPORTED)
set_property(TARGET mysql PROPERTY IMPORTED_LOCATION ${MYSQL_DIR}libmysqlclient.so)
add_executable(${PROJECT_NAME}  main.cpp DBConnection.cpp ClassThatUsesDB.cpp)

target_link_libraries(${PROJECT_NAME} mysql)
target_include_directories(${PROJECT_NAME} PUBLIC ${MYSQL_INCL})