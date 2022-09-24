#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > m;

public:
	void addEdge(T x, T y){
		m[x].push_back(y);

	}

	int bfs(T root, T dest){
		map<T, int> distance;
		map<T, T> parent;
		queue<T> q;

		for(auto node_pair: m){
			distance[node_pair.first] = INT_MAX;
		}

		q.push(root);
		distance[root] =0;
		parent[root] = root;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(auto nbr: m[node])
				if (distance[nbr] == INT_MAX){
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
					parent[nbr] = node;
				}
		}

		// for(auto node_pair : m){
		// 	T node = node_pair.first;;
		// 	int dist = distance[node];
		// 	cout << "node: " << node << " dist: " << dist << endl;
		// }


		T temp = dest;
		while(temp != root){
			cout << temp<<"<--";
			temp = parent[temp];
		}
		cout << root << endl;

		return distance[dest];

	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int board[50] = {0};

	//this denotes the jumps that we can make. EG:- from 2nd position we can make
	//a jump of 13, so we will end up at 15. Similarly from 17 we can make a jump of
	//-13 which will lead us to 4

	board[2] = 13;
	board[5] = 12;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	Graph<int> g;

	for(int i = 0; i < 37; i++){
		for(int dice = 1; dice <= 6; dice++){
			int j = i + dice;
			//calculates the movement due to dice
			j += board[j];
			//calculates the movement due to jump


			if (j <= 36){
				g.addEdge(i, j);
				//directed edge
			}
		}
	}
	g.addEdge(36, 36);

	cout << g.bfs(0, 36) << endl;

}