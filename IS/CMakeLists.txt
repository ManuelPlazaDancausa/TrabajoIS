#Definicion de proyecto y version de cmake
cmake_minimum_required(VERSION 3.10)

project(proyecto_IS)

#Estandarización de versión
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Tests
enable_testing()

#Ficheros incluidos
add_subdirectory(src)
#add_subdirectory(tests)
