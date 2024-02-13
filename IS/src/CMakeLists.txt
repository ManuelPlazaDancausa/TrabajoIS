# Enables testing with add_test() for this project
enable_testing()

add_subdirectory(directorAcademico)
add_subdirectory(evento)
add_subdirectory(menu_organizador)
add_subdirectory(menu_user)
add_subdirectory(menus)
add_subdirectory(organizador)
add_subdirectory(user)
add_subdirectory(userManager)
add_subdirectory(programa)
add_subdirectory(menu_director)
add_subdirectory(global)

add_executable(MiPrograma main.cc)

target_link_libraries(MiPrograma PRIVATE directorAcademico evento menu_director menu_organizador menu_user menus organizador programa user userManager)
target_link_libraries(MiPrograma PUBLIC global)
