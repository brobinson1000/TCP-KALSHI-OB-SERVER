
cmake_minimum_required(VERSION 3.10)


project(TCP_KALSHI_OB_SERVER)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(main
    src/main.cpp
    src/add_bid.cpp
    src/print_orderbook.cpp
    src/resolve_bid.cpp
    src/save_bin_snap.cpp
    src/replay_bin_snap.cpp
    src/periodic_save.cpp
)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

