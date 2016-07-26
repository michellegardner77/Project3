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

//morse_node* root = new morse_node("");
map <char, string> codeKeys;
map <char, string> ::iterator itr;
morse_tree<string> tree;
string morse;
char letter;
string test;



int map_file();
int parse_code();
void encode_string(string s);
void decode_string(string morse);

int main()
{
	string test;
	map_file();
	parse_code();
	encode_string("hello");
	decode_string("._ .__. .__. ._.. . ");
	//cin >> test;
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
void insert(int index, string alpha, string encode_morse);
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
			tree.insert(letter, morse);
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

void construct_tree()
{
	//create morse_nodes for each value given in the text file
	//insert each node into the morse_tree
	//morse_node item;
	//string path = "";
	//tree.insert(root, item, path, item.get_morse());
}

string decode_string(string morse)
{
	string result;
	//expects a binary tree to already exist
	//traverse through the binary tree based on given morse code values. Delimiter is space
	//if the location matches the morse string, append the letter to the message.
	//remove the morse value for the letter that was appended.
	//print out the resulting message
	cout << "The decoded message <" << morse << "> is: " << endl << endl;
	while (!morse.empty())
	{
		char current_letter = tree.convert_to_alpha(morse[0, morse.find(" ")]);
		//pull string of first morse code value, until space
		
		//morse_node* current = tree->*root;

		cout << (current_letter);
		morse.erase(0, morse.find(" "));


	}
	cout << endl << endl;
	
}

