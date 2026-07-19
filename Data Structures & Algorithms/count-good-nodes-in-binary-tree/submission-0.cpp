class Solution {
public:
    int helper(TreeNode* root, int mx) {
        if (root == nullptr)
            return 0;

        int ans = 0;

        if (root->val >= mx) {
            ans = 1;
            mx = root->val;
        }

        ans += helper(root->left, mx);
        ans += helper(root->right, mx);

        return ans;
    }

    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};