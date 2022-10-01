#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
Node *delete_m(Node *head, int m, int n)
{
    if (head == NULL || head->next==NULL|| n == 0)
    {
        return head;
    }
    if (m == 0)
    {
        return NULL;
    }
    int c1 = 1;
    int c2 = 1;
    Node *h1 = head;
    while (c1 < m && h1->next != NULL)
    {
        c1++;
        h1 = h1->next;
    }
    Node *h2 = h1->next;
    while (h2->next!= NULL && c2 < n)
    {
        c2++;
        h2 = h2->next;
    }
    h2 = h2->next;
    h1->next = h2;
    delete_m(h2, m, n);
    return head;
}
int main()
{
    Node *head = input();
    int m,n;
    cin>>m>>n;
    head = delete_m(head,m,n);
    print(head);
    return 0;
}