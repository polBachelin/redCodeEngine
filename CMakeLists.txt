cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_COLOR_MAKEFILE ON)
set(NAME recCode)

project(${NAME}Engine
        LANGUAGES CXX
        VERSION 0.1
        DESCRIPTION "Game Engine to learn"
        )

## Includes
include_directories(./include)
include_directories(./src)

find_package(
        Boost 1.65 REQUIRED
        COMPONENTS test
)

install(PROGRAMS ${Boost_LIBRARIES} DESTINATION ./lib)

set(SRCS
        src/Core/Allocators/Allocator.cpp
)

add_library(${NAME} SHARED
        ${SRCS}
)

target_include_directories(${NAME} PRIVATE .)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
#set_target_properties(${NAME} PROPERTIES VERSION ${PROJECT_VERSION})

#install (TARGETS ${NAME}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#        PUBLIC_HEADER_DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (MVSVC)
        target_compile_options(${NAME} PRIVATE /W4 /WX)
else ()
        target_compile_options(${NAME} PRIVATE -Wall -Wextra)
endif()
