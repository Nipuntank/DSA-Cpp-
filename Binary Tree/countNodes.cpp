#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class binaryTreeNode
{
    public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;
    binaryTreeNode(T data)
    {
        this->data = data;
        left=NULL;
        right=NULL;
    }
    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }

};
binaryTreeNode<int>*takeinputlevelWise()
{
    int rootData;
    cout<<"Enter the data:";
    cin>>rootData;
    binaryTreeNode<int>*root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        int leftchildData;
        cout<<"Enter the left child data of "<<front->data<<":";
        cin>>leftchildData;
        if(leftchildData!=-1)
        {
            binaryTreeNode<int>*child = new binaryTreeNode<int>(leftchildData);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightchildData;
        cout<<"Enter the right child data of "<<front->data<<":";
        cin>>rightchildData;
        if(rightchildData!=-1)
        {
            binaryTreeNode<int>*child = new binaryTreeNode<int>(rightchildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
void printTreelevelWise(binaryTreeNode<int>*root)
{
    cout<<endl;
    if(root==NULL)
    {
        return ;
    }
    queue<binaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left!=NULL)
        {
            cout<<"L:"<<front->left->data;
            pendingNodes.push(front->left);
        }
        cout<<",";
        if(front->left!=NULL)
        {
            cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
int countNode(binaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+countNode(root->left)+countNode(root->right);
}
int main()
{
    binaryTreeNode<int>*root = takeinputlevelWise();
    printTreelevelWise(root);
    cout<<"Number of nodes in the binary tree :"<<countNode(root)<<endl;
    return 0;
}