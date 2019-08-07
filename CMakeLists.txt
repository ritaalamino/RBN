cmake_minimum_required(VERSION 2.8)
project(RBN)

include_directories(include)

add_library(rbn_net SHARED
  "src/network/util/node.cc"
  "src/network/rbn.cc"
  "src/io/rbnexport.cc")

add_executable(myExec "src/main.cpp")
target_link_libraries(myExec rbn_net)