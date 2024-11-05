# 主程序
project(Exe)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./include/main.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ./include
)

# 正常情况下会出现找不到.h的情况，这里我们不使用 target_include_directories(Exe PUBLIC ./) 指使
# 而是使用link指令，这样：
target_link_libraries(${PROJECT_NAME} PUBLIC Library)

# 使用遍历来设置多个执行文件
file(GLOB_RECURSE EXAMPLE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
foreach(EXAMPLE_FILE IN LISTS EXAMPLE_SOURCES)
    # 获得文件名做为项目名
    get_filename_component(NAME_ONLY ${EXAMPLE_FILE} NAME_WE) # NAME_WE = Name without extension
    message(STATUS ${NAME_ONLY})    

    # 其它的和创建项目同样
    project(${NAME_ONLY})

    add_executable(${NAME_ONLY} ${EXAMPLE_FILE})

    target_include_directories(${PROJECT_NAME} PUBLIC ./include)

    target_link_libraries(${NAME_ONLY} PUBLIC Library)
endforeach()
