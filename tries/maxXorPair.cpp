#include <bits/stdc++.h>
using namespace std;

class node{
public:
	node* left;
	node* right;
};

class trie{
	node* root;

public: 
	trie(){
		root = new node();
	}

	//eg 5 = 32 bit integer

	void insert(int n){
		node* temp = root;

		//we are  assuming that the integer is 32 bit.
		//it could also be 64 bit;
		for(int i = 31; i >= 0; i--){
			int bit = (n >> i) & 1;

			if (bit == 0){
				if(temp->left == NULL){
					temp->left = new node();
				}
				temp = temp->left;
			} else {
				if (temp->right == NULL){
					temp->right = new node();
				}
				temp = temp->right;
			}
		}
	}

	int max_xor_helper(int value){
		node* temp = root;
		int currentAns = 0;
		for(int j = 31; j >= 0; j--){
			int bit = (value>>j) &1;

			if (bit == 0){
				//find a complementary value
				if (temp->right != NULL){
					temp = temp->right;
					currentAns += (1 << j);
				} else {
					temp = temp->left;
				}
			} else {
				if (temp->left != NULL){
					temp = temp->left;
					currentAns += (1<<j);
				} else {
					temp = temp->right;
				}
			}
		}
		cout << "ans: " << currentAns << ":" << value << endl;
		return currentAns;
	}

	int maxXor(int *input, int n){
		int maxXor = 0;

		for(int i = 0; i < n; i++){
			int val = input[i];
			insert(val);
			int currentXor = max_xor_helper(val);
			cout << currentXor << " ";
			maxXor = max(currentXor, maxXor);
		}
		return maxXor;
	}

	// 
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	trie t;
	int input[] = {8,1,2,15,10,5};
	cout << t.maxXor(input, 6)<< endl;

}