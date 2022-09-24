#include <bits/stdc++.h>
using namespace std;

template<typename T>
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
		l[y].push_back(x);
	}

	bool isTree(){
		bool *visited = new bool[V];
		int *parent = new int[V];
		queue<int> q;

		for(int i = 0; i < V; i++){
			visited[i] = false;
			parent[i] = i;
		}
		int src = 0;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			for (auto nbr: l[node]){
				if (visited[nbr] == true and parent[nbr] != node){
					return false;
				} else if(!visited[nbr]) {
					visited[nbr] = true;
					q.push(nbr);
					parent[nbr] = node;
				}
			}
		}
		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Graph<int> g(4);
	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(1, 2);
	g.addEdge(0, 3);
	if (g.isTree()){
		cout << "its a treee";
	} else {
		cout << "Nop its nit";
	}
	cout << endl;
}