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
bool structurally_identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool ans = structurally_identical(root1->children[i], root2->children[i]);
        if (ans)
            return true;
        else
            return false;
    }
    if (root1->data == root2->data)
        return true;
    else
        return false;
}
int main()
{
    cout << "Enter the first tree" << endl;
    TreeNode<int> *root1 = takeinput();
    cout <<endl<< "Enter the second tree" << endl;
    TreeNode<int> *root2 = takeinput();
    cout<< "First Tree:" << endl;
    printTree(root1);
    cout << "Second Tree:" << endl;
    printTree(root2);
    if (structurally_identical(root1, root2))

        cout << "Identical";

    else
        cout << "Not Identical";

    return 0;
}