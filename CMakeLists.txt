cmake_minimum_required(VERSION 3.23)
project(mushroom)

set(CMAKE_CXX_STANDARD 14)

add_executable(mushroom src/main.cpp src/lexer/Lexer.cpp src/lexer/Lexer.h src/lexer/Tokens.h src/lexer/Tokens.cpp src/App.cpp src/App.h src/logging/Logger.cpp src/logging/Logger.h)
