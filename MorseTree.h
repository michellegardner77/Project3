#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
#include <map>
//#include "MorseNode.h"
//#include <except>


using namespace std;

// ** follows bpeterman's code on github ** 
// ** Along with Kuhail's slides **
template<typename T>
class morse_tree
{
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
	morse_node *root;
public:
	morse_tree():root(NULL){}

	morse_tree(int i, string a, string m) {
		root = new morse_node(i, a, m, nullptr, nullptr);
	}

	~morse_tree() {}

	//Construct an empty morse tree
	//morse_tree() : root(NULL) {}
	//Construct a binary tree
	//morse_tree(char alpha, morse_tree left = morse_tree(), morse_tree right = morse_tree()) : root(new morse_node(alpha, left.root, right.root)) {}



	void insert(morse_node* r, int index, string alpha, string morse) {
		if (r->index == index)
			return;

		if (r->index > index) {
			if (r->left == nullptr)
				r->left = new morse_node(index, alpha, morse, nullptr, nullptr);
			else
				insert(r->left, index, alpha, morse);
		}
		else {
			if (r->right == nullptr)
				r->right = new morse_node(index, alpha, morse, NULL, NULL);
			else
				insert(r->right, index, alpha, morse);
		}
	}

	// wrapper method for recursive tree insert method
	void insert(int index, string alpha, string morse) {
		if (root == nullptr)
			root = new morse_node(index, alpha, morse, NULL, NULL);
		else
			insert(root, index, alpha, morse);
	}


	char convert_to_alpha(string m)
	{
		if (r->index == morse)
			return r->alpha;

		if (r->index > index) {
			if (r->left == nullptr)
				r->left = new morse_node(index, alpha, morse, morse_overlay, nullptr, nullptr);
			else
				insert(r->left, index, alpha, morse, morse_overlay);
		}
		else {
			if (r->right == nullptr)
				r->right = new morse_node(index, alpha, morse, morse_overlay, nullptr, nullptr);
			else
				insert(r->right, index, alpha, morse, morse_overlay);
		}
	}



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












	morse_tree()
	{
		root = NULL;
	}

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


	void insert(morse_node*& local_root, char letter, string code) //item is the node we're inserting
	{
		if (local_root == NULL)
		{
			cout << "Inserted letter: " << letter << " at position: " << code << endl;
			//create a new morse tree with the local_root as the root
			local_root = new morse_node;
			local_root->letter = letter;
			local_root->code = code;
			local_root->left = local_root->right = NULL;
		}
	}

	//root(new BTNode<Item_Type>(the_data, left_child.root, right_child.root))
	// morse_node first = morse_node('!', NULL, NULL));

};
	//morse_tree(map<char,string> code_keys); //creates morse_tree with values

	//virtual ~morse_tree() {}

	//morse_node get_left_subtree();

	/** Return the right subtree. */
	//morse_node get_right_subtree();

	//bool isBinarySearch();

	//void isBinarySearch(morse_node* local_root, bool& result);

	// Return the data field of the root.
	//const <Item_Type>& get_data() const;
/*
	// Indicate that this is the empty tree. 
	bool is_null() const;

	/** Read a binary tree 
	static morse_tree read_binary_tree(std::istream& in);

	//void insert(char letter, string code);

	//void insert(morse_node*& local_root, morse_node& item, string path, string current_location);

	bool search(morse_node item);

	//given morse code, traverses binary tree, returns alpha value
	char convert_to_alpha (string m);
	
	*/
	//void read_tree(std::vector<std::string>& text);

	//morse_tree read_binary_tree(std::vector<std::string>& text, int& i);

	/** Return a string representation of the root 
	std::string root_to_string() const {
		return root->to_string();
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


	//protected::
	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	//morse_tree(morse_node* new_root) : root(new_root) {}

	// Data Field







// Implementation of member functions
// Accessors
/** Return the left-subtree. 
morse_node morse_tree::get_left_subtree() {
	if (root == NULL) {
		throw std::invalid_argument("get_left_subtree on empty tree");
	}
	return (*root->left);
}


/** Return the right-subtree 
morse_node morse_tree::get_right_subtree(){
	if (root == NULL) {
		throw std::invalid_argument("get_right_subtree on null tree");
	}
	return (*root->right);
}
*/
/*
bool morse_tree::search(morse_node*& local_root, morse_node& item, string current_location)
{
	if (item == NULL)
	{
		return false;
	}
	if ((*local_root).morse == current_position) //if morse code is equal to the value of the current node
	{
		current_position = "0";
		return item;
	}
	while (!morse.empty())
	{
		if (morse[0] == '.') //if next value is .
		{
			morse.erase(0, 1);
			current_position += '.';
			return search(morse, current_position, item->left);
		}
		else
		{
			morse.erase(0, 1);
			current_position += '_';
			return search(morse, current_position, item->left); //next value is _
		}
	}
	
	//else return NULL;
}


void morse_tree::insert_node(morse_node*& local_root, morse_node& item)
{
	char current = item.alpha;
	insert(local_root, item, current);

}

void morse_tree::insert(char letter, string code)
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
					r->left = new morse_node(letter);
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
					r->right = new morse_node(letter);
					// todo: code to bind a new node to r->right
					break;
				}
			}
		}
		insert(r, letter, code);
	}
	else insert(root, letter, code);
	}
}

void morse_tree::insert(morse_node*& local_root, char letter, string code) //item is the node we're inserting
{ 
	if (local_root == NULL)
	{
		//create a new morse tree with the local_root as the root
		local_root = new morse_node(letter);
		local_root->left = local_root->right = NULL;
	}

	if () //if morse code is equal to the value of the current node
	{
		(*local_root).set_alpha(item.get_alpha());
		cout << "Inserted letter: " << (*local_root).get_alpha() << " at position: " << current_location << endl;
		current_location = "";
		return true;
	}

	while (!morse_location.empty()) //while not the correct location
	{
		//search(morse_location, "", local_root);
		//morse_location.erase(0, 1);
		/*
		read the given file, iterate through it line by line, for each character, iterate through the code, 
		if the character is a dot, go left.
		If as you go left, you hit a NULL(because the node hasn't been built yet), go ahead and a build a dummy node. 
		Otherwise, keep going. 
		If the character is a dash, go right. 
		Eventually you will have reached the location for the node to insert. You go ahead and insert it then.
		
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
	}
	//string test;
	//(*local_root).set_morse(item.get_morse());
	//(*local_root).set_alpha(item.get_alpha());
	//cout << "Inserted letter: " << (*local_root).get_alpha() << " at position: " << current_location << endl;
	//cin >> test;
	//delete[item];
	//return true;

}
	//return false;







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