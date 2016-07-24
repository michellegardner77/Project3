#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int mapFile() {
	map <char, string> codeKeys;
	map<char, string> ::iterator itr;

	string code;
	char letter;
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
	}

	reader.close();


	for (itr = codeKeys.begin(); itr != codeKeys.end(); itr++)
	{
		cout << itr->first << itr->second;
		cout << endl;

	}

}
//method to iterate through the morse code from the tet file and determine left or right
int parse_code()
{
	map <char, string> codeKeys;
	map<char, string> ::iterator itr;

	string code;
	char letter;
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
		cout << endl;
	}

	reader.close();

}
