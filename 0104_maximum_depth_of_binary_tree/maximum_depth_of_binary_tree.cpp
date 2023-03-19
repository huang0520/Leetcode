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
    int maxDepth(TreeNode *root, int depth = 1) {
        if (!root) return --depth;

        int left = maxDepth(root->left, depth + 1);
        int right = maxDepth(root->right, depth + 1);

        return max(left, right);
    }
};

auto main() -> int {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    auto ans = sol.maxDepth(root);

    cout << ans << "\n";

    return 0;
}