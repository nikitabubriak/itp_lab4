#include "function.h"

using namespace std;



int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "\nError. Expected 4 arguments:\n\n<lab4>.exe <input>.bmp <output>.bmp <size multiplier> \n" << endl;
		return 1;
	}

	double multiplier = stod(argv[3]);

	return 0;
}
