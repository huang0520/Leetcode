#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    auto findKthLargest(vector<int>& nums, int k) -> int {
        priority_queue<int, vector<int>, greater<int>> storage;

        for (auto num : nums) {
            storage.emplace(num);
            if (storage.size() > k) storage.pop();
        }

        return storage.top();
    }
};

auto main() -> int {
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k{4};

    Solution sol;
    cout << sol.findKthLargest(nums, k) << "\n";

    return 0;
}
