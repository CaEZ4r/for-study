#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

class Drob{
private:
	char znak;
	unsigned int ch, zn, fl;
public:
	Drob();
//Инициализирующий конструктор
	Drob(char, unsigned int, unsigned int, unsigned int);
// Печать дроби в формате (ch/zn)
	void setVolume(char, unsigned int, unsigned int, unsigned int);
	Drob add(Drob);
	Drob& plus(Drob);
	Drob operator+(Drob);
	Drob operator+(int);
	Drob& operator+=(Drob);
	void print();
	void print(char);
};

void Drob::print(){
	printf("%c%u(%u/%u)\n", znak, fl, ch, zn);
};

using namespace std;

int main(int argc, char ** argv)
{
    ifstream f1;
    char znaki[100];
    int cel, chisl, znam;
    int i = 0;
    if (argc < 2){

    }
    std::ifstream in(argv[1]); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << znaki << std::endl;
        }
    }
    in.close();
    Drob res;
    const char* FName = argv[2];
    ofstream in(FName,ios::binary);
    for (i = 0; i < strlen(znaki); i ++){
        if (i == 0){
            in.read((char*)&cel, sizeof(int));
            in.read((char*)&chisl, sizeof(int));
            in.read((char*)&znam, sizeof(int));
            res.cel = cel;
            res.znam = znam;
            res.chisl = chisl;
        }
        else{
            in.read((char*)&cel, sizeof(int));
            in.read((char*)&chisl, sizeof(int));
            in.read((char*)&znam, sizeof(int));
            Drob k;
            k.cel = cel;
            k.chisl = chisl;
            k.znam = znam;
            if (znaki[i] == '+')
                res+=k;
            if (znaki[i] == '-')
                res-=k;
            if (znaki[i] == '*')
                res*=k;
            if (znaki[i] == '/')
                res/=k;
        }
    }
    print(res);
    return 0;
}
