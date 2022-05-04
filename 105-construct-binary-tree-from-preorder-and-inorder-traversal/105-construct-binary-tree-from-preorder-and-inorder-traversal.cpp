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
    
int findIndexInInorder(vector<int> &inorder, int start, int end, int value){
    for(int i=start;i<=end;i++){
        if(inorder[i]==value) return i;
    }
    
    return -1;
}
    
TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end){
    if(start>end) return NULL;
    TreeNode* node = new TreeNode(preorder[index++]);
    if(start==end) return node;
    int pos = findIndexInInorder(inorder, start, end, node->val);
    node->left = buildTreeUtil(preorder, inorder, index, start, pos-1);
    node->right = buildTreeUtil(preorder, inorder, index, pos+1, end);
    return node;
}
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return buildTreeUtil(preorder,inorder,index,0,n-1);
    }
};