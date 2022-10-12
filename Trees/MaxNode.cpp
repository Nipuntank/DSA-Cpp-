#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
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
        int numChild;
        cout << "Enter the num of child " << front->data << ":";
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << ":";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printlevelwise(TreeNode<int> *root)
{
    cout << endl;
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
TreeNode<int> *MaxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    int max = root->data;
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *max1 = MaxDataNode(root->children[i]);
        if (max1->data > max)
        {
            max = max1->data;
            maxNode = max1;
        }
    }
    return maxNode;
}
int main()
{
    TreeNode<int> *root = takeinput();
    printlevelwise(root);
    TreeNode<int> *ans = MaxDataNode(root);
    cout << "The max Node in tree is:" << ans->data;

    return 0;
}