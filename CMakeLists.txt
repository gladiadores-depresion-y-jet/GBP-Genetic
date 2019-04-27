cmake_minimum_required(VERSION 3.13)
project(Genetic)

set(CMAKE_CXX_STANDARD 14)

add_executable(Genetic main.cpp Objects/Gladiator.cpp Objects/Gladiator.h Structures/LinkedList.cpp Structures/LinkedList.h Structures/Node.cpp Structures/Node.h)