project(reMarkable-Qt) 

set(CMAKE_CXX_STANDARD 11) 
cmake_minimum_required(VERSION 3.18)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to run uic automatically when needed.
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCES
    main.cpp
    remarkablefilecontent.cpp
    mainwindow.cpp
    remarkablessh.cpp
    remarkableuserdata.cpp
)
set(HEADERS
    remarkablefilecontent.h
    remarkablessh.h
    remarkableuserdata.h
    mainwindow.h
    utilities.h
)
set(UI mainwindow.ui)
set(RESOURCE resources.qrc)
qt5_add_resources(RESOURCE_ADDED ${RESOURCE})

add_executable(remarkable-qt ${SOURCES} ${HEADERS} ${UI} ${RESOURCE_ADDED})
target_link_libraries(remarkable-qt Qt5::Widgets -luuid)