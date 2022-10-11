void Preorder(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        Preorder(root->children[i]);
    }
}
