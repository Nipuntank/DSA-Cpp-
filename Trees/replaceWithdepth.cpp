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
void printLevelATNewLine(TreeNode<int> *root)
{
    cout<<endl;
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << front->data << " ";
        for (int i = 0; i < front->children.size(); i++)
        {
            q.push(front->children[i]);
        }
    }
}
void depthValue(TreeNode<int>*root,int count)
{
    root->data=count;
    for(int i=0;i<root->children.size();i++)
    {
        depthValue(root->children[i],count+1);
    }
}
void replaceWithDepth(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    int count=0;
    depthValue(root,count);
}
int main()
{
    TreeNode<int> *root = takeinput();
    printLevelATNewLine(root);
    replaceWithDepth(root);
    printLevelATNewLine(root);


    return 0;
}