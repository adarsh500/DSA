
#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

// O(NlogN)
// void buildHeap(vector<int> &v) {
// 	for (int i = 2; i < v.size(); i++) {
// 		int idx = i;
// 		int parent = i / 2;

// 		while (idx > 1 and v[idx] > v[parent]) {
// 			swap(v[idx], v[parent]);
// 			idx = parent;
// 			parent = parent / 2;
// 		}
// 	}
// }

bool minheap = false;
//this will create a max heap

bool compare(int a, int b){
	if (minheap){
		return a < b;
	} else {
		return a > b;
	}
}

void heapify(vector<int> &v, int i) {
	int left = 2 * i;
	int right = left + 1;

	int minIndex = i;
	int lastIndex = v.size() - 1;

	//this will swap the ith node with its left node, if ith node
	//is smaller than its left node
	if (left <= lastIndex && compare(v[left], v[i])) {
		minIndex = left;
	}

	//this will swap the right node with the min index node if right
	//node is smaller.
	if (right <= lastIndex && compare(v[right], v[minIndex])) {
		minIndex = right;
	}

	//so after these two operations, we will have the lowest/highest
	//value at index i

	if (minIndex != i) {
		swap(v[i], v[minIndex]);
		heapify(v, minIndex);
	}
}

//O(N)
void buildHeapOptimised(vector<int> &v) {
	for (int i = (v.size() - 1/2); i >= 1; i--) {
		//we start heapification from the first non-leaf node from bottom
		heapify(v, i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> v{-1, 10, 20, 5, 6 , 1 , 8 , 9 , 4};
	print(v);
	buildHeapOptimised(v);
	print(v);

	return 0;
}