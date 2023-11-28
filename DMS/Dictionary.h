#pragma once
// The code cretea a dictonary using trie tree implementation
#include<iostream>
#include<string>
#include<fstream>
#include <limits>
#include<stdlib.h>
using namespace std;

struct node // node structure 
{
	char Letter;
	bool IswordComplete = false;
	node* children[97];
	string Meaning;
};

class trie_tree
{
public:
	node* root = createNode();
public:
	node* createNode() // function to create a new node
	{
		node* newnode = new node();
		newnode->IswordComplete = false;
		for (int x = 0; x < 97; x++)
		{
			newnode->children[x] = NULL;
		}
		return newnode;
	}

	void large(string& w) // function to enlarge the letters of a word
	{
		for (int i = 0; i < w.length(); i++)
		{
			if (w[i] > 96 && w[i] < 123)
			{
				w[i] -= 32; // to go on to upper case letters
			}
		}
		string temp;
		for (int i = 0; i < w.length(); i++) {
			if (w[i] != ' ') {
				temp += w[i];
			}
		}
		w = temp;
	}

	void LoadDictionary() // function = to load the dictionary into the trie tree
	{
		int pos = 0;
		ifstream read;
		read.open("Dictionary.txt", ios::in);
		string word, meaning;

		if (!read.is_open())
		{
			return;
		}
		else
		{
			while (!read.eof())
			{
				read >> word >> meaning;

				large(word);

				node* temp = root; // used for traversing the string

				for (int x = 0; x < word.length(); x++)
				{
					pos = word[x]; // determining the position of each letter in the array
					if (temp->children[pos] == NULL) // checking if position is occupied already or not 
						temp->children[pos] = createNode(); // if not create a node on that position

					temp = temp->children[pos]; // pointing at the new node
				}
				temp->IswordComplete = true;
				temp->Meaning = meaning;
			}
		}
		read.close();
	}

	void AddWord(string word, string meaning) // function to add new words
	{
		large(word);
		//large(meaning);
		node* temp = root; // used for traversing the string
		int length = word.length(); // storing length of the string

		for (int x = 0; x < length; x++)
		{
			int pos = word[x]; // determining the position of each letter in the array
			if (temp->children[pos] == NULL) // checking if position is occupied already or not 
				temp->children[pos] = createNode(); // if not create a node on that position

			temp = temp->children[pos]; // pointing at the new node
		}
		temp->IswordComplete = true;
		temp->Meaning = meaning;
		ofstream write;
		write.open("Dictionary.txt", ios::app);
		write << endl << word << "\t" << meaning;
		write.close();
	}

	bool find(string word, node*& current)  // function to perfrom the actual searching
	{
		int index;
		//this for loop check word index by index etc a,l,i.
		for (int i = 0; i < word.length(); i++)
		{
			index = word[i];
			//As we know at word last end_word = false
			//so this loop run when word not find means end_word = true.
			if (!current->children[index])
			{
				return false;
			}
			//moves to the next index.
			current = current->children[index];
		}
		//if word exist function return value.
		if (current->IswordComplete == true)
		{
			return true;
		}
		//if word not exist.
		return false;
	}

	string search(string word) // function to search word and display it 
	{
		node* current = root;
		//large the string
		//if ali =ALI.
		large(word);
		if (find(word, current))
		{
			return current->Meaning;
		}
		else
		{
			return "Not Found";
		}
	}

	bool isEmpty() // function to check for empty tree
	{
		for (int i = 0; i < 97; i++)
			if (root->children[i])
				return false;
		return true;
	}

	void delete_word(string word) // Search function for deletion
	{
		node* current = root;
		//word = arge(word);
		if (!find(word, current))
		{
			cout << "\t\t\tWord is Not Available" << endl;
			return;
		}
		current->IswordComplete = false;
		return;
	}

	void DeleteWord(string w) // function to delete words from the tree
	{
		large(w);
		delete_word(w);
		string word, meaning;
		ifstream read;
		ofstream write;
		write.open("new.txt", ios::app);
		read.open("Dictionary.txt");
		while (!read.eof())
		{
			read >> word >> meaning;
			if (word != w) {
				write << word << "\t\t" << meaning << endl;
			}
		}
		read.close();
		write.close();
		remove("Dictionary.txt");
		write.open("Dictionary.txt");
		read.open("new.txt");

		while (!read.eof())
		{
			read >> word >> meaning;
			write << word << "\t\t" << meaning << endl;
		}
		read.close();
		write.close();
		cout << "\t\t\tWord is deleted Sucessfully from file" << endl;
		remove("new.txt");
	}

	void deleteAll(node* ptr) // function to delete the entire tree
	{
		if (ptr == NULL)
			return;
		else
		{
			for (int i = 0; i < 97; i++)
			{
				if (ptr->children[i])
					deleteAll(ptr->children[i]);
			}
			delete ptr;
		}
		root = NULL;
	}

	// function to print suggesstions
	int x;
	void suggestions(node* r, string orignalword, string suggestedword, int index, int& count)
	{

		if (count >= 5 || r == 0 || index > orignalword.length())
		{
			return;
		}
		if (index == orignalword.length())
		{
			suggestions(0, orignalword, suggestedword, index + 1, count);
		}
		else
		{
			suggestions(r->children[int(orignalword[index] - 32 - index)], orignalword, (suggestedword + orignalword[index]), index + 1, count);
		}

		for (int i = 0; i < 97 && count <= 5; i++)
		{
			if (r->children[i] != 0 && r->children[i]->IswordComplete)
			{
				if ((suggestedword + char(i + 32 + index)) != orignalword)
				{
					cout << suggestedword + char(i + 32 + index) << endl;
					count++;
				}
			}
			if ((suggestedword + char(i + 32 + index)) != orignalword && r->children[i] != 0)
			{
				suggestions(r->children[i], orignalword + char(i + 32 + index), (suggestedword + char(i + 32 + index)), index + 1, count);
			}
		}
	}

	void Update(string word) // funtion to update the meaning of a given word
	{
		string meaning;
		large(word);
		int pos;
		node* temp = root; // used for traversing the string
		int length = word.length(); // storing length of the string

		for (int x = 0; x < length; x++)
		{
			pos = word[x]; // determining the position of each letter in the array
			if (temp->children[pos] == NULL)
				cout << "Word does not exit" << endl;
			temp = temp->children[pos];
		}
		if (temp->IswordComplete == true)
		{
			cout << "Enter the new meaning of the word to update" << endl;
			cin >> meaning;
			temp->Meaning = meaning;
		}

		cout << "Word Meaning Updated" << endl;
	}

	~trie_tree() // destructor
	{
		deleteAll(root);
	}
};

static trie_tree Obj;
