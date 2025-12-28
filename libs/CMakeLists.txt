add_library(MyLib b.cpp)
target_include_directories(MyLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})