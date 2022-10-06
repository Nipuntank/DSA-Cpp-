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
Node *midpoint(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge_node(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;
    if (head1 == NULL || head2 == NULL)
    {
        return head;
    }
    if (head1 != NULL && head2 == NULL)
    {
        return head2;
    }
    if (head1 == NULL && head2 != NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if (head1 != NULL)
    {
        tail->next = head1;
        tail = head1;
        head1 = head1->next;
    }
    else
    {
        tail->next = head2;
        tail = head2;
        head2 = head2->next;
    }
    return head;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = midpoint(head);
    Node *head1 = mid->next;
    mid->next = NULL;
    head = mergeSort(head);
    head1 = mergeSort(head1);
    return merge_node(head, head1);
}
int main()
{
    Node *head = input();
    head = mergeSort(head);
    print(head);
    return 0;
}