cmake_minimum_required(VERSION 3.27)
project(BindingOfIsaac-Internal)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-D_DEBUG -D_CONSOLE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DNDEBUG -D_CONSOLE)
endif()

include_directories(${CMAKE_SOURCE_DIR})
set(SOURCE_FILES
        src/entrypoint.cpp
        src/classes/classes.h
        src/hooks/wndproc.cpp
        src/hooks/wndproc.h
)

add_definitions(-D_MBCS)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})