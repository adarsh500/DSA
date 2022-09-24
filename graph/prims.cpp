#include <bits/stdc++.h>
using namespace std;

class Graph{
	vector<pair<int, int>> *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l = new vector< pair< int, int > >[V];
	}

	void addEdge(int x, int y, int w){
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prims(){
		//initialize a min heap
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;

		bool *visited = new bool[V]{0};
		int ans = 0;

		Q.push({0, 0});
		//format in queue is:  weight, destination vertex;
		//format in adj list: dest vertex, weight;
		while(!Q.empty()){
			auto best = Q.top();
			Q.pop();
			int to = best.second;
			int weight = best.first;


			if (visited[to]){
				continue;
			}

			ans += weight;
			visited[to] = 1;

			for(auto x : l[to]){
				if (visited[x.first] == 0){
					Q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}

	cout << g.prims() << endl;
}