add_library(menu_user menu_user.cc menu_user.h)
target_link_libraries(menu_user PUBLIC user)
target_link_libraries(menu_user PUBLIC global)
target_include_directories(menu_user PUBLIC ${CMAKE_CURRENT_LIST_DIR})
