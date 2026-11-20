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
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_FILES)

############################ Build Platform = arm64 ##################################### 
if("${BUILD_PLATFORM}" STREQUAL "arm64")
    add_definitions(-DARM_64) 
    set(CMAKE_C_COMPILER /opt/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
    set(CMAKE_CXX_COMPILER /opt/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

    set(OPENCV_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/opencv-4.5.3-arm64/include/opencv4/)
    set(OPENCV_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/opencv-4.5.3-arm64/lib)
    include_directories(${OPENCV_INCLUDE})

    # 添加Qt配置
    set(QT_INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/include/QtCore/
    )
    set(QT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Arm64_bag/qt5.12.0-arm64/lib)
    include_directories(${QT_INCLUDE})

    set(LIBS 
        ${OPENCV_LIB}/libopencv_core.so.4.5
        ${OPENCV_LIB}/libopencv_imgcodecs.so.4.5
        ${OPENCV_LIB}/libopencv_imgproc.so.4.5 
        ${OPENCV_LIB}/libtbb.so
        ${QT_LIB}/libQt5Core.so.5
    )

############################ Build Platform = amd64 ##################################### 
elseif("${BUILD_PLATFORM}" STREQUAL "amd64")
    add_definitions(-DX86_64) 
    set(CMAKE_C_COMPILER /usr/bin/gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/g++)

    set(OPENCV_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/opencv-4.5.3-amd64/include/opencv4/)
    set(OPENCV_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/opencv-4.5.3-amd64/lib)
    include_directories(${OPENCV_INCLUDE})

    # 添加Qt配置
    set(QT_INCLUDE 
        ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/include/QtCore/
    )
    set(QT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Amd64_bag/qt5.12.0-amd64/lib)
    include_directories(${QT_INCLUDE})

    set(LIBS 
        ${OPENCV_LIB}/libopencv_core.so.4.5
        ${OPENCV_LIB}/libopencv_imgcodecs.so.4.5
        ${OPENCV_LIB}/libopencv_imgproc.so.4.5 
        ${QT_LIB}/libQt5Core.so.5
    )

############################ Build Platform = arm32 ##################################### 
elseif("${BUILD_PLATFORM}" STREQUAL "arm32")
    add_definitions(-DARM_32)   
    set(CMAKE_C_COMPILER /opt/arm-rockchip830-linux-uclibcgnueabihf-master/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc)
    set(CMAKE_CXX_COMPILER /opt/arm-rockchip830-linux-uclibcgnueabihf-master/bin/arm-rockchip830-linux-uclibcgnueabihf-g++)

    set(OPENCV_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/opencv-4.5.3-arm32/include/opencv4/)
    set(OPENCV_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/opencv-4.5.3-arm32/lib)
    include_directories(${OPENCV_INCLUDE})

    # 添加Qt配置
    set(QT_INCLUDE 
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/include/QtCore/
    )
    set(QT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/Arm32_bag/qt5.12.0-arm32/lib)
    include_directories(${QT_INCLUDE})

    set(LIBS 
        ${OPENCV_LIB}/libopencv_core.so.4.5
        ${OPENCV_LIB}/libopencv_imgcodecs.so.4.5
        ${OPENCV_LIB}/libopencv_imgproc.so.4.5 
        ${QT_LIB}/libQt5Core.so.5
    )

endif()

message("OpenCV include = ${OPENCV_INCLUDE}")
message("OpenCV lib = ${OPENCV_LIB}")
message("Qt include = ${QT_INCLUDE}")
message("Qt lib = ${QT_LIB}")

add_executable(${PROJECT_NAME} ${SRC_FILES})

# add_executable 要在 target_link_libraries 之前
target_link_libraries(${PROJECT_NAME} ${LIBS})
