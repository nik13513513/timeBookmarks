cmake_minimum_required(VERSION 3.5)

project(timeBookmarks)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOQRC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Concurrent REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

FILE (GLOB HDR
    Widget.h
    RulerView.h
    BookmarkManager.h
    BookmarkGraphicItem.h
	IStorage.h
	setStorage.h
)

FILE (GLOB FORMS
    Widget.ui
)

FILE (GLOB SRC
    main.cpp
    Widget.cpp
    RulerView.cpp
    BookmarkManager.cpp
    BookmarkGraphicItem.cpp
	IStorage.cpp
	setStorage.cpp
)

add_executable(${PROJECT_NAME} ${SRC} ${HDR} ${FORMS})

source_group("SRC" FILES ${SRC})
source_group("HDR" FILES ${HDR})
source_group("FORM" FILES ${FORMS})

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
	Qt5::Concurrent
)
