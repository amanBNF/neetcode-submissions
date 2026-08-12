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
    TreeNode* solve(int in_s, int in_e, int pre_s, int pre_e, vector<int> &pre, vector<int> &in, unordered_map<int,int> &mp){
        if(in_s > in_e) return nullptr;
        if(pre_s > pre_e) return nullptr;
        
        int root_node = pre[pre_s];

        TreeNode* dummy = new TreeNode(root_node);

        int mid = mp[root_node];

        int l_size = (mid-1) - in_s + 1; 
        int r_size = in_e - (mid + 1) + 1; 

        int l1 = pre_s + 1;
        int h1 = l1 + l_size - 1;

        int l2 = h1 + 1;
        int h2 = l2 + r_size - 1;

        dummy->left = solve(in_s, mid-1, l1, h1, pre, in, mp);
        dummy->right = solve(mid+1, in_e, l2, h2, pre, in, mp);

        return dummy;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        // TreeNode* root = new TreeNode(pre[0]);
        int n = pre.size();

        unordered_map<int,int> mp;

        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
        }

        return solve(0, n-1, 0, n-1, pre, in, mp);
    }
};
