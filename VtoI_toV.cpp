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
	//打开视频
	cap.open("test.mp4");
	//是否成功打开视频
	if (!cap.isOpened())
		return 0;
	long totalFrame = cap.get(CAP_PROP_FRAME_COUNT);
	int fps = cap.get(CAP_PROP_FPS);
	cout << "总帧数为：" << totalFrame << "帧率为" << fps << endl;

	Mat	frame;
	for (int i = 0; i < totalFrame; i++)
	{
		// 通过流操作符把视频转化为一帧帧图片
		cap >> frame;
		if (frame.empty())
			break;

		//存储帧
		String str = to_string(i) + ".png";
		imwrite(str.c_str(), frame);

	}
	cout << "输出完毕" << endl;

}

void imgToVideo()
{
	//文件名，编码格式，帧率，分辨率
	VideoWriter video("test.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), 29.0, Size(1280, 720));
	//图片地址
	String img_path = "test";
	vector<String> img;

	glob(img_path, img, false);
	//获取图片总张数
	size_t count = img.size();
	for (size_t i = 0; i < count; i++)
	{
		stringstream str;
		str << i << ".png";
		Mat image = imread(img_path + str.str());
		//图片不为空
		if (!image.empty())
		{
			//按需调整分辨率
			resize(image, image, Size(1280, 720));
			video << image;
		}
	}
	cout << "处理完毕" << endl;
}