// // //for large amount of data, tries is a better alternative to hashmaps. Hashmaps are
// // //applicable for smaller amounts of data.
// // #include <bits/stdc++.h>
// // using namespace std;

// // class Node {
// // public:
// // 	char data;
// // 	unordered_map<char, Node*> children;
// // 	bool terminal;

// // 	Node(char data) {
// // 		this->data = data;
// // 		terminal = false;
// // 	}
// // };

// // class Trie {
// // 	Node* root;

// // public:
// // 	Trie() {
// // 		root = new Node('\0');
// // 	}

// // 	void insert(string w) {
// // 		Node* temp = root;

// // 		for (int i = 0; w[i] != '\0'; i++) {
// // 			char ch = w[i];

// // 			if (temp->children.count(ch)) {
// // 				temp = temp->children[ch];
// // 			} else {
// // 				Node* n = new Node(ch);
// // 				temp->children[ch] = n;
// // 				temp = n;
// // 			}
// // 			temp->terminal = true;
// // 		}
// // 	}

// // 	bool find(string w) {
// // 		Node* temp = root;

// // 		for (int i = 0; w[i] != '\0'; i++) {
// // 			char ch = w[i];
// // 			if (temp->children.count(ch) == 0) {
// // 				return false;
// // 			} else {
// // 				temp = temp->children[ch];
// // 			}
// // 		}

// // 		return true;
// // 	}

// // 	void query(Node* root, string w, string ans){
// // 		Node* temp = root;
// // 		if (temp == NULL){
// // 			cout << ans << endl;
// // 			return;
// // 		}


// // 	}

// // 	bool print(string w){
// // 		string ans = "";
// // 		Node* temp = root;

// // 		for(int i = 0; w[i] != '\0'; i++){
// // 			char ch = w[i];
// // 			if (temp->children.count(ch) == 0){
// // 				return false;
// // 			} else {
// // 				temp = temp->children[ch];
// // 			}
// // 		}
// // 		query(temp, w, "");
// // 		return true;
// // 	}
// // };

// // int main() {
// // #ifndef ONLINE_JUDGE
// // 	freopen("input.txt", "r", stdin);
// // 	freopen("output.txt", "w", stdout);
// // #endif
// // 	Trie t;

// // 	int n, q;
// // 	cin >> n;
// // 	while(n--){
// // 		string s;
// // 		cin >> s;
// // 		t.insert(s);
// // 	}
// // 	cin >> q;
// // 	while(q--){
// // 		string w;
// // 		cin >> w;
// // 		bool ans = print(w);
// // 		if (ans == false){
// // 			cout << "No suggestions" << endl;
// // 		}
// // 		t.insert(w);
// // 	}

// // }


// #include<bits/stdc++.h>
// using namespace std;


// class node {

// public:
// 	char data;
// 	bool terminal;
// 	map<char, node*>children;

// 	node(char data) {
// 		this->data = data;
// 		this->terminal = false;

// 	}
// };

// class tries {

// public :
// 	node *root;
// 	tries() {
// 		this->root = new node('\0');
// 	}

// 	void addword(string str) {

// 		node *temp = root;
// 		for (int i = 0; i < str.length(); i++) {
// 			char ch = str[i];
// 			if (temp->children.count(ch)) {
// 				temp = temp->children[ch];
// 			} else {
// 				node *newnode = new node(ch);
// 				temp->children[ch] = newnode;
// 				temp = newnode;
// 			}
// 		}
// 		temp->terminal = true;
// 	}
// };


// void print(node *root, string s) {


// 	if (root == NULL) {
// 		return ;
// 	}

// 	if (root->data != '\0') {
// 		s += root->data;
// 	}

// 	if (root->terminal) {
// 		// s += root->data;
// 		cout << s << endl;
// 		for (auto p : root->children) {
// 			print(p.second, s);
// 		}
// 		return;
// 	}



// 	if (root->children.empty()) {
// 		// s += root->data;
// 		cout << s << endl;
// 		return;
// 	}


// 	for (auto p : root->children) {
// 		print(p.second, s);
// 	}

// 	// if (root->terminal){
// 	// 	cout << s << endl;
// 	// }
// }

// bool searchprefix(node *root, string str) {

// 	node *temp = root;
// 	for (int i = 0; i < str.length(); i++) {
// 		char ch = str[i];
// 		if (temp->children.count(ch)) {
// 			temp = temp->children[ch];
// 		} else {
// 			return false;
// 		}
// 	}
// 	for(auto p : temp->children){
// 		print(p.second, str);
// 	}
// 	if (temp->terminal){
// 		cout << str << endl;
// 	}
// 	// print(temp, str);
// 	return true;
// }

// int main() {
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	tries *t = new tries();
// 	int n;
// 	cin >> n;
// 	string arr[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 		t->addword(arr[i]);
// 	}

// 	int q;
// 	cin >> q;

// 	for (int i = 0; i < q; i++) {
// 		string temp;
// 		cin >> temp;
// 		bool p = searchprefix(t->root, temp);
// 		if (p == false) {
// 			cout << "No suggestions" << endl;
// 			t->addword(temp);
// 		}
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int>pp, kk;
class trie {
public:
	trie**children;

	trie(){
		children = new trie*[26];
		for (int i = 0; i < 26; ++i)
			children[i] = NULL;
	}
};

void insert(string s, trie *root)
{
	if (s.empty())
		return;
	int indx = s[0] - 'a';
	trie* child = root->children[indx];
	
	if (child == NULL){
		child = new trie();
		root->children[indx] = child;
	}

	insert(s.substr(1), child);
}

void print( string s, trie * root){
	bool k = false;
	for ( int i = 0; i < 26; ++i){
		if (root->children[i] != NULL){
			k = true;
			break;
		}
	}

	if (!k && kk.find(s) == kk.end()){
		cout << s << "\n";
		kk[s]++;
		return;
	}

	for ( int i = 0; i < 26; ++i){
		if (root->children[i] != NULL){
			char c = 'a' + i;
			string k(1, c);
			s = s + k;
			if (pp.find(s) != pp.end() && kk.find(s) == kk.end()){
				cout << s << "\n";
				kk[s]++;
			}
			print(s, root->children[i]);
			s = s.substr(0, s.size() - 1);
		}
	}
	return;
}

int search(string s, trie* root){
	trie*cur = root;
	for ( int i = 0; i < s.length(); ++i){
		int indx = s[i] - 'a';
		trie*child = cur->children[indx];
		if (child == NULL)
			return -1;
		else{
			cur = child;
		}
	}

	if (pp.find(s) != pp.end()){
		cout << s << "\n";
		kk[s]++;
	}

	print(s, cur);
	return 0;
}

int main(){
	int n, m;
	cin >> n;
	trie* root = new trie();
	while (n--){
		string s;
		cin >> s;
		pp[s]++;
		insert(s, root);
	}
	cin >> m;
	while (m--){
		string s;
		cin >> s;
		kk.clear();
		if (search(s, root) == -1){	
			insert(s, root);
			pp[s]++;
			cout << "No suggestions\n";
		}
	}
	return 0;
}