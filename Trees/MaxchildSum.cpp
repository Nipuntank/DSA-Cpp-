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
void maxFind(TreeNode<int>*root,TreeNode<int>**maxNode,int *max)
{
    int sum = root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum +=root->children[i]->data;
        if(sum>*max)
        {
            *max = sum;
            *maxNode=root;
        }
    }
    for(int i=0;i<root->children.size();i++)
    {
        maxFind(root->children[i],maxNode,max);
    }
}
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    int max=0;
    TreeNode<int>*maxNode=root;
    maxFind(root,&maxNode,&max);
    return maxNode;
}
int main()
{
    TreeNode<int> *root = takeinput();
    printTree(root);
    TreeNode<int>*ans = maxSumNode(root);
    cout<<"Maximum Sum of child is of "<<ans->data;

    return 0;
}