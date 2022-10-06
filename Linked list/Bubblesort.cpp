#include<iostream>
using namespace std;
#include "linkedlist.cpp"
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