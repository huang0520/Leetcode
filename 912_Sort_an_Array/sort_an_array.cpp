#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums.begin(), nums.end() - 1, nums.size());
        return nums;
    }

    auto split(vector<int>::iterator head, int size) -> vector<int>::iterator {
        if (size == 1) return head;
        return head + size;
    }

   private:
    auto mergeSort(vector<int>::iterator begin, vector<int>::iterator end,
                   int size) -> void {
        if (size == 1) {
            return;
        }
        // Split
        int left_size = size / 2;
        auto left_begin = begin;
        auto left_end = left_begin + left_size - 1;

        // Left half
        mergeSort(left_begin, left_end, left_size);

        // Right half
        int right_size = size - left_size;
        auto right_begin = begin + left_size;
        auto right_end = end;

        mergeSort(right_begin, right_end, right_size);

        // Merge
        vector<int> tmp;
        tmp.reserve(size);

        // Choose smaller one between first element of left part and right
        // part
        while (left_begin <= left_end && right_begin <= right_end) {
            if (*left_begin < *right_begin) {
                tmp.emplace_back(*left_begin);
                left_begin++;
            } else {
                tmp.emplace_back(*right_begin);
                right_begin++;
            }
        };

        // If left part all store in tmp first
        if (left_begin > left_end) {
            for (; right_begin <= right_end; right_begin++) {
                tmp.emplace_back(*right_begin);
            }
            // If right part all store in tmp first
        } else {
            for (; left_begin <= left_end; left_begin++) {
                tmp.emplace_back(*left_begin);
            }
        }

        for (auto var : tmp) {
            *begin = var;
            begin++;
        }

        // cout << "tmp:\n";
        // for (auto var : tmp) {
        //     cout << var << ' ';
        // }
        // cout << "\n";

        // do {
        //     cout << *begin << " ";
        //     begin++;
        // } while (begin <= end);
        // cout << "\n=====\n";
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