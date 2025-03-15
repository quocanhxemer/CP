// https://leetcode.com/problems/add-one-row-to-tree/description/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return add(root, val, depth, true);
    }

   private:
    TreeNode* add(TreeNode* root, int val, int depth, bool isLeft) {
        if (depth == 1) {
            if (isLeft) {
                return new TreeNode(val, root, nullptr);
            } else {
                return new TreeNode(val, nullptr, root);
            }
        }

        if (!root) {
            return nullptr;
        }

        return new TreeNode(root->val, add(root->left, val, depth - 1, true),
                            add(root->right, val, depth - 1, false));
    }
};
