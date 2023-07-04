cmake_minimum_required(VERSION 3.0.0)
project(MyGame VERSION 0.1.0 LANGUAGES C CXX)


include(CTest)
enable_testing()

# 查找SDL2包
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)


# 添加 include 目录
include_directories(include)

# 添加源文件
aux_source_directory(src SOURCE_FILES)

add_executable(MyGame ${SOURCE_FILES} main.cpp)

# 添加 SDL2 头文件路径
target_include_directories(MyGame PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# 链接 SDL2 库
target_link_libraries(MyGame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
