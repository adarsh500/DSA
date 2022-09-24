// #include <bits/stdc++.h>
// using namespace std;

// class functor{
// public:
// 	bool operator()(p<int, int> a, p<int, int> b){
// 		if (a.first == b.first){
// 			return a.second > b.second;
// 		} else {
// 			return a.first < b.first;
// 		}
// 	}
// };


// int main() {

// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
// 	int t;
// 	cin >> t;
// 	while (t--) {
// 		int n, k;
// 		cin >> n >> k;
// 		int arr[n];
// 		for (int i = 0; i < n; i++) {
// 			cin >> arr[i];

// 		}

// 		int freq[100000] = {0};

// 		priority_queue<p<int, int> , vector<p<int, int>>, functor> pq;

// 		for(int i = 0; i < n; i++){
// 			int temp = k;
// 			freq[arr[i]]++;
// 			for(int j = 0; j <= i; j++){
// 				p<int, int> p(freq[arr[i]], arr[i]);



// 				pq.push(p);
// 			}

// 			while(!pq.empty() && temp--){
// 				p<int, int> front = pq.top();
// 				cout << front.second << " ";
// 				int f = front.first;
// 				while(f--){
// 					pq.pop();
// 				}
// 			}

// 			while(!pq.empty()){
// 				pq.pop();
// 			}
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;

class p {
public:
	int freq, num;
	p(int freq, int num)
	{
		this->freq = freq;
		this->num = num;
	}
};

class functor {
public:
	bool operator()(p x1, p x2)
	{
		if (x1.freq == x2.freq)
			return x1.num > x2.num; 
			//When frequency of 2 elements is same, the smaller 
			//of the 2 elements will be at the top of the heap.
		else
			return x1.freq < x2.freq; 
			//Max heap based on frequency count
	}
};
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t; int n, k;
	cin >> t;
	int *arr;
	while (t--)
	{
		priority_queue<p, vector<p>, functor>pq; 
		//Preparing a priority queue of p type
		//(ie. based on the number and on the frequency)
		cin >> n >> k;
		arr = new int[n]; int temp;
		int count[100] = {0}; //To maintain frequency count of each number
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < n; i++)
		{
			count[arr[i]]++;
			temp = k;
			for (int j = 0; j <= i; j++) {
				p y(count[arr[j]], arr[j]);
				pq.push(y);
				//Pushing an object of class p
				//(containg the number and its frequency) to the heap
			}
			while (!pq.empty() && temp--)
			{
				p front = pq.top();
				cout << front.num << " ";
				int freq = front.freq;
				while (freq--) //Emptying the heap
					pq.pop();
			}
			while (!pq.empty())
				pq.pop();
		}
		cout << endl;
	}
	return 0;
}