cmake_minimum_required(VERSION 3.16)

project(assignment8_3__2_QC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(assignment8_3__2_QC main.cpp
    all_classes.h)
#    all_classes.h)

include(GNUInstallDirs)
install(TARGETS assignment8_3__2_QC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
