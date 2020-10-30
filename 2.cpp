#include<iostream>
#include<bitset>
// dar in soal mikhaim az yek byte ee ke darim bit 0 ro ba bit 4
// va bit 1 ro ba bit 3 avaz konim va too khode byte aval bezarim

//in taghir ro bedoone moteghayer temp ham mishod anjam dad vali vase fahme behtar
//az temp estefade kardam ;-)



//in ye joor enctyption ast pas addad khoruji ro bezari toosh adad aval ro mide
int main()
{
	char n = 43;	//khoruji 58 ast va barax
	std::cout << (int)n <<" \n"<<(std::bitset<8>)n<< std::endl;
	char temp = 0;
	char mask = 0b00011011;
	//(n & 0b00011011);  //kharej kardan bit haye 0,1,3,4
	temp=((n & (1U << 0)) << 4 )| (((n&(1U<<4))>>4)); //taghir bit 0 va 4
	temp|=((n & (1U << 1)) << 2 )| (((n&(1U<<3))>>2)); //taghir bit 1 va 3
	n = n & ~(0b00011011); //pak kardan (sefr kardan)bit haye 0,1,3,4 ghabli dar byte asli
	n = n | temp; //gozashtane meghdare temp dar byte eslah shode
	//n = (n & ~mask) | ((b << p) & mask);
	std::cout << (int)n << " \n" << (std::bitset<8>)n << std::endl;
}