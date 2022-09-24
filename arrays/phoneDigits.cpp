// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find all possible combinations by
// replacing key's digits with characters of the 
// corresponding list
void findCombinations(vector<char> keypad[], 
                      int input[], string res, int index)
{
    // If processed every digit of key, print result
    if (index == -1) {
        cout << res << " ";
        return;
    }

    // Stores current digit
    int digit = input[index];

    // Size of the list corresponding to current digit
    int len = keypad[digit].size();

    // One by one replace the digit with each character in the
    // corresponding list and recur for next digit
    for (int i = 0; i < len; i++) {
        findCombinations(keypad, input, keypad[digit][i] + res, index - 1);
    }
}

// Driver Code
int main()
{
    // Given mobile keypada
    vector<char> keypad[] =
    {
        {}, {},        // 0 and 1 digit don't have any characters associated
        { 'a', 'b', 'c' },
        { 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}
    };

    // Given input array
    int input[] = { 2, 3, 4 };
  
    // Size of the array
    int n = sizeof(input)/sizeof(input[0]);

    // Function call to find all combinations
    findCombinations(keypad, input, string(""), n - 1);

    return 0;
}