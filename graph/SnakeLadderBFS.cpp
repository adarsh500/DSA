#include <bits/stdc++.h>
using namespace std;

class Graph{
	map<int, list<int>> m;
public:
	void addEdge(int x, int y){
		m[x].push_back(y);
	}

	int bfs(int root, int dest){
		map<int, int> dist;
		queue<int> q;

		for(auto x : m){
			dist[x.first] = INT_MAX;
		}

		q.push(root);
		dist[root] = 0;
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			for(auto x : m[temp]){
				if (dist[x] == INT_MAX){
					q.push(x);
					dist[x] = dist[temp] + 1;
				}
			}
		}
		return dist[dest];
	}

};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int board[50] = {0};
	int t;
	cin >> t;
	while(t--){
		Graph g;
		int n, l, s, start, end;
		cin >> n >> l >> s;
		for(int i = 0; i < l; i++){
			cin >> start >> end;
			board[start] = end - start;
		}

		for(int i = 0; i < s; i++){
			cin >> start >> end;
			board[start] = end - start;
		}

		for(int i = 0; i < n + 1; i++){
			for(int dice = 1; dice < 7; dice++){
				int j = i + dice;
				j += board[j];

				if (j <= n){
					g.addEdge(i, j);
				}
			}
		}
		g.addEdge(n, n);
		cout << g.bfs(0, n) << endl;


	}
}