#include "func.h"
#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>


void function() {
    printf("Function is running.\n");
    std::cout << "Hello Wrold!" << std::endl;
}



void opencvDemo()
{
    // 创建一张 100x100 的三通道蓝色图像
    cv::Mat img(100, 100, CV_8UC3, cv::Scalar(255, 0, 0));
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    std::cout << "OpenCV 转为灰度图: " << static_cast<int>(gray.at<uchar>(50, 50)) << ", 通道数: " << gray.channels() << std::endl;
    const std::string path = "demo_output.png";
    bool ok = cv::imwrite(path, img);
    std::cout << "imwrite 结果: " << (ok ? "成功" : "失败") << ", 文件: " << path << std::endl;
    cv::Mat loaded = cv::imread(path, cv::IMREAD_COLOR);
    std::cout << "OpenCV 图像尺寸: " << loaded.cols << "x" << loaded.rows << ", 通道数: " << loaded.channels() << std::endl;
}