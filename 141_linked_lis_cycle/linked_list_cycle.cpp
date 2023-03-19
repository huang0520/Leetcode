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
        if (!head or !head->next) return false;

        for (ListNode *fast = head->next, *slow = head; fast != slow;
             fast = fast->next->next, slow = slow->next)
            if (!fast or !fast->next) return false;

        return true;
    }
};

auto main() -> int {
    ListNode *head = new ListNode(1);

    Solution sol;
    cout << sol.hasCycle(head) << "\n";

    return 0;
}