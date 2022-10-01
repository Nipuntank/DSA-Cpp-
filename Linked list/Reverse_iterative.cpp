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
Node *reverse(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        Node *up = current->next;
        current->next = prev;
        prev = current;
        current = up;
    }
    return prev;
}
int main()
{
    Node *head = input();
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}