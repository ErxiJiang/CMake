cmake_minimum_required(VERSION 3.17)
project(CMakeLib)

# 增加一个Private库。这行指令将使PrivateLibrary中的CMakeLists.txt文件生效。
add_subdirectory(PrivateLibrary)
# 使用子项目来增加库
add_subdirectory(Library)
# 使用子项目来增加执行文件
add_subdirectory(Main)

# 增加一个库
#add_library(Lib lib.h lib.cpp)
# 这个PUBLIC我知道是怎么回事了。如果指定为Private，那么，当main.cpp中使用target_link_libraries指令的时候，main.cpp并不会“继承”这个库所引用的Header文件。
# 换句话说，将其指定的PUBLIC，可以让外面使用这个库的程序使用include中的头文件。
#target_include_directories(Lib PUBLIC ./)

# 这也是Private的一个用法，如果用PRIVATE来连接一个库，那么在main.cpp中是看不到Private_Lib中的东西的。
#target_link_libraries(Lib PRIVATE PrivateLibrary)


# 自定义的目标（使用COMMAND指令可以执行一些外部的程序，详细查询AI吧，教程中没讲）
# add_custom_target(MyTarget COMMAND ???)
