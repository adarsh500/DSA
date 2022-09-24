#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list< pair< int, int>> l;
public:
	Graph(int V){
		this->V = V;
		// cout << V << endl;
	}

	void addEdge(int x, int y){
		l.push_back({x, y});
	}

	int findSet(int i, int parent[]){
		if (parent[i] == -1){
			return i;
		}
		return parent[i] = findSet(parent[i], parent);
	}

	void unionSet(int x, int y, int parent[], int rank[]){
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);
		if (s1 != s2){
			if (rank[s1] < rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool containsCycle(){
		int *parent = new int [V];
		int *rank = new int[V];
		for(int i = 0; i < V; i++){
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge : l){
			int x = edge.first;
			int y = edge.second;

			int s1 = findSet(x, parent);
			int s2 = findSet(y, parent);

			if (s1 != s2){
				unionSet(s1, s2, parent, rank);
			} else {
				return true;
			}
		}

		for(int i = 0; i < V; i++){
			cout << parent[i] << " ";
		}

		cout << endl;
		for(int i = 0; i < V; i++){
			cout << rank[i] << " ";
		}
		cout << endl;

		delete [] parent;
		delete []rank; 
		return false;
	}

	int pairing(){
		int *parent = new int[V];
		int *rank = new int[V];

		for(int i = 0; i < V; i++){
			parent[i] = -1;
			rank[i] = 1;
		}

		for(auto edge : l){
			int x = edge.first;
			int y = edge.second;

			int s1 = findSet(x, parent);
			int s2 = findSet(y, parent);

			unionSet(s1, s2, parent, rank);	
		}

		int ans = 0;
		for(int i = 0; i < V; i++){
			ans += V - rank[findSet(i, parent)];
		}

		delete [] parent;
		delete [] rank; 

		return ans / 2;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int n, m;
	cin >> n >> m;
	// cout << n << " "<< m << endl;
	Graph g(n);
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.pairing() << endl;

}