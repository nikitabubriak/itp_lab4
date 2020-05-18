#pragma once

#include <iostream>
#include <fstream>
#include <string>



class BMP 
{
	struct Pixel
	{
		int8_t r;
		int8_t g;
		int8_t b;
	};

	struct Header
	{
		int8_t id[2];            // ������ �� ����� 'B' � 'M'
		int32_t filesize;        // ����� ����� � ������
		int16_t reserved[2];     // 0, 0
		int32_t headersize;      // 54L ��� 24-����� ���������
		int32_t infoSize;        // 40L ��� 24-����� ���������
		int32_t width;           // ������ ���������� � �������
		int32_t depth;           // ������ ���������� � �������
		int16_t biPlanes;        // 1 (��� 24-����� ���������)
		int16_t bits;            // 24 (��� 24-����� ���������)
		int32_t biCompression;   // 0L
		int32_t biSizeImage;     // ����� ��������� � 0L ��� ��������� ��� �������� (��� ������)
		int32_t biXPelsPerMeter; // ������������� ������� ������ �� ����, ����� 0L
		int32_t biYPelsPerMeter; // �� ����, �� �����
		int32_t biClrUsed;       // ��� ������������ ���������, ����� ��������� 0L
		int32_t biClrImportant;  // �� ����
	};

public:

	void foo();

};



//#include "function.cpp"