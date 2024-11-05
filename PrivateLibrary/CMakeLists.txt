# 使用子项目文件
project(PrivateLibrary)

# 使用Globbing Patterns
# 要使用这个的时候需要注意，有时候增加文件不能被即时识别，需要重新生成一次Build的项目。
# 还有一种方法是将 CONFIGURE_DEPENDS加到HEADERS后面，但是这样导致每次生成都需要重新生成配置。这和CMake的“配置/生成”分离的精神不合！
file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file (GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# 看看对不对
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS ${HEADERS})
message(STATUS ${SOURCES})

# 这里使用PROJECT_NAME来增加
add_library(${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

# 设置包含目录。这里分开了两个，一个将Header目录公开，将Src的目录隐藏（即在Src中的头文件是隐藏的）。
target_include_directories(${PROJECT_NAME}
    PUBLIC ./include
    PRIVATE ./src
)