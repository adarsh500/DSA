// //Tricky Permutations
// //https://hack.codingblocks.com/contests/c/537/737
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// string ans[100000];
// int c = 0;

// void permute(string inp,int i)
// {
//     //Base case
//     if(i == inp.size())
//     {
//         ans[c++] = inp;
//         return ;
//     }

//     //Recursive case
//     for(int j = i;j<inp.length() ; j++)
//     {
//         swap(inp[i],inp[j]);
//         permute(inp,i+1);
//         swap(inp[i],inp[j]);    //Backtrack
//     }
// }
// int main()
// {
//     string input;
//     cin>>input;

//     permute(input,0);
//     sort(ans,ans+c);

//     string temp = "";
//     for(int i = 0;i<c;i++)
//     {
//         if(temp != ans[i])
//             cout<<ans[i]<<endl;
//         temp = ans[i];
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

void permutationNoDuplicates(string ques, string ans) {

	if (ques.length() == 0) {
		cout << ans << "\n";
		return;
	}

	for (int i = 0; i < ques.length(); i++) {
		char ch = ques[i];
		string ros = ques.substr(0, i) + ques.substr(i + 1);

		bool flag = true;

		for (int j = i + 1; j < ques.length(); j++) {
			if (ques[j] == ch) {
				flag = false;
			}
		}
		if (flag)
			permutationNoDuplicates(ros, ans + ch);
	}
}

int main() {
	string str;
	cin >> str;

	sort(str.begin(), str.end());

	permutationNoDuplicates(str, "");

	return 0;
}