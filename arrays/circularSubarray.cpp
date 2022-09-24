// You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.


// Input Format
// First line contains integer t which is number of test case.
// For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.


// Constraints
// 1<=t<=100 
// 1<=n<=1000 
// |Ai| <= 10000


// Output Format
// Print the maximum circular sum for each testcase in a new line.


// Sample Input
// 1
// 7
// 8 -8 9 -9 10 -11 12
// Sample Output
// 22
// Explanation
// Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)


// This Question can be done using the brute force viz, by using two nested loops and checking the sum of every possible subset but this approach is in O(n^2). So, Now we are going to discuss an approach which solves the given problem in O(n).

// Approach :
// For finding the Maximum Contiguous sum we are using the kadanes algorithm. But in the question the array is circular that means the maximum sum can be of elements which are a part of the wrapping or not. So,
// There can be two cases for the maximum sum:
// Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

// Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. Let us see how. 
// Wrapping of contributing elements implies non wrapping of non contributing elements, so find out the sum of non contributing elements and subtract this sum from the total sum. To find out the sum of non contributing, 
// invert sign of each element and then run Kadane’s algorithm. Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays.

#include<iostream>
#include<algorithm>
using namespace std;

int kadane(int input[],int n) {
	int maxSum = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum += input[i];
		if (sum < 0){
			sum = 0;
		}
		maxSum = max(sum, maxSum);
	}
	return maxSum;
}


int maxCircularSum(int input[], int n)
{
    int max_kadane = kadane(input, n);
    if(max_kadane < 0)
      return max_kadane;

    int max_wrap = 0, i;
    for (i = 0; i < n; i++) {
        max_wrap += input[i]; 
        input[i] = -input[i]; 
    }
 
    // max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(input, n);
 
    // The maximum circular sum will be maximum of two sums
    return max(max_wrap, max_kadane);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int input[n];
		int sum = 0, maxSum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> input[i];
		}

		cout << maxCircularSum(input, n) << endl;


		// for (int i = 0; i < n; ++i)
		// 	{
		// 		cout << input[i] << " ";
		// 	}
	}
	return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// // Standard Kadane's algorithm to find maximum subarray sum
// int kadane(int a[], int n);

// // The function returns maximum circular contiguous sum in a[]
// int maxCircularSum(int a[], int n)
// {
// // Case 1: get the maximum sum using standard kadane's algorithm
// int max_kadane = kadane(a, n);

// // Case 2: Now find the maximum sum that includes
// // corner elements.
// int max_wrap = 0, i;
// for (i=0; i<n; i++)
// {
//         max_wrap += a[i];     // Calculate array-sum
//         a[i] = -a[i];       // invert the array (change sign)
// }

// // max sum with corner elements will be:
// // array-sum - (-max subarray sum of inverted array)
// max_wrap = max_wrap + kadane(a, n);

// // The maximum circular sum will be maximum of two sums
// return (max_wrap > max_kadane)? max_wrap: max_kadane;
// }

// // Standard Kadane's algorithm to find maximum subarray sum
// int kadane(int a[], int n)
// {
//     int max_so_far = 0, max_ending_here = 0;
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         max_ending_here = max_ending_here + a[i];
//         if (max_ending_here < 0)
//             max_ending_here = 0;
//         if (max_so_far < max_ending_here)
//             max_so_far = max_ending_here;
//     }
//     return max_so_far;
// }

// /* Driver program to test maxCircularSum() */
// int main()
// {
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//        int n;
//        cin>>n;
//        int a[n];
//        for(int j=0;j<n;j++)
//        {
//            cin>>a[j];
//        }
//         cout<< maxCircularSum(a, n) <<endl;
//     }
//     return 0;
// }