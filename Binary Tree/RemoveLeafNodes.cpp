#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }
};
TreeNode<int> *takeinputLevelWise()
{
    int rootData;
    cout << "Enter the data:";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter the left child of " << front->data << ":";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            TreeNode<int> *child = new TreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChildData;
        cout << "Enter the right child of " << front->data << ":";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            TreeNode<int> *child = new TreeNode<int>(rightChildData);
            front->right = child;
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
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                break;
            }
            cout << endl;
            pendingNodes.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
    }
}
TreeNode<int> *RemoveLeafNodes(TreeNode<int> *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return NULL;
    }
    if(root->left!=NULL)
    {
        root->left = RemoveLeafNodes(root->left);
    }
    if(root->right!=NULL)
    {
        root->right = RemoveLeafNodes(root->right);
    }
    return root;
}
int main()
{
    TreeNode<int> *root = takeinputLevelWise();
    cout<<endl;
    cout<<"Before Removal of leaf nodes:"<<endl;
    printTree(root);
    cout<<endl;
    TreeNode<int>*ans = RemoveLeafNodes(root);
    cout<<endl;
    cout<<"After Removal of leaf nodes:"<<endl;
    printTree(ans);
    cout<<endl;

    return 0;
}