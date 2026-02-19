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
    void inorder(TreeNode* root, vector<int>& list){
        if(!root) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        inorder(root1, l1);
        inorder(root2, l2);
        int n1 = l1.size(), n2 = l2.size();
        vector<int> ans(n1 + n2);
        int i=0, j=0, k=0;
        while(i < n1 && j < n2){
            if(l1[i] < l2[j]){
                ans[k] = l1[i++];
            }
            else ans[k] = l2[j++];
            k++;
        }
        while(i < n1) ans[k++] = l1[i++];
        while(j < n2) ans[k++] = l2[j++];
        return ans;
    }
};