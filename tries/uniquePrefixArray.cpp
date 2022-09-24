// // //for large amount of data, tries is a better alternative to hashmaps. Hashmaps are
// // //applicable for smaller amounts of data.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	// bool terminal;
	int freq = 0;

	Node(char data) {
		this->data = data;
		// terminal = false;
		freq = 0;
	}
};

class Trie {
	Node* root;
	int count;

public:
	Trie() {
		root = new Node('\0');
		root->freq = 0;
		count = 0;
	}

	void insert(char *w) {
		Node* temp = root;

		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];

			//we check if the charecter is present in the map or not
			if (temp->children.count(ch)) {
				temp = temp->children[ch];
			}

			//else we create a new node with the charecter value and add it to the map
			//and then we point temp to the newly created node;
			else {
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
			temp->freq = temp->freq + 1;
		}
		// temp->terminal = true;
	}

	bool find(char *w) {
		Node* temp = root;

		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch) == 0) {
				return false;
			} else {
				temp = temp->children[ch];
			}
		}

		return true;
	}

	string printUniquePrefix(char *w) {
		Node* temp = root;
		string s = "";

		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch) == 1 and temp->children[ch]->freq > 1) {
				s += ch;
				temp = temp->children[ch];
			} else if (temp->children.count(ch) == 1 and temp->children[ch]->freq == 1) {
				s += ch;
				return s;
			}
		}
		return to_string(-1);
	}

};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Trie t;

	char words[][10] = {"zebra", "dog", "dove", "duck", "zebras"};
	// {"cobra", "dog", "dove", "duck"}

	for (int i = 0; i < 5; i++) {
		t.insert(words[i]);
	}

	for (int i = 0; i < 5; i++) {
		cout << t.printUniquePrefix(words[i]) << endl;
	}

}   
