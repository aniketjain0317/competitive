cmake_minimum_required(VERSION 3.13)
project(Compiler C)

set(CMAKE_C_STANDARD 99)

add_executable(Compiler driver.c ast.c parser.c lexer.c symbol.c typeChecker.c icg.c CodeGenerator.c)
target_link_libraries(Compiler m)