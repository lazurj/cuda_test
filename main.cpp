#include <QCoreApplication>
#include <arrayfire.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const af::array originalImage = af::loadImage("/home/jakub/Downloads/orig.jpg", true);
    af::array grayImage = af::rgb2gray(originalImage);
    af::saveImage("/home/jakub/Downloads/gray.jpg", grayImage);
    af::array cannyImage = af::canny(grayImage, AF_CANNY_THRESHOLD_MANUAL, 0.001,0.1);

    af::saveImage("/home/jakub/Downloads/canny.jpg", cannyImage);

    printf("done!!!!");

    return a.exec();
}
