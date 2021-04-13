#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "Removal.h"


using namespace cv;
using namespace std;


void Removal::RemoveImageRetention(Mat inputImage)
{
    int imgrows = inputImage.rows;//行
    int imgcols = inputImage.cols;//列
    int count = 0;//残影像素数

//    cout << imgcols << "  " << imgrows;

    for (int row = 0; row < imgrows; row += one_block_width)
    {
        for (int col = 0; col < imgcols; col += one_block_width)
        {
            if ((inputImage.at<Vec3b>(row,col)[0] >= 150 && inputImage.at<Vec3b>(row, col)[0] <= 230) && (inputImage.at<Vec3b>(row, col)[1] >= 150 && inputImage.at<Vec3b>(row, col)[1] <= 230) && (inputImage.at<Vec3b>(row, col)[2] >= 150 && inputImage.at<Vec3b>(row, col)[2] <= 230))
            {
                count++;
            }
        }
    }

    //参数仍需调试
    if (count >= 800)
        cout << "此帧为残影" <<count<< endl;
    else
        cout << "此帧正常" << count << endl;


    imshow("处理的图片", inputImage);
    waitKey(50);

    return;

}

//图像增强
Mat Removal::inhence(Mat inputimg)
{
    int imgrows = inputimg.rows;//行
    int imgcols = inputimg.cols;//列
    //新建mat
    Mat dst = Mat::zeros(inputimg.size(), inputimg.type());
    //对比度
    float alpha = 1.3;

    for (int row = 0; row < imgrows; row++)
    {
        for (int col = 0; col < imgcols; col++)
        {
            //相应通道赋值 防止溢出
            dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[0]* alpha);
            dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[1] * alpha);
            dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[2] * alpha);
        }
    }
    //imwrite("..\\2.png",dst);
    return dst;
}