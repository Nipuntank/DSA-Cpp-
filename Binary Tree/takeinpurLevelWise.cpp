#include <iostream>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;
binaryTreeNode<int> *takeinputlevelWise()
{
    int rootData;
    cout << "Enter the data:";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front->data <<":";
        int leftchildData;
        cin >> leftchildData;
        if (leftchildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(leftchildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << front->data <<":";
        int rightchildData;
        cin >> rightchildData;
        if (rightchildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(rightchildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    binaryTreeNode<int> *root = takeinputlevelWise();
    printTree(root);
    return 0;
}