//insertion in heap take O(logN) 
//get min is O(1)
#include <iostream>
#include <vector>
using namespace std;

class Heap{
	vector<int> v;
	//helps us identify if the heap is min heap or max heap
	bool minheap;

	bool compare(int a, int b){
		if (minheap){
			return a < b;
		} else {
			return b < a;
		}
	}

	void heapify(int i){
		int left = 2 * i;
		int right = left + 1;

		int minIndex = i;
		int lastIndex = v.size() - 1;

		//this will swap the ith node with its left node, if ith node
		//is smaller than its left node
		if (left <= lastIndex && compare(v[left], v[i])){
			minIndex = left;
		}

		//this will swap the right node with the min index node if right
		//node is smaller.
		if (right <= lastIndex && compare(v[right], v[minIndex])){
			minIndex = right;
		}

		//so after these two operations, we will have the lowest/highest 
		//value at index i

		if (minIndex != i){
			swap(v[i], v[minIndex]);
			heapify(minIndex);
		}
	}

public:
	Heap(int defaultSize = 10, bool type = true){
		v.reserve(defaultSize);

		//this is done to block the 0th index of the vector
		v.push_back(-1);

		minheap = type;
	}

	void push(int data){
		v.push_back(data);

		//now after pushing the data, the size of the vector will be 11
		//because we reserved 10 indexes, and now we pushed 1 more element

		int idx = v.size() - 1;
		int parent = idx / 2;

		//keep pushing till you reach the root node or stop midway because 
		//current element is already greater than parent
		while (idx > 1 and compare(v[idx], v[parent])){
			//we use a compare function to make the heap class work for both 
			//min heap and max heap. In case of min heap the condition will be
			//v[idx] <  v[parent] 

			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}

	int top(){
		return v[1];
	}

	void pop(){
		int lastIndex = v.size() -1;
		swap(v[1], v[lastIndex]);
		v.pop_back();
		heapify(1);
	}

	bool empty(){
		return v.size() == 1;
	}

};


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    Heap h(10, false);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	int num;
    	cin >> num;
    	h.push(num);
    }

    while(!h.empty()){
    	cout << h.top() << " ";
    	h.pop();
    }

    return 0;
}