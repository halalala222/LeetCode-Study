#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int index = i + k > (n - 1) ? (i + k) % n : i + k;
            nums[index] = result[i];  
        }
    }
};

// @lc code=end

/*
 * 高雅的数组翻转,牛逼的算法
*/
class StandardSolution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};