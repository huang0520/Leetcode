#include <iostream>
#include <queue>
#include <utility>

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
    TreeNode *invertTree(TreeNode *root) {
        queue<TreeNode *> stack;
        if (root) stack.emplace(root);

        while (!stack.empty()) {
            auto node = stack.front();
            stack.pop();

            swap(node->left, node->right);

            if (node->left) stack.emplace(node->left);
            if (node->right) stack.emplace(node->right);
        }
        return root;
    }
};

auto main() -> int {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    Solution sol;
    sol.invertTree(root);

    return 0;
}