# In un file CMakeLists.txt si deve innanzitutto specificare la versione
# minima di CMake necessaria per compilare il progetto. Nel nostro caso
# specifichiamo 3.20
cmake_minimum_required(VERSION 3.20)

project(esercitazione1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(figura1prog figura1.cpp)
add_executable(algoprog esercizio_algoritmi.cpp)
