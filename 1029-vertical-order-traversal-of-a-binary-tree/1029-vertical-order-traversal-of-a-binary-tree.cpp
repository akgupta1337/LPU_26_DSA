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

struct Node{
    int val, x, y;
    Node(int v, int X, int Y): val(v), x(X), y(Y) {}
};

bool comp(const Node& a, const Node& b){
    if (a.y != b.y) return a.y < b.y;
    if (a.x != b.x) return a.x < b.x;   
    return a.val < b.val;      
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*, Node>> q;
        q.push({root, Node(root->val, 0, 0)});
        vector<Node> res;
        while(!q.empty()){
            auto[treeNode, node] = q.front(); q.pop();
            res.push_back(node);
            if(treeNode->left) q.push({treeNode->left, Node(treeNode->left->val, node.x + 1, node.y - 1)});
            if(treeNode->right) q.push({treeNode->right, Node(treeNode->right->val, node.x + 1, node.y + 1)});
        }
        sort(res.begin(), res.end(), comp);
        vector<vector<int>> ans;
        ans.push_back({res[0].val});
        for(int i=1; i<res.size(); i++){
            if(res[i].y == res[i-1].y){
                ans.back().push_back(res[i].val);
            }
            else{
                ans.push_back({res[i].val});
            }
        }
        return ans;
    }
};