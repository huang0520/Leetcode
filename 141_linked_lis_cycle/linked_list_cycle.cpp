#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        if (head->val == INT32_MIN) return true;

        head->val = INT32_MIN;
        return hasCycle(head->next);
    }
};

auto main() -> int {
    ListNode *head = new ListNode(1);

    Solution sol;
    cout << sol.hasCycle(head) << "\n";

    return 0;
}