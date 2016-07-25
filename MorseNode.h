#ifndef MorseNODE_H_
#define MorseNODE_H_ 
#include <iostream>
#include <sstream>

using namespace std;

// A node for Binary Tree
template<typename Item_Type>
struct morse_node
{
	// Data Fields
	char alpha; //letter
	string morse; //morse code
	morse_node<Item_Type>* left;
	morse_node<Item_Type>* right;

	// Constructor
	morse_node(const Item_Type& the_data,
		morse_node<Item_Type>* left_val = NULL,
		morse_node<Item_Type>* right_val = NULL) :
		data(the_data), left(left_val), right(right_val) {}

	// Destructor (to avoid warning message)
	virtual ~morse_node() {}

	// to_string
	virtual string to_string() const { ostringstream os; os << data; return os.str(); }

};

#endif