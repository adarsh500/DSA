#include <iostream>
#include <cstring>
using namespace std;

void replacePi(string s, int i){
	int len = s.length();
	if (i == len){
		cout << endl;
		return;
	}


	if (s[i] == 'p' and s[i + 1] == 'i'){
		cout << "3.14";
		replacePi(s, i + 2);
	} else {
		cout << s[i];
		replacePi(s, i + 1);
	}
}

string replace(string s)
{
    if (s.size() <= 1)
    {
        return s;
    }

    if (s.substr(0, 2) == "pi")
    {
        string ros = replace(s.substr(2));
        return "3.14" + ros;
    }

    string ros = replace(s.substr(1));
    return s[0] + ros;
}

int main(){
	int n;
	cin >> n;
	while (n--){
		string s;
		cin >> s;

		// replacePi(s, 0);
		string ans = replace(s);
		cout << ans << endl;
	}

}