// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int main(){
// 	#ifndef ONLINE_JUDGE	
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		vector<ll> v;
// 		ll c, res = 0;
// 		cin >> c;
// 		for(ll i = 60; i >= 0; i--){
// 			//stores the difference between c and the current bit
// 			ll num1 = (1ll << i) & c;

// 			//stores the difference between the current bit and result
// 			ll num2 = (1ll << i) & res;

// 			if (num1 != num2){
// 				v.push_back((1 << (i + 1)) - 1);
// 				res ^= ((1 << (i + 1)) - 1);
// 			}
// 		}
// 		if(v.empty()){
// 			v.push_back(1);
// 			v.push_back(1);
// 		}
// 		cout << v.size() << "\n";
// 		for(int i = 0; i < v.size(); i++){
// 			cout << v[i] << " ";
// 		}
// 		cout << "\n";
// 	}	
// 	return 0;
// }

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
     int tests;
     cin >> tests;
     while (tests--)
     {
          ll C;
          cin >> C;

          ll cur_xor = 0;
          vector<ll> arr;

          for (int i = 60; i >= 0; i--)
          {
               ll bit1 = (1ll << i) & cur_xor;
               ll bit2 = (1ll << i) & C;

               if (bit1 != bit2)
               {
                    arr.push_back((1ll << (i + 1)) - 1);
                    cur_xor ^= (1ll << (i + 1)) - 1;
               }
          }

          if (arr.empty())
               arr = {1, 1};

          cout << arr.size() << endl;
          for (int i = 0; i < arr.size(); i++)
               cout << arr[i] << " ";
          cout << endl;
     }
     return 0;
}