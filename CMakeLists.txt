cmake_minimum_required(VERSION 3.13)
project(Genetic)

set(CMAKE_CXX_STANDARD 14)

add_executable(Genetic main.cpp Objects/Gladiator.cpp Objects/Gladiator.h Structures/LinkedList.cpp Structures/LinkedList.h Structures/Node.cpp Structures/Node.h Objects/Population.cpp Objects/Population.h Objects/Fitness.cpp Objects/Fitness.h Objects/Algorithm.cpp Objects/Algorithm.h Serializador/SerialPort.cpp Serializador/SerialPort.h)