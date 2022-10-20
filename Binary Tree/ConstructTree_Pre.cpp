#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;
    binaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};
int find(int *in, int inS, int inE, int ele)
{
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
binaryTreeNode<int> *solve(int *pre, int *ino, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int pos = find(ino, inS, inE, rootData);
    int linS = inS;
    int linE = pos - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = pos + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    root->left = solve(pre, ino, linS, linE, lpreS, lpreE);
    root->right = solve(pre, ino, rinS, rinE, rpreS, rpreE);
    return root;
}
binaryTreeNode<int> *buildTree(int *pre, int preLength, int *ino, int inLength)
{
    binaryTreeNode<int> *ans = solve(pre, ino, 0, inLength - 1, 0, preLength - 1);
    return ans;
}
void printTreeLevelWise(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        binaryTreeNode<int> *front = pendingNodes.front();
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
int main()
{
    int size;
    cout << "Enter the size:";
    cin >> size;
    int pre[size], ino[size];
    cout << "Enter the preorder:";
    for (int i = 0; i < size; i++)
    {
        cin >> pre[i];
    }
    cout << "Enter the inorder:";
    for (int i = 0; i < size; i++)
    {
        cin >> ino[i];
    }
    binaryTreeNode<int> *root =buildTree(pre, size, ino, size);
    printTreeLevelWise(root);
    return 0;
}