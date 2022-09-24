#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		l[x].push_back(y);
	}

	void topologicalSort(){
		int *indegree = new int[V];

		//setting the indegree of all nodes to 0
		for(int i = 0; i < V; i++){
			indegree[i] = 0; 
		}

		//update indegree by traversing all the nodes;
		for(int i = 0; i < V; i++){
			for(auto y : l[i]){
				indegree[y]++;
			}
		}

		queue<int> q;
		//1. find nodes with indegree as 0
		for(int i = 0; i < V; i++){
			for(auto y : l[i]){
				if (indegree[y] == 0){
					q.push(y);
				}
			}
		}

		//start traversing from those nodes which have indegree 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout << node << " ";

			for(auto y : l[node]){
				indegree[y]--;
				if (indegree[y] == 0){
					q.push(y);
				}
			}
		}
	}

};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,5);
	g.topologicalSort();

}