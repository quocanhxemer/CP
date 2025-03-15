// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        long long sum[100000];
        memset(sum, 0, sizeof(sum));

        queue<TreeNode *> c;
        c.push(root);

        int current_level = 0;
        while (!c.empty()) {
            queue<TreeNode *> next;

            while (!c.empty()) {
                TreeNode *current = c.front();
                c.pop();
                sum[current_level] += current->val;

                if (current->left) {
                    next.push(current->left);
                }
                if (current->right) {
                    next.push(current->right);
                }
            }

            c = next;
            current_level++;
        }

        if (k > current_level) {
            return -1;
        }

        sort(sum, sum + current_level);
        reverse(sum, sum + current_level);

        return sum[k - 1];
    }
};
