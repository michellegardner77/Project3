#ifndef MorseNODE_H_
#define MorseNODE_H_ 
#include <iostream>
#include <sstream>

using namespace std;

// A node for Binary Tree
struct morse_node
{
	// Data Fields
	char alpha = '!'; //letter
	//string morse; //morse code
	morse_node* left;
	morse_node* right;

	// Constructor
	//morse_node();

	morse_node(char a = '!', morse_node* l = NULL, morse_node* r = NULL) : alpha(a), left(l), right(r) {}
	//morse_node(string morse_value, const char& a = '!', morse_node* left_val = NULL, morse_node* right_val = NULL) : morse(morse_value), alpha(a), left(left_val), right(right_val) {}


	// Destructor (to avoid warning message)
	virtual ~morse_node() {}

	// to_string
	//virtual string to_string() const { ostringstream os; os << data; return os.str(); }

	//string get_morse()
	//{return morse;}

	char get_alpha()
	{return alpha;}

	//void set_morse(string m)
	//{morse = m; }

	void set_alpha(char a)
	{
		alpha = a;
	}
};

#endif