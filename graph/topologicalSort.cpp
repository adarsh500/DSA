#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,  list<T> > m;
public:
	void addEdge(T x, T y){
		m[x].push_back(y);
		// m[y].push_back(x);
	}

	void dfsHelper(T src, map<T, bool> &visited, list<T> &ordering){
		visited[src] = true;

		for(auto node : m[src]){
			if (!visited[node]){
				dfsHelper(node, visited, ordering);
			}
		}

		ordering.push_front(src);
		return;

	}

	void dfs(){
		map<T, bool> visited;
		list<T> ordering;

		for(auto node : m){
			visited[node.first] = false;
		}

		for(auto p : m){
			T node = p.first;
			if (!visited[node]){
				dfsHelper(node, visited, ordering);
			}
		}

		for(auto node: ordering){
			cout << node << endl;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph<string> g;
	g.addEdge("python", "data preprocessing");
	g.addEdge("python", "pytorch");
	g.addEdge("python", "ml");
	g.addEdge("data preprocessing", "ml");
	g.addEdge("pytorch", "dl");
	g.addEdge("ml", "dl");
	g.addEdge("dl", "facerecog");
	g.addEdge("dataset", "facerecog");
	g.dfs();
}