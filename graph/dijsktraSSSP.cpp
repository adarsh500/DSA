#include <bits/stdc++.h>
using namespace std;

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
		unordered_map<T, int> dist;
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
		for(auto d : dist){
			cout << d.first << " -> " << d.second << endl;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph<int> g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	g.printAdj();
	g.dijsktraSSSP(1);

	Graph<string> india;
	india.addEdge("amritsar", "delhi", 1);
	india.addEdge("amritsar", "jaipur", 4);
	india.addEdge("jaipur", "delhi", 2);
	india.addEdge("jaipur", "mumbai", 8);
	india.addEdge("bhopal", "agra", 2);
	india.addEdge("mumbai", "bhopal", 3);
	india.addEdge("agra", "delhi", 1);
	// india.printAdj();
	// india.dijsktraSSSP("amritsar");
}

