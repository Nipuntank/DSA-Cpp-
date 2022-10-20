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
binaryTreeNode<int> *solve(int *post, int *in, int inS, int inE, int poS, int poE)
{
    if (poS > poE)
    {
        return NULL;
    }
    int rootData = post[poE];
    int index = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            index = i;
            break;
        }
    }
    int linS = inS;
    int linE = index - 1;
    int lpoS = poS;
    int lpoE = linE - linS + lpoS;
    int rinS = index + 1;
    int rinE = inE;
    int rpoS = lpoE + 1;
    int rpoE = poE - 1;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    root->left = solve(post, in, linS, linE, lpoS, lpoE);
    root->right = solve(post, in, rinS, rinE, rpoS, rpoE);
    return root;
}
binaryTreeNode<int> *buildTree(int *post, int postlength, int *ino, int inlength)
{
    binaryTreeNode<int> *ans = solve(post, ino, 0, inlength-1, 0, postlength-1);
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
    int post[size], ino[size];
    cout << "Enter the preorder:";
    for (int i = 0; i < size; i++)
    {
        cin >> post[i];
    }
    cout << "Enter the inorder:";
    for (int i = 0; i < size; i++)
    {
        cin >> ino[i];
    }
    binaryTreeNode<int> *root = buildTree(post, size, ino, size);
    printTreeLevelWise(root);
    return 0;
}