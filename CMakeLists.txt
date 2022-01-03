cmake_minimum_required(VERSION 3.21)
project(Androsix C)

set(CMAKE_C_STANDARD 99)

add_executable(Androsix
        includes.h
        mno/main_operations.c mno/main_operations.h mno/main_commands.h
        flt/filetransfer_operations.c flt/filetransfer_operations.h flt/filetransfer_commands.h
        dbg/debugging_operations.c dbg/debugging_operations.h dbg/debugging_commands.h
        androsix.h)