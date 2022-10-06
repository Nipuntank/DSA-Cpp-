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
    cin>>data;
    Node *head =NULL;
    Node *tail = NULL;
    while(data!=-1)
    {
        Node *newnode = new Node(data);
        if(head==NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node *bubble_sort(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *current = head;
    Node *tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    while(current!=tail)
    {
        if(current->data > current->next->data)
        {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        if(current->next==tail)
        {
            tail =current;
            current = head;
        }
        else{
            current = current->next;
        }
    }
    return head;
}
int main()
{
    Node *head = input();
    head = bubble_sort(head);
    print(head);
    
    return 0;
}