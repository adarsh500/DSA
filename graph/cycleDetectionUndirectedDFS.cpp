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

	void addEdge(int x, int y, bool directed = true){
		l[x].push_back(y);

		if (!directed){
			l[y].push_back(x);			
		}
	}

	bool cycleHelper(int node, bool *visited, int parent){
		//visit a node
		visited[node] = true;

		for(int nbr : l[node]){
			if (!visited[nbr]){
				bool cycleFound = cycleHelper(nbr, visited, node);
				if(cycleFound){
					return true;
				}
			//here nbr is visited but the nbr is not parent node
			} else if(visited[nbr] && nbr != parent){
				return true;
			}
		}

		return false;
	}

	bool containsCycle(){
		bool *visited = new bool[V];
		return cycleHelper(0, visited, -1);
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Graph<int> g(7);
	g.addEdge(0,1, true);
	g.addEdge(1,2, true);
	g.addEdge(2,3, true);
	g.addEdge(3,4, true);
	g.addEdge(0,4, true);
	if (g.containsCycle()){
		cout << "has a cycle";
	} else {
		cout << "doesn't have a cycle";
	}
	cout << endl;

}