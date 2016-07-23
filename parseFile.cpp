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