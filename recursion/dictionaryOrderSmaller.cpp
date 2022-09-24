#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string s1, string s2) {
    // cout << "s1:" << s1 << " " << "s2:" << s2 << endl;
    return s1 < s2;
}


void stringPermutations(string str, vector<string> &v, int l, int r, string str1) {
    if (l == r) {
        if (str < str1) {
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