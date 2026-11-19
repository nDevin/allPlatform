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
    qDebug() << "System Architecture:" << QSysInfo::currentCpuArchitecture();



    return 0;
}