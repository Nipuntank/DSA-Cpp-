/*
Given a singly linked list, delete the middle of the linked list. For example, 
if the given linked list is 1->2->3->4->5 then the linked list should be modified to 1->2->4->5
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL, then it should remain NULL.
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
Node *middle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next->next;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            slow = slow->next;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    Node *head = input();
    Node *mid = middle(head);
    cout << mid->data << endl;
    return 0;
}