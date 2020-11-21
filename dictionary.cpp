// C++ implementation of counting the 
// numberber of words in a trie with a 
// given prefix 
#include "bits/stdc++.h" 
using namespace std; 

// Trie Node 
struct TrieNode { 

	// Using map to store the pointers 
	// of child nodes for dynamic 
	// implementation, for making the 
	// program space efiicient 
	map<char, TrieNode*> child; 

	// If isNotWord is true, then 
	// node represents end of word 
	bool isNotWord; 

	// number represents numberber of times 
	// a character has appeared during 
	// insertion of the words in the 
	// trie 
	map<char, int> number; 
}; 

// Declare root node 
struct TrieNode* root; 

// Function to create New Trie Node 
struct TrieNode* getNewTrieNode() 
{ 
	struct TrieNode* Tnode = new TrieNode; 
	Tnode->isNotWord = false; 
	return Tnode; 
} 

// Function to insert a string in trie 
void insertionOfWords(string word) 
{ 
	// To hold the value of root 
	struct TrieNode* curr = root; 

	// To hold letters of the word 
	char s; 

	// Traverse through strings in list 
	for (int i = 0; i < word.length(); i++) { 
		s = word[i]; 

		// If s is not present in the 
		// character field of curr node 
		if (curr->child.find(s) 
			== curr->child.end()) { 

			// Get new node 
			struct TrieNode* p = getNewTrieNode(); 

			// Insert s in character 
			// field of curr node 
			// with reference to node p 
			(curr->child)[s] = p; 

			// Insert s in number field 
			// of curr node with 
			// value 1 
			(curr->number)[s] = 1; 
		} 
		else { 

			// Increment the count 
			// corressponding to the 
			// character s 
			curr->number[s] = (curr->number)[s] + 1; 
		} 

		// Go to next node 
		curr = (curr->child)[s]; 
	} 
	curr->isNotWord = true; 
} 

// Function to count the numberber of 
// words in trie with given prefix 
int counterOFWords(vector<string>& words, 
			string prefix) 
{ 
	root = getNewTrieNode(); 

	// Size of list of string 
	int n = words.size(); 

	// Construct trie containing 
	// all the words 
	for (int i = 0; i < n; i++) { 
		insertionOfWords(words[i]); 
	} 

	struct TrieNode* curr = root; 
	char s; 

	// Initialize the Word Count(wc) = 0 
	int wc = 0; 

	for (int i = 0; prefix[i]; i++) { 
		s = prefix[i]; 

		// If the complete prefix is 
		// not present in the trie 
		if (curr->child.find(s) 
			== curr->child.end()) { 

			// Make the Word Count 0 and use break keyword to out from loop 
			wc = 0; 
			break; 
		} 

		// Update the Word Count
		wc = (curr->number)[s]; 

		// Go to next node 
		curr = (curr->child)[s]; 
	} 

	return wc; 
} 

//  The driver Code is here 
int main() 
{ 
	// This is the list of the input words
	vector<string> words; 
	words = {"Keyboard", "apple", "keyboard", "mango", "keyboard"}; 

	//  find this given prefix
	string prefix = "Keyboard"; 

	// Print the number of words with prefix 
	cout << counterOFWords(words, prefix); 
	return 0; 
}