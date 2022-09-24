#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > m;
public:
	void addEdge(T x, T y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	void bfs(T root){
		queue<T> q;
		map<T, bool> visited;

		q.push(root);
		visited[root] = true;

		while(!q.empty()){
			T temp = q.front();
			cout << temp << " ";
			q.pop();

			for(auto nbr : m[temp]){
				if (!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout << endl;
	}

	int pairing(T src){
		
	}

	// void SingleSourcesShortestPath(T root){
	// 	map<T, int> distance;
	// 	queue<T> q;

	// 	for(auto node_pair: m){
	// 		distance[node_pair.first] = INT_MAX;
	// 	}

	// 	q.push(root);
	// 	distance[root] =0;

	// 	while(!q.empty()){
	// 		T node = q.front();
	// 		q.pop();

	// 		for(auto nbr: m[node])
	// 			if (distance[nbr] == INT_MAX){
	// 				q.push(nbr);
	// 				distance[nbr] = distance[node] + 1;
	// 			}
	// 	}

	// 	for(auto node_pair : m){
	// 		T node = node_pair.first;;
	// 		int dist = distance[node];
	// 		cout << "node: " << node << " dist: " << dist << endl;
	// 	}

	// }
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	// cout << n << " "<< m << endl;
	Graph g;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}
	cout << g.pairing() << endl;
}