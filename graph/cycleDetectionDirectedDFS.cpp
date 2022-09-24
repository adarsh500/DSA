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

	bool cycleHelper(int node, bool *visited, bool *stack){
		//visit a node
		visited[node] = true;
		stack[node] = true;

		for(int nbr : l[node]){
			if (stack[nbr]){
				return true;
			} else if (visited[nbr] == false){
				bool cycleFound = cycleHelper(nbr, visited, stack);
				if(cycleFound){
					return true;
				}
			}
		}

		stack[node] = false;
		return false;
	}

	bool containsCycle(){
		bool *visited = new bool[V];
		bool *stack = new bool[V];
		for(int i = 0; i < V; i++){
			visited[i] = stack[i] = false;
		}
		return cycleHelper(0, visited, stack);
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Graph<int> g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(1,5);
	g.addEdge(5,6);
	g.addEdge(4,2);
	if (g.containsCycle()){
		cout << "has a cycle";
	} else {
		cout << "doesn't have a cycle";
	}
	cout << endl;

}