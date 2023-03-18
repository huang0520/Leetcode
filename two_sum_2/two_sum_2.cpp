#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lp = 0;
        int rp = numbers.size() - 1;
        int curr;

        while (lp < rp){
            curr = numbers[lp] + numbers[rp];

            if (curr == target) return {lp + 1, rp + 1};
            else if (curr < target) lp++;
            else rp--;
        }
        return {-1, -1};
    }
};

int main(void){
    vector <int> nums = {-1,0};
    int target = -1;

    Solution sol;

    auto ans = sol.twoSum(nums, target);
    
    cout << "[" << ans[0] << "," << ans[1] << "]\n";
}