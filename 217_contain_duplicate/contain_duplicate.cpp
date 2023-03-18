#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector <int> & nums) {
        for (auto itr = nums.begin(); itr != nums.end(); itr++){
            if (unique[*itr] == 1) return true;
            unique[*itr] = 1;
        }
        return false;
    }
private:
    unordered_map <int, int> unique;
};

int main(void){
    vector <int> nums{3, 2, 5};

    Solution sol;
    cout << sol.containsDuplicate(nums) << "\n";
}