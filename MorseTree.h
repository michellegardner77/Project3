#include <fstream>
#include <cctype>
#include <string>
#include <iostream>
#include <map>
#include "MorseNode.h"
//#include <except>


using namespace std;

// ** follow's bpeterman's code on github ** 
// ** Along with Kuhail's slides **

// Declare tree
//Tree<string> morse_tree;

//method to read in from a file and assemble the tree
//void bulid_Tree();

// translates code
//void decoding(string d);

// translates code
//void encoding(string message);

template<typename T>
class morse_tree
{
public:

	//Construct a binary tree with two subtrees
	morse_tree(const Item_Type& the_data,
		const morse_tree<Item_Type>& left_child = morse_tree(),
		const morse_tree<Item_Type>& right_child = morse_tree()) :
		root(new morse_node<Item_Type>(the_data, left_child.root, right_child.root)) {}

	virtual ~morse_tree() {}

	//root "head" pointer for entire tree
	//tree_node *root;

	morse_tree<Item_Type> get_left_subtree() const;

	/** Return the right subtree. */
	morse_tree<Item_Type> get_right_subtree() const;

	bool isBinarySearch();

	void isBinarySearch(morse_node<Item_Type>* local_root, bool& result);

	// Return the data field of the root.
	const Item_Type& get_data() const;

	// Indicate that this is the empty tree. 
	bool is_null() const;

	// Indicate that this tree is a leaf. 
	bool is_leaf() const;

	/** Return a string representation of this tree. */
	virtual std::string to_string() const;

	/** Read a binary tree */
	static morese_tree<Item_Type> read_binary_tree(std::istream& in);

	void read_tree(std::vector<std::string>& text);

	morse_tree<Item_Type> read_binary_tree(std::vector<std::string>& text, int& i);

	/** Return a string representation of the root */
	std::string root_to_string() const {
		return root->to_string();
	}


	/** Return a pre-order traversal of the tree */
	std::string pre_order() const {
		return pre_order(root);
	}

	/** Return a post-order traversal of the tree */
	std::string post_order() const {
		return post_order(root);
	}

	std::string in_order() const {
		return in_order(root);
	}

	int height() const {
		if (is_null()) return 0;
		return 1 + std::max(get_left_subtree().height(), get_right_subtree().height());
	}

	int number_of_nodes() const {
		if (is_null()) return 0;
		return 1 + get_left_subtree().number_of_nodes()
			+ get_right_subtree().number_of_nodes();
	}

protected:

	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	Binary_Tree(morse_node<Item_Type>* new_root) : root(new_root) {}

	// Data Field
	morse_node<Item_Type>* root;

private:

	std::string pre_order(const morse_node<Item_Type>* local_root) const;

	std::string post_order(const morse_node<Item_Type>* local_root) const;

	std::string in_order(const morse_node<Item_Type>* local_root) const;
};













template<typename Item_Type>
void morse_tree<Item_Type>::setRoot(morse_node<Item_Type>* new_root) {

	root = new_root;
}
template<typename Item_Type>
morse_node<Item_Type>* morse_tree<Item_Type>::getRoot() {

	return root;
}

