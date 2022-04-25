cmake_minimum_required(VERSION 3.5)
#指定项目名称，
#注：一旦使用了project指令指明了一个项目名称，则同时隐式定义了两个预定义变量：PROJECT_BINARY_DIR和PROJECT_SOURCE_DIR
#注：推荐使用外部构建的方法，在build或cmake目录中构建工程，区分上述两个目录，使得整个项目的结构较为清晰分明。
project(Test VERSION 0.1 LANGUAGES CXX)

#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 设置自动生成ui.h文件,AUTOUIC打开可以省去QT5_WRAP_UI命令
set(CMAKE_AUTOUIC ON)
# 设置自动生成moc文件,AUTOMOC打开可以省去QT5_WRAP_CPP命令
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#使用标志位CMAKE_CXX_STANDARD_REQUIRED和CMAKE_CXX_STANDARD指定编译器的使用版本
#指定使用C++11版本
set(CMAKE_CXX_STANDARD 11)
add_definitions("-Wall -g")
# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THIRDPARTY_DIR /home/cc/Qt5.12.11/ThirdParty/QtXlsxWriter-master/)
INCLUDE_DIRECTORIES(./Inc)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#使用find_package引入外部依赖包
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools Sql Xlsx REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Sql Xlsx REQUIRED)

if(Qt5_FOUND)
    #message(${Qt5Xlsx_INCLUDE_DIRS})
endif()

set(TS_FILES Test_en_US.ts)

file(GLOB SRC_LIST ./Src/*.cpp ./Src/*.c)
file(GLOB INC_LIST ./Inc/*.h ./ThirdParty/xlsx/xlsxdocument.h)

set(PROJECT_SOURCES       
        ./Src/mainwindow.ui        
        ./Src/operatewindow.ui        
        Pic.qrc
        ${TS_FILES}
        ${SRC_LIST}
        ${INC_LIST}
)
#message(${PROJECT_SOURCE_DIR})
#message(${PROJECT_BINARY_DIR})
#message(${THIRDPARTY_DIR})
#message("Qt${QT_VERSION_MAJOR}::Widgets")
#message(${PROJECT_SOURCES})

#设置可执行文件的存放路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/bin)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Test SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Test
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()
#CMake中target_link_libraries的PRIVATE，PUBLIC和INTERFACE的区别
#1、只有源文件中包含了库文件        PRIVATE
#2、只有头文件中包含了库文件        INTERFACE
#3、源文件和头文件都包含了库文件     PUBLIC
target_link_libraries(Test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql -lsqlite3 Qt${QT_VERSION_MAJOR}::Xlsx)

set_target_properties(Test PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Test)
endif()
