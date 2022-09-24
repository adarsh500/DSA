//TIME COMPLEXITY of Dijkshtra: E log (E + V)

#include <bits/stdc++.h>
using namespace std;

int n, m;

template <typename T>
class Graph{
	map<T, list< pair<T, int> > > m;

public:
	void addEdge(T x, T y, int dist, bool bidirectional = true){
		m[x].push_back({y, dist});

		if (bidirectional){
			m[y].push_back({x, dist});

		}
	}

	void printAdj(){
		//function to print the adjacency list
		for(auto item : m){
			T key = item.first;
			auto value = item.second;
			cout << key << " -> ";

			for(auto nbr : value) {
				T childKey = nbr.first;
				int dist = nbr.second;
				cout << "(" << childKey << ","<< dist << ")";
			}
			cout << endl;
		}
	}

	void dijsktraSSSP(T src){
		map<T, int> dist;
		//used to store the distance of all nodes;

		for(auto item : m){
			dist[item.first] = INT_MAX;
		}	

		set< pair<int , T>> s;
		//distance will the the first item as pairs are sorted according to
		//thier first element. NOTE : sets are sorted


		dist[src] = 0;
		s.insert({0, src});

		while(!s.empty()){
			//find the first pair of the set
			//NOTE: s.begin() is an iterator
			auto p = *(s.begin());
			T node = p.second;
			int nodeDist = p.first;

			s.erase(s.begin());

			for(auto childPair: m[node]){
				if (nodeDist + childPair.second < dist[childPair.first]){
					//we cannot update elements in set, so we delete and
					//insert

					T dest = childPair.first;
					auto f = s.find({dist[dest], dest});
					if (f != s.end()){
						s.erase(f);
					}

					dist[dest] = nodeDist + childPair.second;
					s.insert({dist[dest], dest});
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if (i == src){
				continue;
			} else if (dist.find(i) != dist.end()){
				if (dist[i] == INT_MAX){
					cout << -1 << " ";
				} else {
					cout << dist[i] << " ";					
				}
			} else {
				cout << -1 << " ";
			}
		}
		cout << endl;
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int q = 1;
	cin >> q;
	while(q--){
		int src;
		Graph<int> g;
		cin >> n >> m;
		// n - nodes    m - edges
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			g.addEdge(u, v, 6, true);
		}

		cin >> src;

		g.dijsktraSSSP(src);
	}
}