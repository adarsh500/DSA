/*
STEPS:

1. init dist[vertices] = INT_MAX, dist[src] = 0;
2. relax all edges V - 1 times
3. Negative weight cycle detection
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, int src, vector<vector<int>> edges){
	//create a vector
	vector<int> dist(V + 1, INT_MAX);
	dist[src] = 0;

	//relax all edges V - 1 times;
	for(int i = 0; i < V - 1; i++){
		for(auto edge : edges){
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]){
				dist[v] = dist[u] + wt;
			}
		}
	}

	//check the presence of a negative weight cycle
	for(auto edge : edges){
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]){
			cout << "negative weight cycle found" << endl;
			exit(0);
		}
	}

	return dist;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;

	vector< vector<int> > edges;
	for(int i = 0; i < m; i++){
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}

	vector<int> dist = bellmanFord(n, 1, edges);

	for(int i = 1; i <= n; i++){
		cout << "node " << i << " is at a distance of " << dist[i] << endl;
	}

	return 0;
}