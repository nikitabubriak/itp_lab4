#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 8847360; // 4K UHD

class BMP 
{

	class Header
	{
		int8_t id1;              // ������ �� ����� 'B' � 'M'
		int8_t id2;              // ������ �� ����� 'B' � 'M'
		int32_t filesize;        // ����� ����� � ������
		int16_t reserved1;       // 0, 0
		int16_t reserved2;       // 0, 0
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

	public:

		Header read_header(istream&);
		void write_header(ostream&);
		int get_pixels_number();
		int get_headersize();
		int get_width();
		int get_depth();
		
	}header_in;

	class Pixel
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;

	public:

		void read_pixels(istream&, Pixel*, int, int);
		uint8_t get_r();
		void set_r(uint8_t);
		
		friend class BMP;
	};

public:

	Pixel *pixels_in = new Pixel[SIZE];

	void input_data(string);
	void increase_scale(string, int);

}bitmap;



#include "function.cpp"