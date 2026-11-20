cmake_minimum_required(VERSION 3.10)
project(allPlatform)

message("Build Platform = ${BUILD_PLATFORM}")

# 添加位置无关代码编译选项
add_compile_options(-fPIC)
# 使用CMake的标准方式设置C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置优化级别
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_BUILD_TYPE Release)
 # 保留汇编器的调试信息
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")


include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)


############################ Build Platform = arm64 ##################################### 
if("${BUILD_PLATFORM}" STREQUAL "arm64")
    add_definitions(-DARM_64) 
    set(CMAKE_C_COMPILER /opt/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
    set(CMAKE_CXX_COMPILER /opt/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

    set(OPENCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/opencv-4.5.3-arm64/include/opencv4/)
    set(OPENCV_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/opencv-4.5.3-arm64/lib)
    include_directories(${OPENCV_INCLUDE_DIRS})
    link_directories(${OPENCV_LIB_PATH})

    # 添加Qt配置
    set(QT_INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/include/QtCore/
    )
    set(QT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/lib)
    include_directories(${QT_INCLUDE_DIRS})
    link_directories(${QT_LIB_PATH})

############################ Build Platform = amd64 ##################################### 
elseif("${BUILD_PLATFORM}" STREQUAL "amd64")
    add_definitions(-DX86_64) 
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)

    set(OPENCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/opencv-4.5.3-amd64/include/opencv4/)
    set(OPENCV_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/opencv-4.5.3-amd64/lib)
    include_directories(${OPENCV_INCLUDE_DIRS})
    link_directories(${OPENCV_LIB_PATH})

    # 添加Qt配置
    set(QT_INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/include/QtCore/
    )
    set(QT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/lib)
    include_directories(${QT_INCLUDE_DIRS})
    link_directories(${QT_LIB_PATH})

############################ Build Platform = arm32 ##################################### 
elseif("${BUILD_PLATFORM}" STREQUAL "arm32")
    add_definitions(-DARM_32)   
    set(CMAKE_C_COMPILER /opt/arm-rockchip830-linux-uclibcgnueabihf-master/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc)
    set(CMAKE_CXX_COMPILER /opt/arm-rockchip830-linux-uclibcgnueabihf-master/bin/arm-rockchip830-linux-uclibcgnueabihf-g++)

    set(OPENCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/opencv-4.5.3-arm32/include/opencv4/)
    set(OPENCV_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/opencv-4.5.3-arm32/lib)
    include_directories(${OPENCV_INCLUDE_DIRS})
    link_directories(${OPENCV_LIB_PATH})

    # 添加Qt配置
    set(QT_INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/include/QtCore/
    )
    set(QT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/lib)
    include_directories(${QT_INCLUDE_DIRS})
    link_directories(${QT_LIB_PATH})
endif()

# OpenCV 依赖包内若提供 libtbb.so 则显式链接
# 交叉编译时 ld 无法自动查找间接依赖（libopencv_core 依赖 libtbb.so），必须显式给出
set(TBB_LIB_PATH "")
if(EXISTS ${OPENCV_LIB_PATH}/libtbb.so)
    set(TBB_LIB_PATH ${OPENCV_LIB_PATH}/libtbb.so)
endif()


message("OpenCV lib = ${OPENCV_LIB_PATH}")
message("TBB lib = ${TBB_LIB_PATH}")
message("OpenCV include = ${OPENCV_INCLUDE_DIRS}")
message("Qt lib = ${QT_LIB_PATH}")
message("Qt include = ${QT_INCLUDE_DIRS}")


# 添加可执行文件
add_executable(allPlatform ${SRC_LIST})

target_link_libraries(allPlatform
${OPENCV_LIB_PATH}/libopencv_core.so.4.5
${OPENCV_LIB_PATH}/libopencv_imgcodecs.so.4.5
${OPENCV_LIB_PATH}/libopencv_imgproc.so.4.5 
${TBB_LIB_PATH}
${QT_LIB_PATH}/libQt5Core.so.5
)