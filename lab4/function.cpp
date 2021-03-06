#include "function.h"

using namespace std;



void BMP::input_data(string input)
{
	ifstream infile(input, ios::binary);
	if (!infile.is_open()) { cout << "Error. Cannot open input file\n"; }

	header_in = header_in.read_header(infile);

	int n_pixels_in = header_in.get_pixels_number();

	pixels_in->read_pixels(infile, pixels_in, header_in.get_width(), header_in.get_depth());

	infile.close();
}

uint8_t BMP::Pixel::get_r()
{
	return this->r;
}

void BMP::Pixel::set_r(uint8_t r)
{
	this->r = r;
}

int BMP::Header::get_pixels_number()
{
	return this->width*this->depth;
}

int BMP::Header::get_headersize()
{
	return this->headersize;
}

int BMP::Header::get_width()
{
	return this->width;
}

int BMP::Header::get_depth()
{
	return this->depth;
}



BMP::Header BMP::Header::read_header(istream &infile)
{
	Header header;

	infile.read((char*)&header.id1,				sizeof(int8_t));
	infile.read((char*)&header.id2,				sizeof(int8_t));
	infile.read((char*)&header.filesize,		sizeof(int32_t));
	infile.read((char*)&header.reserved1,		sizeof(int16_t));
	infile.read((char*)&header.reserved2,		sizeof(int16_t));
	infile.read((char*)&header.headersize,		sizeof(int32_t));
	infile.read((char*)&header.infoSize,		sizeof(int32_t));
	infile.read((char*)&header.width,			sizeof(int32_t));
	infile.read((char*)&header.depth,			sizeof(int32_t));
	infile.read((char*)&header.biPlanes,		sizeof(int16_t));
	infile.read((char*)&header.bits,			sizeof(int16_t));
	infile.read((char*)&header.biCompression,	sizeof(int32_t));
	infile.read((char*)&header.biSizeImage,		sizeof(int32_t));
	infile.read((char*)&header.biXPelsPerMeter, sizeof(int32_t));
	infile.read((char*)&header.biYPelsPerMeter, sizeof(int32_t));
	infile.read((char*)&header.biClrUsed,		sizeof(int32_t));
	infile.read((char*)&header.biClrImportant,	sizeof(int32_t));

	return header;
}



void BMP::Header::write_header(ostream& outfile)
{
	outfile.write((char*)&this->id1,			sizeof(int8_t));
	outfile.write((char*)&this->id2,			sizeof(int8_t));
	outfile.write((char*)&this->filesize,		sizeof(int32_t));
	outfile.write((char*)&this->reserved1,		sizeof(int16_t));
	outfile.write((char*)&this->reserved2,		sizeof(int16_t));
	outfile.write((char*)&this->headersize,		sizeof(int32_t));
	outfile.write((char*)&this->infoSize,		sizeof(int32_t));
	outfile.write((char*)&this->width,			sizeof(int32_t));
	outfile.write((char*)&this->depth,			sizeof(int32_t));
	outfile.write((char*)&this->biPlanes,		sizeof(int16_t));
	outfile.write((char*)&this->bits,			sizeof(int16_t));
	outfile.write((char*)&this->biCompression,	sizeof(int32_t));
	outfile.write((char*)&this->biSizeImage,	sizeof(int32_t));
	outfile.write((char*)&this->biXPelsPerMeter,sizeof(int32_t));
	outfile.write((char*)&this->biYPelsPerMeter,sizeof(int32_t));
	outfile.write((char*)&this->biClrUsed,		sizeof(int32_t));
	outfile.write((char*)&this->biClrImportant, sizeof(int32_t));
}



void BMP::Pixel::read_pixels(istream &infile, Pixel *pixel, int w, int d)
{
	int8_t padding;

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			infile.read((char*)&pixel[(i*d) + j].r, sizeof(int8_t));
			infile.read((char*)&pixel[(i*d) + j].g, sizeof(int8_t));
			infile.read((char*)&pixel[(i*d) + j].b, sizeof(int8_t));

			if (j == w-1 && (w * 3) % 4 != 0)
			{
				for (int i = 0; i < 4 - (w * 3) % 4; i++)
				{
					infile.read((char*)&padding, sizeof(int8_t));
				}
			}
		}
	}
}



void BMP::increase_scale(string output, int n)
{

	ofstream outfile(output, ios::binary);
	if (!outfile.is_open()) { cout << "Error. Cannot open output file\n"; }

	cout << "Enlarging image " << n << " times...";

	int w = header_in.get_width();
	int d = header_in.get_depth();

	int _n = n;
	int8_t padding = 0x00;

	int32_t w_out = w * _n;
	int32_t d_out = d * _n;
	int32_t filesize_out = header_in.get_headersize() + w_out + d_out;

	header_in.write_header(outfile);

	for (int i = 0; i < d; i++) // 65 different 3-rows in depth
	{
		for (int k = 0; k < _n; k++) // 3 equal rows in depth
		{
			for (int j = 0; j < w; j++) // 65 different 3-pixels in width
			{
				for (int l = 0; l < _n; l++) // 3 equal pixels in width
				{
					outfile.write((char*)&pixels_in[(i*d) + j].r, sizeof(uint8_t));
					outfile.write((char*)&pixels_in[(i*d) + j].g, sizeof(uint8_t));
					outfile.write((char*)&pixels_in[(i*d) + j].b, sizeof(uint8_t));
				}

				if (j == w - 1 && (w * _n * 3) % 4 != 0)
				{
					for (int i = 0; i < 4 - (w * _n * 3) % 4; i++)
					{
						outfile.write((char*)&padding, sizeof(uint8_t));
					}
				}
			}
		}
	}

	outfile.seekp(2, ios::beg);
	outfile.write((char*)&filesize_out, sizeof(int32_t));

	outfile.seekp(18, ios::beg);
	outfile.write((char*)&w_out, sizeof(int32_t));

	outfile.seekp(22, ios::beg);
	outfile.write((char*)&d_out, sizeof(int32_t));

	outfile.close();

	cout << "Done." << endl;
	cout << "Written result to " << output << endl;
}