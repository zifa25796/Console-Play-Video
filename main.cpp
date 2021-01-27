#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "terminal.h"
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <mutex>
using namespace std;
using namespace cv;

String debug_img_path = "C:\\CS\\C++\\img_process\\test.jpg";
double out_put_size = 100;


void imgInfo(Mat img) {
	cout << "Width: " << img.cols << "\tHight: " << img.rows << "\tChannels: " << img.channels() << endl;
	return;
}

Mat getImg(String path) {
	Mat img = imread(path);
	if (img.data == nullptr) {
		cout << "Img not exist" << endl;
		return img;
	}
	else {
		//imgInfo(img);
	}

	Mat resized_img;
	int longerSide;
	if (img.cols < img.rows) {
		longerSide = img.rows;
	}
	else {
		longerSide = img.cols;
	}

	float resize_percent = out_put_size / longerSide;
	resize(img, resized_img, Size(), resize_percent, resize_percent / 2);

	return resized_img;
}

int* printImg(Mat img) {
	const int rows = img.rows;
	const int cols = img.cols;

	for (size_t y = 0; y < rows; ++y) {
		unsigned char* row_ptr = img.ptr<unsigned char>(y);

		for (size_t x = 0; x < cols; ++x) {
			unsigned char* data_ptr = &row_ptr[x * img.channels()];
			int rgb = RGB2ConsoleColor(int(data_ptr[2]), int(data_ptr[1]), int(data_ptr[0]));

			gotoxy(x, y);
			text_colour(rgb);
			putchar(char(" "));
		}
		text_colour(0);
		printf("\n");
	}

	return nullptr;
}

double m_() {
	gotoxy(0, 0);
	clock_t start, finish;
	double duration;
	start = clock();

	Mat img = getImg(debug_img_path);
	if (img.data == nullptr) return 0;
	//imgInfo(img);

	hidecursor();
	/*char buff[2048];
	setvbuf(stdin, buff, _IOFBF, sizeof(buff));*/
	printImg(img);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	return duration;
}

void video2image(string video, string path)
{
	VideoCapture capture(video);
	if (!capture.isOpened())
	{
		cerr << "Failed to open a video" << endl;
		return;
	}

	Mat frame;
	int num = 1;
	string filename;
	char   temp_file[5];

	for (;;)
	{
		capture >> frame;
		if (frame.empty())
			break;
		sprintf(temp_file, "%d", num);//每张图片前缀由六个字符构成，不够六个字符的前面用0补完整
		filename = temp_file;
		cout << temp_file << endl;
		filename = path + filename + ".jpg";
		num++;
		imwrite(filename, frame);
	}
	capture.release();
}

void video() {
	string videoFromfile = "C:\\CS\\C++\\img_process\\res\\test.mkv";  //读取视频
	string Imagespath = "C:\\CS\\C++\\img_process\\res\\imgs\\";    //保存图片集路径
	//string videoTosave   = "E:\\opencv_demo\\vs2010\\video\\testVideo.avi"; //保存视频路径
	video2image(videoFromfile, Imagespath);
}


int main() {
	/*clock_t start, finish;
	double duration;
	start = clock();*/

	
	int num = 1;
	char temp_file[5];
	string filename;
	string path = "C:\\CS\\C++\\img_process\\res\\imgs\\";

	while (num <= 249) {

		sprintf(temp_file, "%d", num);
		filename = path + temp_file + ".jpg";

		Mat img = getImg(filename);
		if (img.data == nullptr) return 0;

		hidecursor();
		gotoxy(0, 0);
		printImg(img);

		num++;
	}

	
	
	/*finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	text_colour(10);
	cout << endl << duration << endl;*/
	text_colour(10);
	gotoxy(0, 0);
	cout << num;
	return 0;
}