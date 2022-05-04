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
    
int findIndexInInorder(vector<int>& inorder, int start, int end, int value){
    for(int i=start;i<=end;i++){
        if(inorder[i]==value) return i;
    }
    return -1;
}
    
TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int &index, int start, int end){
    if(start>end) return NULL;
    TreeNode* node = new TreeNode(postorder[index--]);
    if(start==end) return node;
    int pos = findIndexInInorder(inorder, start, end, node->val);
    node->right = buildTreeUtil(inorder,postorder,index,pos+1,end);
    node->left = buildTreeUtil(inorder,postorder,index,start,pos-1);
    
    return node;
}
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n-1;
        return buildTreeUtil(inorder,postorder,index,0,n-1);
    }
};