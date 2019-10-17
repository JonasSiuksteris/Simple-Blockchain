cmake_minimum_required(VERSION 3.12)
project(Blockchainv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blockchainv2 main.cpp Block.h Blockchain.h Block.cpp Blockchain.cpp Transactions.cpp User.h User.cpp)