#include <stdio.h>
#include <iostream>
#include "func.h"
#include <QDebug> 
#include <opencv2/core/version.hpp>


int main() 
{
    function();
    std::cout << "OpenCV Version: " << CV_VERSION << std::endl;
    qDebug() << "Qt Version:" << qVersion(); 
    opencvDemo();


    #ifdef ARM_64
        std::cout << "硬件平台：ARM_64" << std::endl;
    #elif ARM_32
        std::cout << "硬件平台：ARM_32" << std::endl;
    #elif X86_64   
        std::cout << "硬件平台：X86_64" << std::endl;
    #endif 


    return 0;
}