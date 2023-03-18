#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp = 0, rp = nums.size() - 1;

        for (int mp = (lp + rp) >> 1; lp <= rp; mp = (lp + rp) >> 1){
            if (nums[mp] > target) rp = mp - 1;
            else if (nums[mp] < target) lp = mp + 1;
            else return mp;
        }
        return -1;
    }
};

int main(void){
    vector <int> nums = {};
    int target = 5;

    Solution sol;
    int ans = sol.search(nums, target);
    cout << ans << "\n";
}