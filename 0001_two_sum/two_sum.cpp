#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector <int> twoSum(vector <int> & nums, int target) {
        unordered_map <int, int> table;

        for (auto itr = nums.begin(); itr != nums.end(); itr++){
            auto got = table.find(target - *itr);
            int index = itr - nums.begin();

            if (got == table.end()) table[*itr] = index;
            else return {got->second, index};
        }
        return {0, 0};
    }
};

int main(void){

    vector <int> nums = {2, 5, 5, 11};
    int target = 10;

    Solution sol;

    auto ans = sol.twoSum(nums, target);

    cout << "[" << ans[0] << "," << ans[1] << "]" << "\n";
}