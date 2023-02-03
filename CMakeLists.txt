cmake_minimum_required(VERSION 3.24)
project(msdScript1)

set(CMAKE_CXX_STANDARD 14)

include_directories(msdScriptCommandLine)

add_executable(msdScript1
        msdScriptCommandLine/catch.hpp
        msdScriptCommandLine/cmdline.cpp
        msdScriptCommandLine/cmdline.hpp
        msdScriptCommandLine/expr.cpp
        msdScriptCommandLine/expr.hpp
        msdScriptCommandLine/main.cpp msdScriptCommandLine/test.cpp)
