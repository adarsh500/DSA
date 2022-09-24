#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,  list<T> > m;
public:
	void addEdge(T x, T y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void dfsHelper(T src, map<T, bool> &visited){
		cout << src << " ";
		visited[src] = true;

		for(auto node : m[src]){
			if (!visited[node]){
				dfsHelper(node, visited);
			}
		}
	}

	void dfs(T src){
		map<T, bool> visited;

		for(auto node : m){
			visited[node.first] = false;
		}

		dfsHelper(src, visited);
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(0);
}