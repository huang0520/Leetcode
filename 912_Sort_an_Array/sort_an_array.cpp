#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int> nums) {
        if (nums.size() == 1) {
            return nums;
        }

        // Split
        auto mid = nums.begin() + nums.size() / 2;

        auto left = sortArray(vector<int>(nums.begin(), mid));
        auto right = sortArray(vector<int>(mid, nums.end()));

        // Merge
        return merge(left, right);
    }

   private:
    auto merge(vector<int> left, vector<int> right) -> vector<int> {
        vector<int> tmp;
        tmp.reserve(left.size() + right.size());

        // Compare first value of two vector
        auto l_itr = left.begin(), r_itr = right.begin();
        while (l_itr != left.end() && r_itr != right.end()) {
            if (*l_itr > *r_itr) {
                tmp.emplace_back(*r_itr);
                r_itr++;
            } else {
                tmp.emplace_back(*l_itr);
                l_itr++;
            }
        }

        for (; l_itr != left.end(); l_itr++) {
            tmp.emplace_back(*l_itr);
        }

        for (; r_itr != right.end(); r_itr++) {
            tmp.emplace_back(*r_itr);
        }

        return tmp;
    }
};

auto main() -> int {
    vector<int> nums = {5, 2, 3, 1};

    Solution sol;
    auto ans = sol.sortArray(nums);

    for (auto var : ans) {
        cout << var << " ";
    }
    cout << '\n';

    return 0;
}