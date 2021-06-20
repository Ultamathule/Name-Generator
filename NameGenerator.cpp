
#include "pch.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>


using namespace std;

void NameGenerator();
 
int main()
{
	// generation loop.
	bool isDone = false;

	while (isDone == false)
	{

		NameGenerator();

		
	}
	system("PAUSE")
	return 0;
}



void NameGenerator()
{
	//this will generate "a-z" can also generate "A-Z", "0-9"
	mt19937 generator{ random_device{}() };			
	uniform_int_distribution<int> distribution('a','z');

	// first letter generator
	mt19937 FLgenerator{ random_device{}() };
	uniform_int_distribution<int> FirstLetter('A', 'Z');
	
	// thiswill generate length of name
	static default_random_engine randomGen(time(NULL));			
	uniform_int_distribution<int>  nameLength(2, 5);

	//random vowl out of the array
	static default_random_engine randomGenV(time(NULL));
	uniform_int_distribution<int>  randVowlChoice(0, 5);
	
	// this will generate the vowl in the second place always
	int randVowl = randVowlChoice(randomGenV);
					//vowl array!!
	char VowlArray[6] = { 'a', 'e', 'i', 'o' , 'u' , 'y' };

	
	
	int nameLengthResult;
	nameLengthResult = nameLength(randomGen);

	auto generate_leng = 1;// modify for length for first letter 
	string rand_FL(generate_leng, '\0');
	for (auto& diss : rand_FL)
		diss = FirstLetter(FLgenerator);

	for (int i = 0; i < 6; i++);

	// generation after the first letter!!
	string rand_str(nameLengthResult, '\0');
	for (auto& dis : rand_str)
		dis = distribution(generator);

	

	cout << "Random Name generated : " << rand_FL << VowlArray[randVowl] << rand_str << VowlArray[randVowl] << endl << endl ;
}
// press R to regenerate a new name
void PressRtoReGen()
{
	//char r = 'R';
	//if()
}
