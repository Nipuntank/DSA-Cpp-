#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    vector<TreeNode<int> *> children;
    int data;
    TreeNode(T data)
    {
        this->data = data;
    }
};
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
        cout << "Enter num of child " << front->data << ":";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
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
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == 0)
                cout << front->children[i]->data;
            else
                cout << "," << front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}
void LargestNode(TreeNode<int>*root,TreeNode<int>**max1,TreeNode<int>**max2)
{
    if(*max1==NULL)
    {
        *max1=root;
    }
    else if(*max2==NULL && root->data < (*max1)->data)
    {
        *max2 = root;
    }
    else if(root->data > (*max1)->data)
    {
        *max2 = *max1;
        *max1 = root;
    }
    else if(root->data < (*max1)->data && (*max2)->data < root->data)
    {
        *max2 = root;
    }
    for(int i=0;i<root->children.size();i++)
    {
        LargestNode(root->children[i],max1,max2);
    }

}
TreeNode<int>*secondLargestNode(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return root;
    }
    TreeNode<int>*max1=NULL;
    TreeNode<int>*max2=NULL;
    LargestNode(root,&max1,&max2);
    return max2;

}
int main()
{
    TreeNode<int> *root = takeinput();
    printTree(root);
    TreeNode<int>*ans = secondLargestNode(root);
    cout<<"Second largest number in the Tree: "<<ans->data<<endl;

    return 0;
}