cmake_minimum_required(VERSION 3.8)
project(C_Projects)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c buildTree.c buildTree.h treeStructure.h valueTree.c valueTree.h writeTree.c writeTree.h test.c test.h destroyTree.c destroyTree.h)
add_executable(C_Projects ${SOURCE_FILES})