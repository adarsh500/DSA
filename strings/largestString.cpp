#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	char arr[1000];
	char largest[1000];

	int len = 0, largest_len = 0;

	//this part stores \n as its first element, that is why there
	//is that gap between the n input and the first string
	// for (int i = 0; i < n; i++){
	// 	cin.getline(arr, 1000);
	// 	cout << arr << endl;
	// }

	//this is the fix to that issue : )
	//notice the differenct between lines 12-17 and 21-26
	cin.get();

	for (int i = 0; i < n; i++){
		cin.getline(arr, 1000);
		//cout << arr << endl;
		len = strlen(arr);
		if (len > largest_len){
			largest_len = len;
			strcpy(largest, arr); //syntax: strcpy(destination, source)
		}
	} 

cout << largest << " and " << largest_len << endl; 



	return 0;
}