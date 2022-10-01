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
Node *even_odd(Node *head)
{
    Node *even = new Node(0);
    Node *etail = even;

    Node *odd = new Node(0);
    Node *otail = odd;

    while (head!= NULL)
    {
        if (head->data % 2 == 0)
        {
            etail->next = head;
            etail = head;
            head = head->next;
            etail->next = NULL;
        }
        else
        {
            otail->next = head;
            otail = head;
            head = head->next;
            otail->next = NULL;
        }
    }
    etail->next=odd->next;
    return even->next;
}
int main()
{
    Node *head = input();
    head = even_odd(head);
    print(head);

    return 0;
}