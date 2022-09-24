#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class node
{
public:
    node *next;
    int data;
    node() { next = NULL; }
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);
    return;
}

void newList(node *&head, int n, int k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == n)
    {
        return;
    }
    k = k%n;

    node *fast = head;
    node *slow = head;

    while (k > 0)
    {
        fast = fast->next;
        k--;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    node *agla = slow->next;
    fast->next = head;
    slow->next = NULL;
    head = agla;

    return;
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    int i = 0;
    while (i < n)
    {
        int d;
        cin >> d;
        insertAtTail(head, d);
        i++;
    }

    int k;
    cin >> k;

    newList(head, n, k);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}