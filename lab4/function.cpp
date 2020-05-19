#include "function.h"

using namespace std;



void BMP::read_header(istream &infile)
{
	infile.read((char*)&header.id[0],			sizeof(int8_t));
	infile.read((char*)&header.id[1],			sizeof(int8_t));
	infile.read((char*)&header.filesize,		sizeof(int32_t));
	infile.read((char*)&header.reserver[0],		sizeof(int16_t));
	infile.read((char*)&header.reserved[1],		sizeof(int16_t));
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
}



void BMP::read_pixels(istream &infile)
{

}



