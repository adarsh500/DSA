#include <bits/stdc++.h>
using namespace std;
//note: here it doesn't matter what the parent and rank of other numbers is
//all that matters are parent and rank of root node is correct

class Graph{
	int V;
	list< pair< int, int>> l;
	//here we are creating an edge list and not an adjacency list
public:
	Graph(int V){
		this->V = V;
	}

	void addEdge(int x, int y){
		l.push_back({x, y});
	}

	int findSet(int i, int parent[]){
		if (parent[i] == -1){
			return i;
		}
		//without optimization
		// return findSet(parent[i], parent);

		//after optimization
		// basically stores the parent of each child node as root node, so comparisons have to be lessd
		return parent[i] = findSet(parent[i], parent);
	}

	void unionSet(int x, int y, int parent[], int rank[]){
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		//unoptimized
		// if (s1 != s2){
		// 	parent[s1] = s2;
		// }

		//optimizing using union by rank
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
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(2, 5);
	// g.addEdge(2, 6);

	if(g.containsCycle()){
		cout << " has cycle";
	} else {
		cout << "no cycle";
	}
	cout << endl;

}