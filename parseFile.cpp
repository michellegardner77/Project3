#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
map <char, string> codeKeys;
map<char, string> ::iterator itr;
string code;
char letter;

int mapFile() {
	


	ifstream reader("morse.txt"); // input file stream reader to read the characters char letter
	if (!reader) {
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else {
		while (reader >> letter >> code)
		{
			codeKeys[letter] = code;
		}
		cout << endl;
	}

	reader.close();

	//prints the map in the same format as text file
	for (itr = codeKeys.begin(); itr != codeKeys.end(); itr++)
	{
		cout << itr->first << itr->second;
		cout << endl;
	}

}
//method to iterate through the morse code from the text file and determine left or right
int parse_code()
{



	ifstream reader("morse.txt"); // input file stream reader to read the characters char letter
	if (!reader) {
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else {
		while (reader >> letter >> code)
		{
			codeKeys[letter] = code;

			for (unsigned i = 0; i < code.length(); i++)
			{
				if (code[i] == '.') {
					cout << letter <<" : left" << endl;
				}else
						cout << letter << " : right" << endl;
					
			}

		}
		cout << endl << endl;;
	}

	reader.close();

}

//encodes string into morse code using the the map created from text file.
void encode_string(string message)
{
	
	cout << "The encoded message <" << message << "> is: " << endl << endl;
	for (unsigned i = 0; i < message.length(); i++)
	{
		{
			for (itr = codeKeys.begin(); itr != codeKeys.end(); itr++)
			if (message[i] == itr->first)
			{
				cout << itr->second << "  ";
				
			}

		}
	}
		cout << endl << endl;

}
