cmake_minimum_required(VERSION 3.17)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_COLOR_MAKEFILE ON)
set(spdlog_DIR spdlog/build)
set(NAME redCodeEngine)

project(${NAME}Engine
LANGUAGES CXX
VERSION 0.1
DESCRIPTION "Game Engine to learn"
)

find_package(Threads)

## Includes
include_directories(./include)
include_directories(./include/utils)
include_directories(./include/Core)


include_directories(./include/Core/Components)
include_directories(./include/Core/Components/Manager)
include_directories(./include/Core/Components/Pool)

include_directories(./include/Core/Entity)
include_directories(./include/Core/Entity/Manager)
include_directories(./include/Core/Entity/utils)
include_directories(./include/Core/Entity/Pool)

include_directories(./include/Core/Systems)
include_directories(./include/Core/Systems/Manager)

include_directories(./src/Core/Allocators)
include_directories(./loguru)
#find_package(
#        Boost 1.65 REQUIRED
#        COMPONENTS test
#)
#
#install(PROGRAMS ${Boost_LIBRARIES} DESTINATION ./lib)

set(SRCS
        loguru/loguru.cpp
        src/utils/Clock.cpp
        src/Core/Engine.cpp
        src/Core/Entity/Manager/EntityManager.cpp
        src/Core/Components/Manager/ComponentManager.cpp
        src/Core/Systems/Manager/SystemManager.cpp
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
add_library(${NAME}
        ${SRCS}
)

#add_executable(${NAME} ${SRCS})
target_link_libraries(${NAME} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${NAME} dl)
target_include_directories(${NAME} PRIVATE .)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
# set_target_properties(${NAME} PROPERTIES VERSION ${PROJECT_VERSION})

#install (TARGETS ${NAME}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#        PUBLIC_HEADER_DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (MVSVC)
        target_compile_options(${NAME} PRIVATE /W4 /WX)
else ()
        target_compile_options(${NAME} PRIVATE -Wall -Wextra -std=c++11 -lpthread -ldl)
        add_compile_options(-ldl)
endif()
