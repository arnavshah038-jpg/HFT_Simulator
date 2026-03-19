cmake_minimum_required(VERSION 3.10)
project(HFT_Simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3") # Speed ke liye -O3 optimization

include_directories(include)

add_executable(hft_sim 
    src/main.cpp 
    src/OrderBook.cpp
)