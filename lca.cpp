/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode * root, int k)
{
    if(root == NULL)
        return false;
    if(root->val == k || find(root->left,k) || find(root->right,k))
        return true;
    return false;
}
TreeNode * findLCA(TreeNode * root,int n1,int n2,bool &v1,bool &v2)
{
    if(root == NULL)
        return NULL;
    if(root->val == n1)
    {
        v1 = true;
        return root;
    }
    if(root->val == n2)
    {
        v2 = true;
        return root;
    }
    TreeNode * left_lca = findLCA(root->left,n1,n2,v1,v2);
    TreeNode * right_lca = findLCA(root->right,n1,n2,v1,v2);
    
    if(left_lca && right_lca)
        return root;
    
    return (left_lca != NULL) ? left_lca : right_lca;
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool v1 = false;
    bool v2 = false;
    TreeNode * lca = findLCA(A,B,C,v1,v2);
    
    if(v1 && v2 || v1 && find(lca,C) || v2 && find(lca,B))
        return lca->val;
    return NULL;
}
