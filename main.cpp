//Project 3B
//Michelle Garner
//Jeremy Troshynski
//James Harrison

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "MorseTree.h"
#include "MorseNode.h"

using namespace std;

map <char, string> codeKeys;
map <char, string> ::iterator itr;
morse_tree tree;
string morse;
char letter;
string test;



int map_file();
int parse_code();
void encode_string(string s);
void decode_string(string morse);
void decode_character(morse_node*& local_root, string path);
//void decode_string(string morse);

int main()
{
	string test;
	map_file();
	parse_code();
	encode_string("hello");
	decode_string("._ .__. .__. ._.. . ");
	//cin >> test;
}

void decode_string(string morse)
{
	cout << "The decoded message <" << morse << "> is: " << endl << endl;
	//for each separation of " "'s 
	while (!morse.empty())
	{
		decode_character(tree.root, morse.substr(0, morse.find(' ')));
		morse.erase(0, morse.find(" ") +1);
	}
	cin >> test;
}


int map_file() {
//reads in text file and places letter/morse code combinations in the map codeKeys
	ifstream reader("morse.txt"); // input file stream reader to read the characters char letter
	if (!reader) {
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else {
		while (reader >> letter >> morse)
		{
			codeKeys[letter] = morse;
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
	//tree.root = new morse_node();
	ifstream reader("morse.txt"); // input file stream reader to read the characters char letter
	if (!reader) {
		cout << "Error opening file: " << endl;
		return -1; //signals error
	}
	else {
		while (reader >> letter >> morse)
		{
			codeKeys[letter] = morse;
			morse_node item = morse_node(letter);
			tree.insert(tree.root, item, morse);
			//cin >> test;
			for (unsigned i = 0; i < morse.length(); i++)
			{
				//if (code[i] == '.') {
					//cout << letter << " : left" << endl;
				//}
				//else
					//cout << letter << " : right" << endl;
			}

		}
		cout << endl << endl;;
	}

	reader.close();

}

//encodes string into morse code using the the map created from text file.
//prints resulting morse code
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



void decode_character(morse_node*& local_root, string path)
{
	if (path.empty()) //if we're in the correct position
	{
		cout << (*local_root).alpha;
		return;
	}
	if (path[0] == '.') //if next value is .
	{
		return decode_character(local_root->left, path.substr(1));
	}
	else //if next value is _
	{
		return decode_character(local_root->right, path.substr(1));
	}
}

