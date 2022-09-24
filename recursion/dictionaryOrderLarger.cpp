


//program to generate all permutations of a stirng
// #include <iostream>
// using namespace std;
// void permute(string a,string b,string x,bool flag)
// {
//     if(a.length()==0)
//     {
//         if(x.compare(b)>0){
//             cout<<x<<endl;
//             return;
//         }
//     }
//     for(int j=0;a[j]!='\0';j++)
//     {
//         string ros = a.substr(0,j)+a.substr(j+1);
//         char ch = a[j];
//         if(flag)
//             permute(ros,b,x+ch,flag);
//         else{
//             if(a[j]>=a[0])
//                 permute(ros,b,x+ch,flag or ch>a[0]);
//         }
//     }
// }
// int main() {
//     string a,b;
//     cin>>a;
//     b=a;
//     permute(a,b,"",false);
// }



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string s1, string s2) {
    cout << "s1:" << s1 << " " << "s2:" << s2 << endl;
    return s1 < s2;
}


void stringPermutations(string str, vector<string> &v, int l, int r, string str1) {
    if (l == r) {
        if (str > str1) {
            v.push_back(str);
        }
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(str[i], str[l]);
        stringPermutations(str, v, l + 1, r, str1);
        swap(str[i], str[l]);
    }
}

int main() {
    string str;
    cin >> str;
    vector<string> v;
    stringPermutations(str, v, 0, str.size() - 1, str);
    sort(v.begin(), v.end(), cmp);
    for (auto x : v) {
        cout << x << endl;
    }
    return 0;
}