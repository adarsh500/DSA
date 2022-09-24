#include <iostream>
#include <list>
using namespace std;

int main() {
	//how to creaet a normal list
	// list<pair<int, int> > l or list<pair<int, int> > l[5]

	//we will be creating a dynamic list;
	list<pair<int, int> > *l;
	int n;
	cin >> n;

	//here l is a pointer to an array of linked list
	l = new list<pair<int, int> >[n];

	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++) {
		int x, y, weight;
		cin >> x >> y >> weight;
		l[x].push_back(make_pair(y, weight));
		l[y].push_back(make_pair(x, weight));
	}

	for (int i = 0; i < n; i++){
		cout << "linked list " << i << "->";
		for (auto xp: l[i]){
			cout << "(" << xp.first << "," << xp.second << ")";
		}
		cout << endl;
	}
}