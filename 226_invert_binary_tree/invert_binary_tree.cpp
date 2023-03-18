#include <iostream>
#include <queue>

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
        if (root == nullptr) return root;

        invertTree(root->left);
        invertTree(root->right);

        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

auto main() -> int {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    return 0;
}