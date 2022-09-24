

// There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.
// Input Format

// First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k
// Constraints

// 1<=N<=10^7
// 1<=k<=N
// 1 <= Ai <= 100000
// Output Format

// Space separated integers in a single line denoting strength of strongest fighters in the groups.
// Sample Input

// 5
// 1 3 1 4 5
// 3

// Sample Output

// 3 4 5

// Explanation

// First sub-group: 1 3 1 --> Max strength is 3
// Second sub-group: 3 1 4 --> Max strength is 4
// Third sub-group: 1 4 5 --> Max strength is 5



// #include <iostream>
// #include <deque>
// #define lli long long int  
// using namespace std;

// int main(){
// 	lli n, k, i;
// 	lli arr[10000];

// 	cin >> n;
// 	for (lli i = 0; i < n; i++){
// 		cin >> arr[i];
// 	}
// 	cin >> k;


// 	deque<lli> Q;
// 	for(i = 0; i < k; i++){
// 		while(!Q.empty() && arr[i] >= arr[Q.back()]){
// 			Q.pop_back();
// 		}
// 		Q.push_back(i);
// 	}

// 	for(; i < n; i++){
// 		cout << arr[Q.front()] << " ";

// 		//this means while the elements in the deque are less than the window
// 		//1.remove elements that are not a part of the window
// 		while(!Q.empty() && (Q.front() <= i - k)){
// 			Q.pop_front();
// 		}

// 		//2. remove elements that are not useful in the window
// 		while(!Q.empty() && arr[i] >= arr[Q.back()]){
// 			Q.pop_back();
// 		}

// 		//3. Add the new elements
// 		Q.push_back(i);
// 	}

// 	cout << arr[Q.front()] << " " << endl;
// }


//apparently CB is accepting only the below solution
#include<iostream>
#include<deque>
using namespace std;

int main(){
	long n;
	cin>>n;
	long *a = new long[n];
	for(long i=0;i<n;i++){
		cin>>a[i];
	}
	long k;
	cin>>k;
	
	deque<long> q(k);
	
	
	for(long i=0;i<k;i++){
		while(!q.empty() && a[q.back()] <= a[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	for(long i=k;i<n;i++){
        cout<<a[q.front()]<<" ";
		while(!q.empty() && (q.front() <= i-k)){
			q.pop_front();
		}
		while(!q.empty() && a[i] >= a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
    cout<<a[q.front()];
	
	return 0;
}