//this is an inplace sorting algo. T complexity O(NlogN)
#include <bits/stdc++.h>
using namespace std;

bool minheap = false;

bool compare(int a, int b){
	if (minheap){
		return a < b;
	} else {
		return a > b;
	}
}

void print(vector<int> v){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void heapify(vector<int> &v, int i, int size) {
	int left = 2 * i;
	int right = left + 1;

	int minIndex = i;
	int lastIndex = size;

	if (left < lastIndex && compare(v[left], v[minIndex])) {
		minIndex = left;
	}

	if (right < lastIndex && compare(v[right], v[minIndex])) {
		minIndex = right;
	}

	if (minIndex != i) {
		swap(v[i], v[minIndex]);
		heapify(v, minIndex, size);
	}
}

void buildHeapOptimised(vector<int> &v) {
	for (int i = (v.size() - 1/2); i >= 1; i--) {
		heapify(v, i, v.size());
	}
}

void heapsort(vector<int> &arr){
	buildHeapOptimised(arr);
	int n = arr.size();

	while(n > 1){
		swap(arr[1], arr[n - 1]);
		n--;
		heapify(arr, 1, n);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	vector<int> v;
	v.push_back(-1);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	heapsort(v);
	print(v);
}