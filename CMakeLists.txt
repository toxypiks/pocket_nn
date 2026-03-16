cmake_minimum_required(VERSION 3.16)
project(pocket_nn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(MAIN_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
  )

add_executable(main)
target_sources(main
 PRIVATE
  ${MAIN_SRC}
)

set(NN_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/nn.c
  ${CMAKE_CURRENT_SOURCE_DIR}/include/nn.h
)

add_library(nn)
target_sources(nn
 PRIVATE
  ${NN_SRC}
  )

target_include_directories(nn
 PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
