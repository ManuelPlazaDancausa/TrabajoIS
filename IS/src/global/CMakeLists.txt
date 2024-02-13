add_library(global global.cc global.h)
target_link_libraries(global PUBLIC user)
target_link_libraries(global PUBLIC evento)
target_include_directories(global PUBLIC ${CMAKE_CURRENT_LIST_DIR})