#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int result = 0, maxNum = nums.at(0), size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums.at(i) == 0)
                continue;
            if (nums.at(size - 1) > 0)
            {
                int sub = nums.at(i);
                for (int j = i; j < size; j++)
                {
                    nums.at(j) -= sub;
                }
                printf("i : %d,max : %d\n",i,nums.at(size - 1));
                result++;
            }
            else
                break;
        }
        return result;
    }
};

/**
 * 这个好屌，因为每次都是将最小的非零元素减少至 0 ，所以如果要将整个数组中的数都减少为 0 ，就需要将所有的不同的
 * 非零按照从小到大的顺序减少至 0 ，此时减少次数就等于不同非零元素个数
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
            if (num > 0) {
                hashSet.emplace(num);
            }
        }
        return hashSet.size();
    }
};

// @lc code=end
