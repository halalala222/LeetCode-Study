#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1])
        {
            return nums.size();
        }
        int left = 0,right = nums.size(),min = 0;
        while (left <= right)
        {
            min = left + (right - left) / 2;
            printf("%d\n",min);
            if (nums[min] == target)
            {
                return min;
            }
            printf("%d\n",left);
            if (nums[min] > target)
            {
                right = min - 1;
               
            }
            
            if (nums[min] < target)
            {
                left = min + 1;
            }
            
        }
        return left;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> ints;
    ints.push_back(1);
    Solution *s = new Solution;
    printf("%d",s->searchInsert(ints,1));
    return 0;
}

