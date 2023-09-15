cmake_minimum_required(VERSION 3.25)
project(wyy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        Network
        REQUIRED)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(wyy resource.qrc main.cpp utility/utility.h page/mainwindow.cpp page/mainwindow.h page/mainwindow.ui page/popupsearch.cpp page/popupsearch.h page/popupsearch.ui page/popupsearchitem.cpp page/popupsearchitem.h page/popupsearchitem.ui utility/utility.cpp page/slideshowwidget.cpp page/slideshowwidget.h page/slideshowwidget.ui page/slideshowbutton.cpp page/slideshowbutton.h page/slideshowview.cpp page/slideshowview.h page/slideshowitem.cpp page/slideshowitem.h page/galleryitem.h page/galleryitem.ui page/gallerywidget.cpp page/gallerywidget.h page/gallerywidget.ui page/messagewidget.cpp page/messagewidget.h page/messagewidget.ui page/messageitem.cpp page/messageitem.h page/messageitem.ui page/ranklistitem.cpp page/ranklistitem.h page/ranklistitem.ui page/ranklistwidget.cpp page/ranklistwidget.h page/ranklistwidget.ui page/podcastwidgetitem.cpp page/podcastwidgetitem.h page/podcastwidgetitem.ui page/podcastwidget.cpp page/podcastwidget.h page/podcastwidget.ui page/categoryselectbox.cpp page/categoryselectbox.h page/categoryselectbox.ui page/accountwidget.cpp page/accountwidget.h page/accountwidget.ui page/settingwidget.cpp page/settingwidget.h page/settingwidget.ui control/CustomComboBox.h page/favoritemusic.cpp page/favoritemusic.h page/favoritemusic.ui page/FavoriteMusicDelegate.h page/bottomwidget.cpp page/bottomwidget.h page/bottomwidget.ui page/newestmusic.cpp page/newestmusic.h page/newestmusic.ui control/newmusiclistitem.cpp control/newmusiclistitem.h control/newmusiclistitem.ui control/customsearchbox.cpp control/customsearchbox.h control/customsearchbox.ui)

target_link_libraries(wyy
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::Network
        )

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Multimedia Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
