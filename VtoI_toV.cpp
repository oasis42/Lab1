#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
	videoToImg();
	imgToVideo();
}

void videoToImg()
{
	VideoCapture cap;
	//����Ƶ
	cap.open("test.mp4");
	//�Ƿ�ɹ�����Ƶ
	if (!cap.isOpened())
		return 0;
	long totalFrame = cap.get(CAP_PROP_FRAME_COUNT);
	int fps = cap.get(CAP_PROP_FPS);
	cout << "��֡��Ϊ��" << totalFrame << "֡��Ϊ" << fps << endl;

	Mat	frame;
	for (int i = 0; i < totalFrame; i++)
	{
		// ͨ��������������Ƶת��Ϊһ֡֡ͼƬ
		cap >> frame;
		if (frame.empty())
			break;

		//�洢֡
		String str = to_string(i) + ".png";
		imwrite(str.c_str(), frame);

	}
	cout << "������" << endl;

}

void imgToVideo()
{
	//�ļ����������ʽ��֡�ʣ��ֱ���
	VideoWriter video("test.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), 29.0, Size(1280, 720));
	//ͼƬ��ַ
	String img_path = "test";
	vector<String> img;

	glob(img_path, img, false);
	//��ȡͼƬ������
	size_t count = img.size();
	for (size_t i = 0; i < count; i++)
	{
		stringstream str;
		str << i << ".png";
		Mat image = imread(img_path + str.str());
		//ͼƬ��Ϊ��
		if (!image.empty())
		{
			//��������ֱ���
			resize(image, image, Size(1280, 720));
			video << image;
		}
	}
	cout << "�������" << endl;
}