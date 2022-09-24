#include <bits/stdc++.h>
using namespace std;

class Graph{
	unordered_map<string, list<pair<string, int>>> map;

public:
	void insertEdge(string x, string y, bool birectional, int weight){
		map[x].push_back({y, weight});
		if (birectional){
			map[y].push_back({x, weight});
		}
	}


	void printAdjList(){
		for(auto p : map){
			string key = p.first;
			cout << "key: " << key << "->";
			auto value = p.second;
			for(auto x : value){
				cout << "(" << x.first << ","<< x.second << ") ";
			}
			cout << endl;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph g;
	g.insertEdge("A", "B", true, 10);
	g.insertEdge("A", "C", true, 20);
	g.insertEdge("A", "D", false, 10);
	g.printAdjList();

}