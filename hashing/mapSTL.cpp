#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	// ways to insert in a map

	map<string, int> m;

	m.insert(make_pair("mango", 120));

	pair<string, int> p;
	p.first = "Apple";
	p.second = 170;

	m.insert(p);

	m["banana"] = 40;

	string fruit;
	cin >> fruit;

	m[fruit] *= 2; 

	auto it = m.find(fruit);
	if (it != m.end()){
		cout << "the price of the fruit is: " << m[fruit] << endl;
	} else {
		cout << "fruit not found" << endl;
	}

	m.erase(fruit);

	if (m.count(fruit)){
		cout << "the price of the fruit is: " << m[fruit] << endl;
	} else {
		cout << "fruit not present" << endl; 
	}

	//maps store the unique keys only once. If the key is repeated,
	//then the value associated with it is updated 

	m["Kiwi"] = 70;
	m["dragonfruit"] = 150;

	for(auto it = m.begin(); it != m.end(); it++){
		cout << it->first << ": "<< it->second << endl;
	}

}