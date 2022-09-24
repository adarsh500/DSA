#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n], XOR, setBit, res1, res2;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		XOR = XOR ^ arr[i];
	}

	setBit = XOR & ~(XOR-1);

	for (int i = 0; i < n; i++){
		if ((arr[i] & setBit) != 0){
			res1 = res1 ^ arr[i];
		} else {
			res2 = res2 ^ arr[i];
		}
	}

	(res1 < res2) ? (cout << res1 << " " << res2 << endl) : (cout << res2 << " " << res1 << endl);
	return 0;
}
