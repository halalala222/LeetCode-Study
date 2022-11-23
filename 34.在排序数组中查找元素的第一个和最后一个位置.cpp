#include <vector>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftResult;
        int size = nums.size();
        if (!nums.size()) return vector<int>{-1,-1};
        int l = 0,r = size - 1;
        while (l <= r)
        {
            int mid = ( l + r ) / 2;
            printf("l : %d,r : %d,mid : %d\n",l,r,mid);
            printf("midNum : %d\n",nums.at(mid));
            if (nums.at(mid) >= target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (l >= size || nums.at(l) != target) return vector<int>{-1,-1};
        leftResult = l;
        r = size - 1;
        l = 0;
        while (l <= r)
        {
            int mid = (l + r + 1) / 2;
            printf("l : %d,r : %d,mid : %d\n",l,r,mid);
            if (nums.at(mid) <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return vector<int>{leftResult,r};
    }
};
// @lc code=end

