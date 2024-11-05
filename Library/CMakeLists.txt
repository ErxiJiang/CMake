project(Library)

add_library(${PROJECT_NAME}
    ./include/lib.h
    ./src/lib.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ./include
    PRIVATE ./src
)

# 这也是Private的一个用法，如果用PRIVATE来连接一个库，那么在main.cpp中是看不到Private_Lib中的东西的。
target_link_libraries(${PROJECT_NAME} PRIVATE PrivateLibrary)