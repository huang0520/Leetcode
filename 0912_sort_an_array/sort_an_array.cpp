#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }

   private:
    auto mergeSort(vector<int>& arr, int left, int right) -> void {
        if (right == left) return;

        // Split
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge
        merge(arr, left, mid, right);
    }

    auto merge(vector<int>& arr, int left, int mid, int right) -> void {
        vector<int> tmp;

        // Compare first value of two vector
        int l = left, r = mid + 1, size = right - left + 1;
        tmp.reserve(size);

        while (l <= mid and r <= right)
            tmp.emplace_back(arr[l] > arr[r] ? arr[r++] : arr[l++]);

        while (l <= mid) tmp.emplace_back(arr[l++]);

        while (r <= right) tmp.emplace_back(arr[r++]);

        for (int i = 0; i < right - left + 1; i++) arr[left + i] = tmp[i];
    }
};

auto main() -> int {
    vector<int> nums = {7, 3, 3, 1};

    Solution sol;
    auto ans = sol.sortArray(nums);

    for (auto var : ans) {
        cout << var << " ";
    }
    cout << '\n';

    return 0;
}