// Deepak and Gautam are having a discussion on a new type of number that they call Coding Blocks Number or CB Number. They use following criteria to define a CB Number.

// 0 and 1 are not a CB number.
// 2,3,5,7,11,13,17,19,23,29 are CB numbers.
// Any number not divisible by the numbers in point 2( Given above) are also CB numbers.
// Deepak said he loved CB numbers.Hearing it, Gautam throws a challenge to him.

// Gautam will give Deepak a string of digits. Deepak's task is to find the number of CB numbers in the string.

// CB number once detected should not be sub-string or super-string of any other CB number. 
// Ex- In 4991, both 499 and 991 are CB numbers but you can choose either 499 or 991, not both.

// Further, the CB number formed can only be a sub-string of the string.
// Ex - In 481, you can not take 41 as CB number because 41 is not a sub-string of 481.

// As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CB numbers that can be formed from the given string.

// Deepak has to take class of Launchpad students. Help him by solving Gautam's challenge.


// Input Format
// First line contain size of the string.

// Next line is A string of digits.


// Constraints
// 1 <= Length of strings of digits <= 17


// Output Format
// Maximum number of CB numbers that can be formed.


// Sample Input
// 5
// 81615
// Sample Output
// 2
// Explanation
// 61 and 5 are two CB numbers.

// #include <iostream>
// #include<string>
// using namespace std;
// bool isCB(long long sub)
// {
//     //int flag=0;
//     //cout<<sub<<" ";
//     if(sub==0||sub==1)
//     {
//         //cout<<endl;
//         return false;
//     }
//     int prime[10]={2,3,5,7,11,13,17,19,23,29};
//     for(int i=0;i<10;i++)
//     {
//         if(sub==prime[i])
//         {
//             //flag=1;
//             //cout<<flag<<" "<<sub<<endl;
//             return true;
//         }
//     }
//     for(int i=0;i<10;i++)
//     {
//         if(sub % prime[i]==0)
//         {
//             //cout<<endl;
//             return false;
//         }
//     }
//     //flag=1;
//     //cout<<flag<<" "<<sub<<endl;
//     return true;
// }



// bool isValid(bool visited[17], string str,int start,int end)
// {
//     //cout<<"isValid starts ";
//     //cout<<str<<" ";
//     //cout<<"("<<start<<","<<end<<")"<<endl;
//     /*for(int j=start;j<end;j++)
//     {
//         cout<<str[j];
//     }
//     cout<<endl;
//     */
//     //int flag=0;
//     for(int i=start;i<end;i++)
//     {
//         if(visited[i])
//         {
//             //flag=1;
//             //cout<<"("<<start<<","<<end<<") "<<flag<<endl;
//             return false;
//         }
//     }
//     //cout<<"isValid starts ";
//     //cout<<str<<" ";
//     //cout<<"("<<start<<","<<end<<") "<<flag<<endl;
//     return true;
// }



// int main()
// {
//     int N,cnt=0;
//     cin>>N;
//     string str;
//     cin>>str;
//     //getline(cin,str);
//     //cout<<str<<" dfghj";
//     bool visited[str.length()];
//     for(int k=0;k<str.length();k++)
//     {
//         visited[k]=false;
//     }
//     for(int len=1;len<=str.length();len++)
//     {
//         for(int start=0;start<=str.length()-len;start++)
//         {
//             //cout<<"HJl"<<start;

//             int end=start+len;
//             //cout<<start<<","<<end<<endl;
//             string sub=str.substr(start,len);
//             //cout<<sub<<endl;
//             if(isCB(stoll(sub)) && isValid(visited,sub,start,end))
//             {
//                 //cout<<"FGHJ";
//                 cnt++;
//                 //cout<<sub<<endl;
//                 for(int i=start;i<end;i++)
//                 {
//                     visited[i]=true;
//                 }
//             }
//         }
//     }
//     cout<<cnt;

// }

//WITHOUT THE COMMENTS
// #include <iostream>
// #include<string>
// using namespace std;
// bool isCB(long long sub)
// {
//     if(sub==0||sub==1)
//     {
//         return false;
//     }
//     int prime[10]={2,3,5,7,11,13,17,19,23,29};
//     for(int i=0;i<10;i++)
//     {
//         if(sub==prime[i])
//         {
//             return true;
//         }
//     }
//     for(int i=0;i<10;i++)
//     {
//         if(sub % prime[i]==0)
//         {
//             return false;
//         }
//     }
//     return true;
// }



// bool isValid(bool visited[17], string str,int start,int end)
// {
//     for(int i=start;i<end;i++)
//     {
//         if(visited[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }



// int main()
// {
//     int N,cnt=0;
//     cin>>N;
//     string str;
//     cin>>str;
//     bool visited[str.length()];
//     for(int k=0;k<str.length();k++)
//     {
//         visited[k]=false;
//     }
//     for(int len=1;len<=str.length();len++)
//     {
//         for(int start=0;start<=str.length()-len;start++)
//         {
//             int end=start+len;
//             string sub=str.substr(start,len);
//             if(isCB(stoll(sub)) && isValid(visited,sub,start,end))
//             {
//                 cnt++;
//                 for(int i=start;i<end;i++)
//                 {
//                     visited[i]=true;
//                 }
//             }
//         }
//     }
//     cout<<cnt;

// }

//CB SOLUTION
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long convertToInt(string s)
{
    long i, j = 0;
    i = 0;
    while (s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool isCbNumber(string s)
{
    long long num = convertToInt(s);
    if (num <= 1) {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        if (num == arr[i]) {
            return true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (num % arr[i] == 0) {
            return false;
        }
    }

    return true;
}

bool isValid(bool * visited, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        if (visited[i])
        {
            return false;
        }
    }
    return true;
}

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    long count = 0;
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n - i; j++){  
         int e = j + i;
            string sub = s.substr(j, i);
            if (isCbNumber(sub) && isValid(visited, j, e)){
                count++;
                for (int k = j; k < i + j; k++){
                    visited[k] = true;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}



