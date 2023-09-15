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
add_executable(wyy resource.qrc main.cpp utility/utility.h mainwindow.cpp mainwindow.h mainwindow.ui popupsearch.cpp popupsearch.h popupsearch.ui popupsearchitem.cpp popupsearchitem.h popupsearchitem.ui utility/utility.cpp slideshowwidget.cpp slideshowwidget.h slideshowwidget.ui slideshowbutton.cpp slideshowbutton.h slideshowview.cpp slideshowview.h slideshowitem.cpp slideshowitem.h galleryitem.h galleryitem.ui gallerywidget.cpp gallerywidget.h gallerywidget.ui messagewidget.cpp messagewidget.h messagewidget.ui messageitem.cpp messageitem.h messageitem.ui ranklistitem.cpp ranklistitem.h ranklistitem.ui ranklistwidget.cpp ranklistwidget.h ranklistwidget.ui podcastwidgetitem.cpp podcastwidgetitem.h podcastwidgetitem.ui podcastwidget.cpp podcastwidget.h podcastwidget.ui categoryselectbox.cpp categoryselectbox.h categoryselectbox.ui accountwidget.cpp accountwidget.h accountwidget.ui settingwidget.cpp settingwidget.h settingwidget.ui control/CustomComboBox.h favoritemusic.cpp favoritemusic.h favoritemusic.ui FavoriteMusicDelegate.h bottomwidget.cpp bottomwidget.h bottomwidget.ui newestmusic.cpp newestmusic.h newestmusic.ui control/newmusiclistitem.cpp control/newmusiclistitem.h control/newmusiclistitem.ui control/customsearchbox.cpp control/customsearchbox.h control/customsearchbox.ui)

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
