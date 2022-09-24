// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int d)
//     {
//         data = d;
//         next = NULL;
//     }
// };

// // This function gets two arguments - the head pointers of the two linked lists
// // Return the node which is the intersection point of these linked lists
// // It is assured that the two lists intersect

// Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
// {
//     Node *temp1 = l1;
//     Node *temp2 = l2;
//     int len1 = 0, len2 = 0;
//     while (temp1 != NULL) {
//         len1++;
//         temp1 = temp1->next;
//     }

//     while (temp2 != NULL) {
//         len2++;
//         temp2 = temp2->next;
//     }
//     temp1 = l1;
//     temp2 = l2;
//     cout << len1 << " " << len2 << endl;
//     if (len1 > len2){
//         int diff = len1 - len2;

//         while(diff != 0){
//             diff--;
//             l1 = l1->next;
//         }
//     } else {
//         int diff = len2 - len1;

//         while(diff != 0){
//             diff--;
//             l2 = l2->next;
//         }
//     }
//     // temp1 != temp2 &&
//     while(temp1 != NULL && temp2 != NULL){
//         temp1 = temp1->next;
//         temp2 = temp2->next;

//         if (temp1 == temp2){
//             return temp1;
//         }
//     }
//     return NULL;
// }




// *
// *
// *   You do not need to refer or modify any code below this.
// *   Only modify the above function definition.
// *   Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
// *   You do not even need to read or know about the code below.
// *
// *
// *


// Node *buildList(unordered_map<int, Node *> &hash)
// {
//     int x;
//     cin >> x;
//     Node *head = new Node(x);
//     Node *current = head;
//     hash[x] = head;
//     while (x != -1)
//     {
//         cin >> x;
//         if (x == -1)
//             break;
//         Node *n = new Node(x);
//         hash[x] = n;
//         current->next = n;
//         current = n;
//     }
//     current->next = NULL;
//     return head;
// }

// void printLinkedList(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     unordered_map<int, Node *> hash;
//     Node *l1 = buildList(hash);

//     Node *l2 = NULL;
//     int x;
//     cin >> x;
//     l2 = new Node(x);
//     Node *temp = l2;

//     while (x != -1)
//     {
//         cin >> x;
//         if (x == -1)
//             break;
//         if (hash.find(x) != hash.end())
//         {
//             temp->next = hash[x];
//             break;
//         }
//         Node *n = new Node(x);
//         temp->next = n;
//         temp = n;
//     }

//     cout << "L1 - ";
//     printLinkedList(l1);
//     cout << "L2 - ";
//     printLinkedList(l2);

//     Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
//     cout << "Intersection at node with data = " << intersectionPoint->data << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    /*Code here*/
     Node *temp1=l1;
    Node *temp2=l2;
    int cnt1=0;
    int cnt2=0;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        cnt1++;
    }
    while(temp2!=NULL)
    {
        temp2=temp2->next;
        cnt2++;
    }

    temp1=l1;
    temp2=l2;
    if(cnt1>cnt2)
    {
        int diff=cnt1-cnt2;
        while(diff!=0)
        {
            diff--;
            temp1=temp1->next;
        }
    }
    else
    {
        int diff=cnt2-cnt1;
        while(diff!=0)
        {
            diff--;
            temp2=temp2->next;
        }
    }
    while(temp1!=temp2 && temp1!=NULL && temp2!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=temp2)
    {
        return NULL;
    }
    return temp1;
}



/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*   Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*   You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x];
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }
}