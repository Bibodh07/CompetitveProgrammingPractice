#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  
    if(root == NULL)
    {
        return NULL;
    }

    if(root == p || root == q)
    {
        return root;
    }

  

    TreeNode* val_Inleft = lowestCommonAncestor(root->left, p, q);
    TreeNode* val_Inright = lowestCommonAncestor(root->right, p, q);

    if(val_Inleft && val_Inright)
    {
        return root;
    }
    else if (val_Inleft && !val_Inright)
    {
        return val_Inleft;
    }
    else if (val_Inright && !val_Inleft)
    {
        return val_Inright;
    }
    else{
        return NULL;
    }
    
    
}