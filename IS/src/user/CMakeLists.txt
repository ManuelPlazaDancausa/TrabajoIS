add_library(user user.cc user.h)
target_include_directories(user PUBLIC ${CMAKE_CURRENT_LIST_DIR})