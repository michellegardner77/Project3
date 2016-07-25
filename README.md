# Project3
Project 3B, Morse code. 

//Kuhail's Instructions
//Use a binary tree for decoding and a map for encoding.
//To build the morse tree(without having to order the letters based on their code), 
//read the given file,
//iterate through it line by line, 
//for each character, iterate through the code,
//if the character is a dot,go left. 
//If as you go left, you hit a NULL(because the node hasn't been built yet), 
//go ahead and a build a dummy node.
//Otherwise, keep going. 
//If the character is a dash, go right. 
//Eventually you will have reached the location for the node to insert.
//You go ahead and insert it then.
	//For encoding, just use a map<char, 
	//string> where the char is the character and the string is the code for each character.
