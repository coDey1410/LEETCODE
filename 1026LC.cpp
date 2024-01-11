/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxi=INT_MIN;
    void findMaxdiff(TreeNode* root,TreeNode* child)
{
    if(!root||!child)
    return;
    maxi=max(maxi,abs(root->val-child->val));
    findMaxdiff(root,child->left);
    findMaxdiff(root,child->right);
}

    void  findMax(TreeNode* root)
     {

         if(!root)
         return;

         findMaxdiff(root,root->left);
         findMaxdiff(root,root->right);

         findMax(root->left);
         findMax(root->right);

     }
    int maxAncestorDiff(TreeNode* root) {
        findMax(root);
        return maxi;
    }
};
/*__________________________________________________________________________________*/
/*OPTIMAL SOLUTION*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxi=INT_MIN,mini=INT_MAX;
    int findMax(TreeNode* root,int mini,int maxi)
{
    if(!root)
    return abs(maxi-mini);
    maxi=max(maxi,root->val);
    mini=min(mini,root->val);
    int l=findMax(root->left,mini,maxi);
    int r=findMax(root->right,mini,maxi);
    return max(l,r);
}

    
    int maxAncestorDiff(TreeNode* root) {
         return findMax(root,root->val,root->val);
       
    }
};