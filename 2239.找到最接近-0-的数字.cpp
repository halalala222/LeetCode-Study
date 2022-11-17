#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 *
 * [2239] 找到最接近 0 的数字
 */

// @lc code=start
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int result = 0;
        int minLength = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = min(nums[i],0) ? -nums[i] : nums[i];
            printf("%d\n",temp);
            printf("%d\n",nums[i]);
            printf("%d\n",result);
            printf("%d\n",minLength);
            if (minLength == temp) result = max(result,nums[i]); 
            else {
                minLength = min(temp,minLength);
                result = minLength == temp ? nums[i] : result;
            }
        }
        return result;
    }
};
// @lc code=end

