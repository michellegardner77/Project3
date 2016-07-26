#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
#include <map>
#include "MorseNode.h"
//#include <except>

using namespace std;

class morse_tree
{
	/*
private:

struct morse_node
{
int index;
string alpha;
string code;
string morse;
morse_node *left;
morse_node *right;
morse_node(int i, string a, string m, morse_node *l, morse_node *r) : index(i), alpha(a), morse(m), left(l), right(r) {}
};
*/
public:
	morse_node *root;

	morse_tree() :root(NULL){}
	//morse_tree(char alpha, morse_tree left = morse_tree(), morse_tree right = morse_tree()) : root(new morse_node(alpha, left.root, right.root)) {}
	//morse_tree(int i, string a, string m) {}

	~morse_tree() {}

	bool insert(morse_node*& local_root, morse_node& item, string path)
	{
		if (local_root == NULL)
		{
			local_root = new morse_node();
			local_root->left = local_root->right = NULL;
		}
		if (path.empty()) //if we're in the correct position
		{
			local_root->alpha = item.alpha;
			//cout << "Inserted letter: " << item.alpha << endl; //" at position: "; // << endl;
			return true;
		}
		if (path[0] == '.') //if next value is .
		{
			return insert(local_root->left, item, path.substr(1));
		}
		else //if next value is _
		{
			return insert(local_root->right, item, path.substr(1));
		}
	}
};
	/*
	string decode(string message) {
		string result = "";
		tree_node* current = root;
		char letter[4] = " .-";

		for (int i = 0; i <= message.size(); i++){
			if (message.size() == i){
				result += current->morse_overlay;
			}

			else if (message[i] == letter[0]){
				result += current->morse_overlay;
				current = root;
				if (message[i + 1] == letter[0]){
					result += " ";
					i++;
				}
			}
			else if (message[i] == message[1]){
				if (current->right != nullptr && current->left != nullptr)
					current = current->right;
			}
			else if (message[i] == letter[2]){
				if (current->right != nullptr && current->left != nullptr)
					current = current->left;
			}
		}
		return result;
	}
	*/





	/*
	void insert(char letter, string code)
	{
		morse_node *r = root;
		if (r != NULL)
		{
			for (int i = 0; i < code.length(); i++)
			{
				if (code[i] == '.')
				{
					if (r->left)
						r = r->left;
					else
					{
						insert(r->left, letter, code);

						// todo: code to bind a new node to r->left
						break;
					}
				}
				else // its always either '.' or '-' so there is no need to double check the symbol here
				{
					if (r->right)
						r = r->right;
					else
					{
						insert(r->right, letter, code);
						// todo: code to bind a new node to r->right
						break;
					}
				}
			}
			insert(r, letter, code);
		}
		else insert(root, letter, code);
	}
	*/




	/*
	int height() const {
		if (is_null()) return 0;
		return 1 + std::max(get_left_subtree().height(), get_right_subtree().height());
	}

	int number_of_nodes() const {
		if (is_null()) return 0;
		return 1 + get_left_subtree().number_of_nodes()
			+ get_right_subtree().number_of_nodes();
	}
	*/






	






/*
void morse_tree::insert(morse_node*& local_root, morse_node& item) //item is the node we're inserting
{ 
	if (local_root == NULL)
	{
		//create a new morse tree with the local_root as the root
		local_root = new morse_node(letter);
		local_root->left = local_root->right = NULL;
	}

	if (current_location == ) //if morse code is equal to the value of the current node
	{
		(*local_root).set_alpha(item.get_alpha());
		cout << "Inserted letter: " << (*local_root).get_alpha() << " at position: " << current_location << endl;
		current_location = "";
		return true;
	}

		if (morse_location.front() == '.')
		{
			morse_location.erase(0, 1); //prepare next location to find
			current_location.append("."); //keep track of current location for next iteration
			//cout << item.get_alpha() << " going left" << endl;
			//cout << "morse location: " << morse_location << endl;
			morse_tree::insert(local_root->left, item, morse_location, current_location); //go left
		}
		else //(morse_location.front() == '_')
		{
			morse_location.erase(0, 1);
			current_location.append("_");
			//cout << item.get_alpha() << " going right" << endl;
			//cout << "morse location: " << morse_location << endl;
			morse_tree::insert(local_root->right, item, morse_location, current_location); //go right
		}

	//string test;
	//(*local_root).set_morse(item.get_morse());
	//(*local_root).set_alpha(item.get_alpha());
	//cout << "Inserted letter: " << (*local_root).get_alpha() << " at position: " << current_location << endl;
	//cin >> test;
	//delete[item];
	//return true;

}

*/






/*

		// constructor that creates a root node
		tree(int i, string a, string e, string m) {
			root = new tree_node(i, a, e, m, NULL, NULL);
		}

		// destructor, delete all nodes incase spys find out the code
		~tree() {};

		bool is_null() const;

	private:
		void insert(tree_node* r, int index, alpha, morse_encode, morse_overlay)
			if (r->index == index)
				return;
		if (r->index > index)
		{
			if (r->left == NULL)
			{
				r->left = new tree_node(index, alpha, morse_encode, morse_overlay, NULL, NULL);
			}
			else
			{
				insert(r->left, index, morse_encode, morse_overlay);
			}
		else
		{
			if (r->right == NULL)
			{
				r->right = new tree_node(index, alpha, morse_encode, morse_overlay, NULL, NULL);
			}
			else
			{
				insert(r->right, index, alpha, morse_encode, morse_overlay);
			}
		}


		//wrapper for recursive tree insert method
		void insert(int index, string alpha, string morse_encode, string morse_overlay) {
			if (root == NULL)
			{
				root = new tree_node(index, alpha, morse_encode, morse_overlay, NULL, NULL);
			}
			else
			{
				insert(root, index, alpha, morse_encode, morse_overlay);
			}
		}
		*/