cmake_minimum_required(VERSION 3.10)
project(ErableCompiler)

set(CMAKE_CXX_STANDARD 17)
#OPTION(USE_OpenMP "Use OpenMP to enamble <omp.h>" ON)

#[[# Find OpenMP
if(APPLE AND USE_OpenMP)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(OpenMP_C ${CMAKE_C_COMPILER})
        set(OpenMP_C_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
        set(OpenMP_C_LIB_NAMES "libomp" "libgomp" "libiomp5")
        set(OpenMP_libomp_LIBRARY ${OpenMP_C_LIB_NAMES})
        set(OpenMP_libgomp_LIBRARY ${OpenMP_C_LIB_NAMES})
        set(OpenMP_libiomp5_LIBRARY ${OpenMP_C_LIB_NAMES})
    endif()
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(OpenMP_CXX ${CMAKE_CXX_COMPILER})
        set(OpenMP_CXX_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
        set(OpenMP_CXX_LIB_NAMES "libomp" "libgomp" "libiomp5")
        set(OpenMP_libomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        set(OpenMP_libgomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        set(OpenMP_libiomp5_LIBRARY ${OpenMP_CXX_LIB_NAMES})
    endif()
endif()
if(USE_OpenMP)
    find_package(OpenMP REQUIRED)
endif(USE_OpenMP)]]


include_directories(.)
include_directories(..)
include_directories(../Global)
include_directories(../include)
set(ERABLE_PARSE_TABLE_PATH ${CMAKE_INSTALL_PREFIX}/ErableParseTable.pt)
add_definitions(-DERABLE_MAJOR=1 -DERABLE_MINOR=0 -DERABLE_PARSE_TABLE_PATH="${ERABLE_PARSE_TABLE_PATH}")
#link_directories(${OPENMP_DIRECTORES})
#include_directories(/usr/local/Cellar/leveldb/1.22/include)
set(EXECUTABLES
        Lexer/Tokens.cpp Lexer/Tokens.hpp
        Lexer/Lexer.cpp Lexer/Lexer.hpp
        Scanner.hpp
        #[[Old_Parser.cpp Old_Parser.hpp Old_Symbols.cpp Old_Symbols.hpp Old_Syntax.cpp Old_Syntax.hpp]]
        ProcessedData.cpp ProcessedData.hpp
        AST.cpp AST.hpp
        ID.cpp ID.hpp
        Headers.hpp
        Lexer/Symbols.cpp Lexer/Symbols.hpp
        Syntax.cpp Syntax.hpp
        Parser/ParseTable.cpp Parser/ParseTable.hpp
        Parser/ParseTableOutput.cpp Parser/ParseTableOutput.hpp
        Parser/ParseTableIO.cpp Parser/ParseTableIO.hpp
        Parser/ParseTableInput.cpp Parser/ParseTableInput.hpp
        Parser/Parser.cpp Parser/Parser.hpp
        #[[Parser/.IntList.cpp Parser/.IntList.hpp]]
        Parser/MultiStack.cpp Parser/MultiStack.hpp
        )
add_executable(ErableCompiler main.cpp ${EXECUTABLES})
add_library(ErableCompilerDyn SHARED ${EXECUTABLES})
add_library(ErableCompilerStatic STATIC ${EXECUTABLES})

#add_subdirectory(tests)

message("Prefix: ${ERABLE_PARSE_TABLE_PATH}")

#link_libraries(${LevelDB})

set_property(TARGET ErableCompiler PROPERTY CXX_STANDARD 17)
#
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
#link_libraries(openmp)
#if (OPENMP_FOUND)
#    message("FOUND OPENMP")
#    include_directories(${OPENMP_INCLUDES})
#    link_directories(${OPENMP_LIBRARIES})
#    link_libraries(${OPENMP_LIBRARIES})
#    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#    # set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
#endif(OPENMP_FOUND)
