cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(Atmosphere VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++ 标准 (Qt 6 推荐 C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)     # 自动处理 MOC
set(CMAKE_AUTORCC ON)     # 自动处理资源文件
set(CMAKE_AUTOUIC ON)     # 自动处理 UI 文件

# 查找 Qt 组件
find_package(Qt6 COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets REQUIRED)

# 设置源文件
set(SOURCES
    main.cpp
    MainWindow.cpp
    Utilities/OpenGLWidget.cpp
    Utilities/OpenGLVersion.cpp
    Utilities/InputManager.cpp
    Utilities/ShaderProgram.cpp
    Utilities/ShaderManager.cpp
    Utilities/DataBuffer.cpp
    Utilities/Geometry/Mesh.cpp
    Utilities/Geometry/Quad.cpp
    Utilities/Geometry/Cube.cpp
    Utilities/Geometry/Sphere.cpp
    Utilities/DUpdateEvent.cpp
    Utilities/OpenGLFrameTimer.cpp
    DrawCanvas.cpp
    Utilities/Entity.cpp
    Utilities/Transform3D.cpp
    Utilities/Camera3D.cpp
    Utilities/ThirdPersonCamera.cpp
    Utilities/Player.cpp
    Demo/Demo.cpp
    AtmosphereModel/AtmosphereModel.cpp
    Utilities/OpenGLTexture.cpp
    Demo/GodCamera.cpp
    Demo/RawShaderProgram.cpp
)

# 设置头文件
set(HEADERS
    MainWindow.h
    Utilities/OpenGLWidget.h
    Utilities/OpenGLVersion.h
    Utilities/InputManager.h
    Utilities/ShaderProgram.h
    Utilities/ShaderManager.h
    Utilities/DataBuffer.h
    Utilities/Geometry/Mesh.h
    Utilities/Geometry/Quad.h
    Utilities/Geometry/Cube.h
    Utilities/Geometry/Sphere.h
    Utilities/DUpdateEvent.h
    Utilities/OpenGLFrameTimer.h
    DrawCanvas.h
    Utilities/Entity.h
    Utilities/Transform3D.h
    Utilities/Camera3D.h
    Utilities/ThirdPersonCamera.h
    Utilities/Player.h
    Demo/Demo.h
    AtmosphereModel/AtmosphereModel.h
    AtmosphereModel/Constants.h
    Utilities/OpenGLTexture.h
    Demo/GodCamera.h
    Demo/RawShaderProgram.h
)

# UI 文件
set(FORMS
    MainWindow.ui
)

# 资源文件
set(RESOURCES
    resource.qrc
)

# 添加可执行目标
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${RESOURCES}
)

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)

# 添加编译器定义 (对应 DEFINES += QT_DEPRECATED_WARNINGS)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    QT_DEPRECATED_WARNINGS
)

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/Geometry
    ${CMAKE_CURRENT_SOURCE_DIR}/AtmosphereModel
    ${CMAKE_CURRENT_SOURCE_DIR}/Demo
)

# macOS 特定配置
if(APPLE)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.Atmosphere")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}")
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}")
    set(MACOSX_BUNDLE_ICON_FILE "app.icns")
    
    # set_target_properties(${PROJECT_NAME} PROPERTIES
    #     MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist
    #     MACOSX_BUNDLE ON
    # )
endif()
