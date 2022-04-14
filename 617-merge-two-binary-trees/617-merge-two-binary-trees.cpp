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
    
TreeNode* mergeTreesUtil(TreeNode* &temp1, TreeNode* &temp2){
    if(temp1 && temp2) temp1->val = temp1->val + temp2->val;
    if(temp1==NULL && temp2!=NULL) return temp2;
    if(temp2){
         temp1->left = mergeTreesUtil(temp1->left,temp2->left);
        temp1->right = mergeTreesUtil(temp1->right, temp2->right);
    }
    
    return temp1;
}
    
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* temp1 = root1, *temp2 = root2;
        return mergeTreesUtil(temp1, temp2);
        
    }
};