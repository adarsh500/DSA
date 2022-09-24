#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 
	unordered_map<string, vector<string>> phonebook;

	phonebook["rahul"].push_back("9103012983");
	phonebook["rahul"].push_back("1947370144");
	phonebook["rahul"].push_back("9182134983");
	phonebook["rahul"].push_back("9189172983");
	phonebook["Ada"].push_back("9102983783");
	phonebook["Ada"].push_back("9103192883");
	phonebook["tommy"].push_back("91122983");
	phonebook["tommy"].push_back("91031983");

	for(auto p: phonebook){
		cout << "name: " << p.first << "->";
		for(auto s: p.second){
			cout << s << " ->";
		}
		cout << endl;
	}

	string name;
	cin >> name;

	if (phonebook.count(name) == 0){
		cout << "absent" << endl;
	} else {
		for(auto s: phonebook[name]){
			cout << s << endl;
		}
	}

}