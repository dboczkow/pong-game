cmake_minimum_required(VERSION 3.15)
project(
  pong
  VERSION 0.0.0
  DESCRIPTION "Simple pong game"
  LANGUAGES CXX)

find_package(SDL2 REQUIRED CONFIG)

add_executable(
  pong
  src/main.cpp
)

# Main SDL library for init
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
