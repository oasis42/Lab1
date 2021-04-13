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
    int imgrows = inputImage.rows;//��
    int imgcols = inputImage.cols;//��
    int count = 0;//��Ӱ������

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

    //�����������
    if (count >= 800)
        cout << "��֡Ϊ��Ӱ" <<count<< endl;
    else
        cout << "��֡����" << count << endl;


    imshow("�����ͼƬ", inputImage);
    waitKey(50);

    return;

}

//ͼ����ǿ
Mat Removal::inhence(Mat inputimg)
{
    int imgrows = inputimg.rows;//��
    int imgcols = inputimg.cols;//��
    //�½�mat
    Mat dst = Mat::zeros(inputimg.size(), inputimg.type());
    //�Աȶ�
    float alpha = 1.3;

    for (int row = 0; row < imgrows; row++)
    {
        for (int col = 0; col < imgcols; col++)
        {
            //��Ӧͨ����ֵ ��ֹ���
            dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[0]* alpha);
            dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[1] * alpha);
            dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(inputimg.at<Vec3b>(row, col)[2] * alpha);
        }
    }
    //imwrite("..\\2.png",dst);
    return dst;
}