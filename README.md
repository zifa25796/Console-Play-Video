# Console-Play-Video
Play a video in console, auto change RGB color to console colors(limited).

Author: Zeke Fan
Date: 2021-01-27

## Functions

main.cpp
 - void video(): fill in corsopngind dir, and it will turn video to img by frame
 - void imgInfo(Mat img): output width, hight, channels
 - Mat getImg(String path): Load in one img to Mat obj, and resize it to proper pixle size
 - int* printImg(Mat img): print the img on console, the return value is useless, could be void

terminal.h
 - void gotoxy(int x, int y): change cursor position to x, y
 - text_colour(int serial): change console text and background color
 - int fixNumber(int num): change RGB values (0~255) to console color values (0, 128, 192, 225)
 - int RGB2ConsoleColor(int R, int G, int B): turn a RGB color to corsponding console color

## Env
 - OpenCV2
