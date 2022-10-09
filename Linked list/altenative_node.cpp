#include <iostream>
using namespace std;
#include "linkedlist.cpp"
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