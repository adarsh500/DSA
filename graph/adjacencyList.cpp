#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	//we create a pointer to an array of list. We can allocate memory to it,
	//when we can get the value of V
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y){
		//we are creating a bidirectional edge 
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printAdjList(){
		for(int i = 0; i < V; i++){
			cout << "vertex  " << i << "->";
			for (auto x : l[i]){
				cout << x << ",";
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
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.printAdjList();
}