#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int val;
	node *left;
	node *right;
	node(int d = 0)
	{
		left = right = NULL;
		val = d;
	}
};

class Trie
{
private:
	node *root;

public:
	Trie() {
		root = new node(0);
	}

	void insert(int xorSoFar) {
		node *temp = root;
		for (int i = 31; i >= 0; i--) {
			int b = xorSoFar & (1 << i);

			if (b == 0) {
				if (temp->left == NULL) {
					temp->left = new node();
				}
				temp = temp->left;
			} else {
				if (temp->right == NULL) {
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
		temp->val = xorSoFar;
	}

	int query(int xorSoFar){
		node *temp = root;
		for (int i = 31; i >= 0; i--) {
			int b = xorSoFar & (1 << i);

			if (b == 0) {
				if (temp->right != NULL) {
					temp = temp->right;
				}
				else if (temp->left != NULL) {
					temp = temp->left;
				}
			}
			else {
				if (temp->left != NULL) {
					temp = temp->left;
				}
				else if (temp->right != NULL) {
					temp = temp->right;
				}
			}
		}
		return xorSoFar ^ (temp->val);
	}
};

int main() {
	Trie t;
	int n;
	cin >> n;

	int xorSoFar = 0;
	int result = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		xorSoFar ^= x;
		t.insert(xorSoFar);
		result = max(result, t.query(xorSoFar));
	}

	cout << result;

	return 0;
}

