#include "function.h"

using namespace std;



int main(int argc, char* argv[])
{
	/*

D:\KPI\OP2\lab4\Debug

lab4.exe input.bmp output.bmp 10

	*/

	if (argc != 4)
	{
		cout << "\nError. Expected 4 arguments:\n\n" 
			 << "<lab4>.exe <input>.bmp <output>.bmp <size multiplier> \n" << endl;
		return 1;
	}

	string input = argv[1], 
		   output = argv[2];
	int multiplier = stoi(argv[3]);

	bitmap.input_data(input);
	bitmap.increase_scale(output, multiplier);

	return 0;
}