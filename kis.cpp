#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
int main(){
	int x1 = 0, x2 = 3, x3 = 8, x4 = 0, x5 = 1, x6 = 8, x7 = 0, x8 = 2, x9 = 1, y1 = 0, y2 = 1, y3 = 3, y4 = 0, y5 = 2, y6 = 7;
	ofstream fout("txt.bin", ios_base::binary);
	fout.write((char*)&x1, sizeof(int));
	fout.write((char*)&x2, sizeof(int));
	fout.write((char*)&x3, sizeof(int));
	fout.write((char*)&x4, sizeof(int));
	fout.write((char*)&x5, sizeof(int));
	fout.write((char*)&x6, sizeof(int));
	fout.write((char*)&x7, sizeof(int));
	fout.write((char*)&x8, sizeof(int));
	fout.write((char*)&x9, sizeof(int));
	fout.write((char*)&y1, sizeof(int));
	fout.write((char*)&y2, sizeof(int));
	fout.write((char*)&y3, sizeof(int));
	fout.write((char*)&y4, sizeof(int));
	fout.write((char*)&y5, sizeof(int));
	fout.write((char*)&y6, sizeof(int));
	fout.close();
	return 0;
}
