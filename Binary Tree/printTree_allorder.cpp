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
TreeNode<int> *takeinput()
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
        cout << "Enter the left child of " << front->data << ":";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            TreeNode<int> *child = new TreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << front->data << ":";
        int rightChildData;
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

void printTree_preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree_preorder(root->left);
    printTree_preorder(root->right);
}
void printTree_inorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree_inorder(root->left);
    cout << root->data << " ";
    printTree_inorder(root->right);
}
void printTree_postorder(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return ;
    }
    printTree_postorder(root->left);
    printTree_postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
    TreeNode<int> *root = takeinput();
    cout<<endl;
    cout<<"Inorder:";
    printTree_inorder(root);
    cout<<endl;
    cout<<"Preorder:";
    printTree_preorder(root);
    cout<<endl;
    cout<<"Postorder:";
    printTree_postorder(root);
    cout<<endl;
    return 0;
}