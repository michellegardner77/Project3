//Project 3B
//Michelle Garner
//Jeremy Troshynski
//James Harrison

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int mapFile();
int parse_code();
int encode_string(string message);


int main()
{
	
	mapFile(); //for testing
	parse_code(); //for testing
	
	encode_string("hello world");//decodes the entered string from the map for quick reference


}
