add_library(userManager userManager.cc userManager.h)
target_link_libraries(userManager PUBLIC user)
target_link_libraries(userManager PUBLIC global)
target_include_directories(userManager PUBLIC ${CMAKE_CURRENT_LIST_DIR})

