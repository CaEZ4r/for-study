#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <chrono>

class Drob{
private:
	char znak;
	int chisl, znam, cel;
	int NOD(int, int);
public:
	Drob();

	void setVolume(int , int , int);
	Drob add(Drob);
	Drob& plus(Drob);
	Drob& operator*=(Drob);
	Drob operator+(Drob);
	Drob operator+(int);
	Drob& operator+=(Drob);
	Drob& operator-=(Drob);
	Drob& operator/=(Drob);
	void print();
	void print(char);
};
Drob::Drob(){
		chisl = cel = 0;
		znam = 1;
};
void Drob::print(){
	printf("%u(%u/%u)\n", cel, chisl, znam);
};

void Drob::setVolume(int _fl, int _ch, int _zn){
	cel = _fl;
	chisl = _ch;
	znam = _zn;
};

int Drob::NOD(int a, int b){
	unsigned int x;
	if (a > b) 
		x = b;
	else
		x = a;
	int res = 1;
	for (int j = 2; j < a; j ++) {
			while (a % j == 0 && b % j == 0) {
				a /= j;
				b /= j;
				res *= j;
			}
		}
	return res;
};
Drob& Drob::operator+=(Drob d){
	Drob tmp;
	
		chisl += cel * znam;
		d.chisl += d.cel * d.chisl;
		tmp.chisl = d.chisl * znam + chisl * d.znam;
		tmp.znam = znam * d.znam;
		tmp.cel = tmp.chisl / tmp.znam;
		tmp.chisl %= tmp.znam;
		int k = NOD(tmp.chisl, tmp.znam);
		tmp.chisl /= k;
		tmp.znam /= k;
	if (tmp.chisl == 0){
		tmp.znam = 1;
	}	

	znam = tmp.znam;
	chisl = tmp.chisl;
	cel = tmp.cel;
	return *this; 
};
Drob& Drob::operator-=(Drob d){
	Drob tmp;
		chisl =(chisl + cel * znam) * d.znam;
		d.chisl =(d.chisl + d.cel * d.chisl) * znam;
		tmp.chisl = chisl - d.chisl;
		tmp.znam = znam * d.znam;
		tmp.cel = tmp.chisl / tmp.znam;
		tmp.chisl %= tmp.znam;
		int k = NOD(tmp.chisl, tmp.znam);
		tmp.chisl /= k;
		tmp.znam /= k;
	if (tmp.chisl == 0){
		tmp.znam = 1;
	}
	cel = tmp.cel;
	znam = tmp.znam;
	chisl = tmp.chisl;
	return *this; 
}
Drob& Drob::operator/=(Drob d){
	Drob tmp;
	chisl += cel * znam;
	d.chisl += d.cel * d.znam;
	
	int l = d.chisl;
	d.chisl = d.znam;
	d.znam = l;
	
	tmp.chisl = chisl * d.chisl;
	tmp.znam = znam * d.znam;
	int k = NOD(tmp.chisl, tmp.znam);
	tmp.chisl /= k;
	tmp.znam /= k;
	tmp.cel = tmp.chisl / tmp.znam;
	tmp.chisl = tmp.chisl % tmp.znam;
	if (tmp.chisl == 0){
		tmp.znam = 1;
	}
	cel = tmp.cel;
	chisl = tmp.chisl;
	znam = tmp.znam;
	return *this;
};
Drob& Drob::operator*=(Drob d){
	Drob tmp;
	
	chisl += cel * znam;
	d.chisl += d.cel * d.znam;
	tmp.chisl = chisl * d.chisl;
	tmp.znam = znam * d.znam;
	tmp.cel = tmp.chisl / tmp.znam;
	tmp.chisl = tmp.chisl % tmp.znam;
	if (tmp.chisl == 0){
		tmp.znam = 1;
	}
	int k = NOD(tmp.chisl, tmp.znam);
	tmp.chisl /= k;
	tmp.znam /= k;
	znam = tmp.znam;
	chisl = tmp.chisl;
	cel = tmp.cel;
	return *this;
};
using namespace std;

int main(int argc, char ** argv)
{
    string znaki;
    int ce, chis, zna;
    Drob res;
    int i = 0;
    if (argc < 2){

    }
    std::ifstream in(argv[1]); // îêðûâàåì ôàéë äëÿ ÷òåíèÿ
    if (in.is_open())
    {
        
        
            getline(in, znaki);
        
    }
    in.close();
    const char* FName = argv[2];
    ifstream fout(FName,ios::binary);
    fout.read((char*)&ce, sizeof(int));
    fout.read((char*)&chis, sizeof(int));
    fout.read((char*)&zna, sizeof(int));
    res.setVolume(ce, chis, zna);
    while (znaki[i] != '\0') {
            fout.read((char*)&ce, sizeof(int));
            fout.read((char*)&chis, sizeof(int));
            fout.read((char*)&zna, sizeof(int));
            Drob k;
            k.setVolume(ce, chis, zna);
            if (znaki[i] == '+')
                res+=k;
            
            if (znaki[i] == '*')
                res*=k;
            if (znaki[i] == '-')
            	res-=k;
            if (znaki[i] == '/')
            	res/=k;
            i ++;
    }
    fout.close();
    res.print();
    return 0;
}
