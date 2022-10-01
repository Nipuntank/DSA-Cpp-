#include<iostream>
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
Node * reverse_rec(Node *head)
{
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    Node *ans = reverse_rec(head->next);
    Node *temp=head->next;
    temp->next=head;
    head->next=NULL;
    return ans;
}
int main()
{
    Node *head =input();
    print(head);
    head = reverse_rec(head);
    print(head);
    return 0;
}