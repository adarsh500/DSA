// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, pair<int, int> > Node;
// //stores data of the node, the row number and the column number
// //in the same order

// vector<int> mergeKSortedArrays(vector< vector<int> > arr) {
// 	vector<int> result;

// 	priority_queue<Node, vector<Node>, greater<Node>> pq;

// 	for (int i = 0; i < arr.size(); i++) {
// 		pq.push({arr[i][0], {i, 0}});
// 	}

// 	while (!pq.empty()) {
// 		Node current = pq.top();
// 		pq.pop();
// 		int data = current.first;
// 		int row = current.second.first; //row in which element is present
// 		int column = current.second.second; // column in which element is presnt

// 		result.push_back(data);


// 		if (column + 1 < arr[row].size()) {
// 			//this makes sure that the column doesn't go out of bounds
// 			pq.push({arr[row][column + 1], {row, column + 1}});
// 		}
// 	}
// 	return result;
// }

// int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n, k, num;

// 	cin >> k >> n;

// 	vector<vector<int>>arr(k, vector<int>(n)); //Storing k sorted arrays in a 2d vector
// 	for (int i = 0; i < k; i++) {
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j];
// 	}

// 	// for (int i = 0; i < k; i++) {
// 	// 	// vector<int> v;
// 	// 	for (int j = 0; j < n; j++) {
// 	// 		cout << arr[i][j] << " ";
// 	// 		// cin >> num;
// 	// 		// v.push_back(num);
// 	// 	}
// 	// 	cout << endl;
// 	// 	// arr.push_back(v);
// 	// }

// 	vector<int> output = mergeKSortedArrays(arr);

// 	for (auto x : output) {
// 		cout << x << " ";
// 	}

// 	cout << endl;
// 	return 0;
// }




#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int, pair<int, int>> //Pair to store <Element , < RowNumber , ColNumber > >

vector<int> mergeKSortedArrays(vector<vector<int>> v)
{
    int k = v.size();
    int n = v[0].size();

    vector<int> res;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < k; i++)
    {
        //Push the first elements of all the rows into the PQ with their row and column number
        pq.push({v[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        //Take the smallest element out of PQ
        //Insert it into final result and push the next element of its row into the PQ
        ppi t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int rowNo = t.second.first;
        int colNo = t.second.second;
        if (colNo < n - 1)
        {
            //Check whether the current element is last element of its row or not. If so , do nothing.
            pq.push({v[rowNo][colNo + 1], {rowNo, colNo + 1}});
        }
    }

    return res;
}

int main()
{
    int k;  //No of rows
    int n;  //No of cols
    cin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> res = mergeKSortedArrays(v);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}