#include <iostream>
#include "Treeuse.h"
#include <queue>
using namespace std;
TreeNode<int> *takeinput()
{
    int rootData;
    cout << "Enter the data:";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numchild;
        cout << "Enter the num of child of:" << front->data << ":" << endl;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << ":";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printPostOrder(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }   
    for(int i=0;i<root->children.size();i++)
    {
        printPostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
int main()
{
    TreeNode<int> *root = takeinput();
    printPostOrder(root);
    delete root;
    return 0;
}