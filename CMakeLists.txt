cmake_minimum_required(VERSION 3.1)
project(UNIX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(wav-write wav-write.cpp)
add_executable(wav-read wav-read.cpp)
add_executable(normalize normalize.cpp)
add_executable(remove-bias remove-bias.cpp)
add_executable(reverse reverse.cpp)
add_executable(cumulative-sum cumulative-sum.cpp)
add_executable(difference difference.cpp)
add_executable(sine sine.cpp)
add_executable(sine-sweep sine-sweep.cpp)
add_executable(noise noise.cpp)
add_executable(multiply multiply.cpp)
add_executable(tanh tanh.cpp)

## Add lines here to make new executable targets
