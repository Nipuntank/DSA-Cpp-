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
Node *merging(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 != NULL && head2 == NULL)
    {
        return head1;
    }
    if (head1 == NULL && head2 != NULL)
    {
        return head2;
    }
    Node *temp = head1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}
int main()
{
    Node *head1=input();
    Node *head2=input();
    Node *head = merging(head1,head2);
    print(head);

    return 0;
}