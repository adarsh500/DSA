/*


You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.
Input Format

First line contains integer t as number of test cases.
Next t lines contains one balanced expression each.
Constraints

1 < t < 100
1< expression < 100
Output Format

Print "Duplicate" if the expression has any redundancy. Else print "Not Duplicates".
Sample Input

2
(((a+(b))+(c+d)))
((a+(b))+(c+d))

Sample Output

Duplicate
Not Duplicates

Explanation

For 1st test case : The subexpression "a+(b)" is surrounded by two pairs of brackets.


*/



#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {
	int t; 
	string str; 
	stack<char>s; 
	int count; 
	int flag;
	cin >> t;
	while (t--){
		cin >> str; flag = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ')')
				s.push(str[i]);
			else {
				count = 0;
				while (true) {
					if (s.top() != '(') {
						count++;
						s.pop();
					}
					if (s.top() == '(') {
						s.pop();
						break;
					}
				}
				if (count == 0) {
					cout << "Duplicate" << endl; 
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
			cout << "Not Duplicates" << endl;
	}
	return 0;
}