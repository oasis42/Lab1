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

    int imgrows = inputImage.rows;//��
    int imgcols = inputImage.cols;//��
    int count = 0;//��Ӱ������

//    cout << imgcols << "  " << imgrows;

//�Դ������ݵ����ص���д���,��ɫ����1,��ɫ����0

//    std::cout << "���н����õ�������:" << endl;

    for (int i = 0; i < imgrows; i += one_block_width)
    {

        for (int j = 0; j < imgcols; j += one_block_width)
        {
            if (i < anchor_size + left_blank && j < anchor_size + left_blank);
            //���ϽǶ�λ��
            else
                if (i >= imgrows - anchor_size - left_blank && j < anchor_size + left_blank);
            //���½Ƕ�λ��
                else
                    if (i < anchor_size + left_blank && j >= imgcols - anchor_size - left_blank);
            //���ϽǶ�λ��
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

    //�����������
    if (count >= 500)
        cout << "��֡Ϊ��Ӱ" << endl;
    else
        cout << "��֡����" << endl;


    imshow("�����ͼƬ",inputImage);
    waitKey(0);

    return;

}