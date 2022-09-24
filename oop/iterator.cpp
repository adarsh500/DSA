#include <iostream>
#include <list>
using namespace std;

template <typename T>
int search(T arr[],int n,T key){

    for(int p=0;p<n;p++){
        if(arr[p]==key){
            return p;
        }
    }
    //return n if element not found
    return n;
}

template<class ForwardIterator, class T>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key){
    while (start != end){
        if (*start == key){
            return start;
        }
        start++;
    }
    return end;
}


int main() {
    list<int> l;

    l.push_back(1);
    l.push_back(4);
    l.push_back(7);
    l.push_back(10);
    l.push_back(101);
    l.push_back(6);

    auto it = search(l.begin(),l.end(), 101);
    if (it == l.end()){
        cout << "element not found " << endl;
    } else {
        cout << "found at :" << *it << endl;
    }
}
