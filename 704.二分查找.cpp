#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int min = 0;
        if (target < nums[0] || target > nums[nums.size() - 1])
        {
            return -1;
        }
        // printf("left : %d",left);
        // printf("right : %d",right);
        while (left <= right)        
        {
            min = (left + right) / 2;
            // printf("min : %d",min);
            // printf("left : %d",left);
            // printf("right : %d",right); 
            if (target == nums[min])
            {
                return min;
            }
            if (target < nums[min])
            {
                right = min - 1;
            }
            if (target > nums[min])
            {
                left = min + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
