//Print Tree in level wise
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
