#include "function.h"

using namespace std;



int main()//int argc, char* argv[])
{

	/*if (argc != 4)
	{
		cout << "\nError. Expected 4 arguments:\n\n<lab4>.exe <input>.bmp <output>.bmp <size multiplier> \n" << endl;
		return 1;
	}
	*/

	/*	
D:\KPI\OP2\lab4\Debug
lab4.exe input.bmp output.bmp 3
	*/

	//^^^^^^^^^^^^^^^^^^^^^^^^^
	string argv1 = "input.bmp";
	string argv2 = "output.bmp";

	string argv3 = "3";
	double multiplier = stod(argv3);//argv[3]);

	BMP bitmap;
	
	bitmap.input_data(argv1);
	bitmap.increase_scale(argv2, multiplier);



	//cout <<"\nr: " <<bitmap.pixels_in[1].get_r()<<endl;

	///////////////////////////////////////////////

	//cout << bitmap.header_in.get_depth();

	//bitmap.read_header(infile);
	//bitmap.read_pixels(infile);
	//BMP::Header header;
	//header bitmap.read_header(infile);
	//int n_pixels_in = header_in.width*header_in.depth;
	//Pixel p = *pixels_in;

	
	//cout << header_in.id1 << "\t" << header_in.width << "\t" << header_in.depth << endl;
	//cout << (i*d) + j << "\t" << pixel[(i*d) + j].r << "\t" << pixel[(i*d) + j].g << "\t" << pixel[(i*d) + j].b << endl;
	//pixels_in = pixels_in.read_pixels(infile);
	//const int n_pixels_in = header_in.width*header_in.depth;
	//vector<Pixel> pixels_in;// [n_pixels_in];// = Pixel.read_pixels(infile);
	//pixels_in.read_pixels(infile, header_in);

	return 0;
}
