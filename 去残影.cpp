#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include "decode.h"


using namespace cv;
using namespace std;


void DeCode::RemoveImageRetention(Mat inputImage)
{

    int imgrows = inputImage.rows;//行
    int imgcols = inputImage.cols;//列
    int count = 0;//残影像素数

//    cout << imgcols << "  " << imgrows;

//对储存数据的像素点进行处理,黑色代表1,白色代表0

//    std::cout << "按行解码后得到的数据:" << endl;

    for (int i = 0; i < imgrows; i += one_block_width)
    {

        for (int j = 0; j < imgcols; j += one_block_width)
        {
            if (i < anchor_size + left_blank && j < anchor_size + left_blank);
            //左上角定位点
            else
                if (i >= imgrows - anchor_size - left_blank && j < anchor_size + left_blank);
            //左下角定位点
                else
                    if (i < anchor_size + left_blank && j >= imgcols - anchor_size - left_blank);
            //右上角定位点
                    else
                        if (i < left_blank);

                        else
                            if (i >= imgrows - left_blank);

                            else
                                if (j < left_blank);

                                else
                                    if (j >= imgcols - left_blank);

                                    else {

                                        if ((inputImage.at<Vec3b>(i, j)[0] >= 120 && inputImage.at<Vec3b>(i, j)[0] <= 180 )&& (inputImage.at<Vec3b>(i, j)[1] >= 120 && inputImage.at<Vec3b>(i, j)[1] <= 180) && (inputImage.at<Vec3b>(i, j)[2] >= 120 && inputImage.at<Vec3b>(i, j)[2] <= 180))
                                        {

                                            count++;

                                        }

                                    }

        }

        //std::cout << endl;

    }

    //参数仍需调试
    if (count >= 500)
        cout << "此帧为残影" << endl;
    else
        cout << "此帧正常" << endl;


    imshow("处理的图片",inputImage);
    waitKey(0);

    return;

}