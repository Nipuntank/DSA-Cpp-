/*
                  Remove duplicates from a sorted linked list
Write a function that takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. 
The list should only be traversed once.For example if the linked list is 
11->11->11->21->43->43->60 then removeDuplicates() 
should convert the list to 11->21->43->60.
*/
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
Node *duplicate_sorted(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *a = temp->next->next;
            delete temp->next;
            temp->next = a;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    Node *head = input();
    head = duplicate_sorted(head);
    print(head);

    return 0;
}