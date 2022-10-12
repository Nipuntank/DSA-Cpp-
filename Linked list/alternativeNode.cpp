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
Node *alte(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head->next->next;
    delete head->next;
    head->next = temp;
    alte(temp);
    return head;
}
int main()
{
    Node *head = input();
    head = alte(head);
    print(head);
    return 0;
}