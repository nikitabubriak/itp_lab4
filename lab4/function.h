#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



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
		int get_pixels_number();
		int get_width();
		int get_depth();

		//friend class Pixel;
	};

	class Pixel
	{

		uint8_t r;
		uint8_t g;
		uint8_t b;
	public:
		void read_pixels(istream&, Pixel*, int, int);

		
	};
	
	//Header read_header(istream&);
	//Header header = read_header();
	//void read_pixels(istream&);


public:



	//solve ifstream infile function
	//read_pixels read_header in .cpp adjust to BMP class
	//read_pixels adjust to BMP encapsulation (~header)
	//call VVV (method from here)somethin from main() to start the program VVVVV
	//method here to take filename STRING from main and in the method create ifstream and pass it by calling read_header/pixels in this method


	Header header_in;


	//istream stream();

	void input_data(string);

	
	
	//ofstream outfile("output.bmp", ios::binary);//argv[2], ios::binary);
	
	

	

	

	//Header header;
	//Pixel *pixel = new Pixel[header.width*header.depth];
	
	//void read(istream&);

};



#include "function.cpp"