// Overloading the ostream insertion operator.
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
	const morse_tree<Item_Type>& tree)
{
	return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename Item_Type>
std::istream& operator>>(std::istream& in,
	morse_tree<Item_Type>& tree)
{
	tree = morse_tree<Item_Type>::read_binary_tree(in);
	return in;
}


// Implementation of member functions
// Accessors
/** Return the left-subtree. */
template<typename Item_Type>
morse_tree<Item_Type>
morse_tree<Item_Type>::get_left_subtree() const {
	if (root == NULL) {
		throw std::invalid_argument("get_left_subtree on empty tree");
	}
	return morse_tree<Item_Type>(root->left);
}


/** Return the right-subtree */
template<typename Item_Type>
morse_tree<Item_Type>
morse_tree<Item_Type>::get_right_subtree() const {
	if (root == NULL) {
		throw std::invalid_argument("get_right_subtree on null tree");
	}
	return morse_tree<Item_Type>(root->right);
}

/** Return the data field of the root
@throws std::invalid_argument if null tree
*/
template<typename Item_Type>
const Item_Type& morse_tree<Item_Type>::get_data() const {
	if (root == NULL) {
		throw std::invalid_argument("get_data on null tree");
	}
	return root->data;
}

template<typename Item_Type>
bool morse_tree<Item_Type>::is_null() const {
	return root == NULL;
}

/** Indicate that this tree is a leaf. */
template<typename Item_Type>
bool morse_tree<Item_Type>::is_leaf() const {
	if (root != NULL) {
		return root->left == NULL && root->right == NULL;
	}
	else
		return true;
}

/** Return a string representation of this tree */
template<typename Item_Type>
std::string morse_tree<Item_Type>::to_string() const {
	std::ostringstream os;
	if (is_null())
		os << "NULL\n";
	else {
		os << *root << '\n';
		os << get_left_subtree().to_string();
		os << get_right_subtree().to_string();
	}
	return os.str();
}

/*string_tokenizer st(line, "+ ");
while (st.has_more_tokens()) {
string term = st.next_token();*/

template<typename Item_Type>
void morse_tree<Item_Type>::read_tree(std::vector<std::string>& text) {
	int i = 0;
	morse_tree<Item_Type> newTree = read_binary_tree(text, i);
	setRoot(newTree.getRoot());
}



template<typename Item_Type>
morse_tree<Item_Type> morse_tree<Item_Type>::
read_binary_tree(std::vector<std::string>& text, int& i) {

	if (i>text.size() - 1 || text[i] == "NULL") {
		return morse_tree<Item_Type>();
	}
	else {
		std::string txt = text[i];
		//i = i + 1;
		morse_tree<Item_Type> left = read_binary_tree(text, ++i);
		//i = i + 1;
		morse_tree<Item_Type> right = read_binary_tree(text, ++i);
		return morse_tree<Item_Type>(txt, left, right);
	}
}

template<typename Item_Type>
morse_tree<Item_Type> morse_tree<Item_Type>::
read_binary_tree(std::istream& in) {
	std::string next_line;
	getline(in, next_line);
	if (next_line == "NULL") {
		return morse_tree<Item_Type>();
	}
	else {
		Item_Type the_data;
		std::istringstream ins(next_line);
		ins >> the_data;
		morse_tree<Item_Type> left = read_binary_tree(in);
		morse_tree<Item_Type> right = read_binary_tree(in);
		return morse_tree<Item_Type>(the_data, left, right);
	}
}




/** Return a pre-order traversal of the tree */
template<typename Item_Type>
std::string morse_tree<Item_Type>::pre_order(const morse_node<Item_Type>* local_root) const {
	std::string result;
	if (local_root != NULL) {
		result += local_root->to_string();
		if (local_root->left != NULL) {
			result += " ";
			result += pre_order(local_root->left);
		}
		if (local_root->right != NULL) {
			result += " ";
			result += pre_order(local_root->right);
		}
	}
	return result;
}


/** Return a post-order traversal of the tree */
template<typename Item_Type>
std::string morse_tree<Item_Type>::post_order(const morse_node<Item_Type>* local_root) const {
	std::string result;
	if (local_root != NULL) {
		if (local_root->left != NULL) {
			result += post_order(local_root->left);
			result += " ";
		}
		if (local_root->right != NULL) {
			result += post_order(local_root->right);
			result += " ";
		}
		result += local_root->to_string();
	}
	return result;
}


/** Return an in-order traversal of the tree */
template<typename Item_Type>
std::string morse_tree<Item_Type>::in_order(const morse_node<Item_Type>* local_root) const {
	std::string result;
	if (local_root != NULL) {
		result += "(";
		if (local_root->left != NULL) {
			result += in_order(local_root->left);
			result += " ";
		}
		result += local_root->to_string();
		if (local_root->right != NULL) {
			result += " ";
			result += in_order(local_root->right);
		}
		result += ")";
	}
	return result;
}








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