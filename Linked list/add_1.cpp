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
    cout << endl;
}
Node *reverse_rec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *ans = reverse_rec(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return ans;
}
Node *add_one(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *h1 = reverse_rec(head);
    int carry = 1, sum;
    Node *temp = h1;
    while (temp != NULL)
    {
        sum = carry + temp->data;
        if (sum <= 9)
        {
            sum = sum % 10;
            temp->data = sum;
            temp = temp->next;
            carry = 0;
            break;
        }
        else
        {
            if (sum == 10)
                carry = 1;
            else
                carry = 0;
            sum = sum % 10;
            temp->data = sum;
            temp = temp->next;
        }
    }
    if (carry > 0)
    {
        Node *newnode = new Node(carry);
        head->next = newnode;
        newnode->next = NULL;
    }
    head = reverse_rec(h1);
    return head;
}

int main()
{
    cout<<"Enter the single digit numbers:";
    Node *head = input();
    print(head);
    head = add_one(head);
    print(head);
    return 0;
}