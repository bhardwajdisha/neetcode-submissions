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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val !=subRoot->val) return false;
        return sameTree(root->left,subRoot->left) && sameTree(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr && subRoot == nullptr) return true;
        if(root==nullptr) return false;
        bool isFound = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            // TreeNode* dummy = nullptr;
            int n = que.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->val == subRoot->val){
                    isFound = sameTree(temp, subRoot);
                    if(isFound) return true;
                }
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            // if(dummy){
            //     isFound = sameTree(dummy, subRoot);
            //     if(isFound) return true;
            // }
        }
        return isFound;
    }
};
