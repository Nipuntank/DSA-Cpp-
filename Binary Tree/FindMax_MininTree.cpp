#include <iostream>
using namespace std;
#include <climits>
#include <queue>
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> *takeinputlevelWise()
{
    int rootData;
    cout << "Enter the data:";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front->data << ":";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter the right child of " << front->data << ":";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printlevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
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
void findMax(BinaryTreeNode<int> *root, int *max)
{
    if (root == NULL)
        return;
    if ((*max) < root->data)
    {
        *max = root->data;
    }
    findMax(root->left, max);
    findMax(root->right, max);
}
void findMin(BinaryTreeNode<int> *root, int *min)
{
    if (root == NULL)
        return;
    if ((*min) > root->data)
    {
        *min = root->data;
    }
    findMin(root->left, min);
    findMin(root->right, min);
}
pair<int, int> getMinMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> ans;
        ans.first = INT_MAX;
        ans.second = INT_MIN;
        return ans;
    }
    int min = INT_MAX, max = INT_MIN;
    findMin(root, &min);
    findMax(root, &max);
    pair<int, int> ans;
    ans.first = min;
    ans.second = max;
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeinputlevelWise();
    cout<<endl;
    printlevelWise(root);
    cout<<endl;
    pair<int, int> ans=getMinMax(root);
    cout << "Mininmum:" << ans.first << endl;
    cout << "Maximum:" << ans.second << endl;

    return 0;
}