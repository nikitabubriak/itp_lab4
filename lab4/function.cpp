#include "function.h"

using namespace std;

/*void BMP::read(istream &infile)
{
	Header::read_header(infile);
	//read_pixels(infile);
}
*/

void BMP::input_data(string input)
{
	ifstream infile(input, ios::binary);//argv[1], ios::binary);
	if (!infile.is_open()) { cout << "Error. Cannot open file\n"; }

	header_in = header_in.read_header(infile);

	int n_pixels_in = header_in.get_pixels_number();
	Pixel *pixels_in = new Pixel[n_pixels_in];

	pixels_in->read_pixels(infile, pixels_in, header_in.get_width(), header_in.get_depth());

	infile.close();

	cout << "\nw:\t" << header_in.get_width() << "\nd:\t" << header_in.get_depth() << endl;
	//cout << pixels_in[0].r << endl;
}


int BMP::Header::get_pixels_number()
{
	return this->width*this->depth;
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
	//bitmap.Header header;
	Header header;
	//cout << "\nreading header\n";
	//&this->
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

	//cout << this->id1<< this->filesize << this->width << "\t" << this->depth << endl;
	//cout << header.id1 << "\t" << header.width << "\t" << header.depth << endl;
	return header;
}



void BMP::Pixel::read_pixels(istream &infile, Pixel *pixel, int w, int d)
{
	//cout << "\nreading pixels\n";
	int8_t padding;
	//int32_t w = header_in.get_width();
	//int32_t d = header_in.get_depth();
	//cout << w << "\t" << d << endl;

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
			//if ((i*d) + j) cout << (i*d) + j <<"\t"<< pixel[(i*d) + j].r << "\t" << pixel[(i*d) + j].g << "\t" << pixel[(i*d) + j].b << endl;
		}
	}
	//return pixel;
}


