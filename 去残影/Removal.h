#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

//二维码大小
#define one_block_width 10
#define left_blank 2 * one_block_width
#define IMG_X 100 * one_block_width//不包括二维码边框
#define IMG_Y 100 * one_block_width
#define anchor_size 10 * one_block_width
#define anchor_blank 1 * one_block_width//框的粗细
//每个二维码最多二进制数量
#define MAX_CHAR (IMG_X / one_block_width * IMG_Y / one_block_width) - 3 * (anchor_size / one_block_width * anchor_size / one_block_width)

using namespace cv;

class Removal
{
	public:
		void RemoveImageRetention(Mat inputImage);
		Mat inhence(Mat inputImage);
};