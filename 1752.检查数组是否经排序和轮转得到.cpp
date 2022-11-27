#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
/**
 * 无论怎么轮转始终都是一俩快非递减的数组拼凑一起
*/
/**
 * 这一版有问题，只统计了突然降低瞬间的次数
 * 需要判断是否是有顺序的。即降低前的一个值，为最大值。
 * 而且也无法对于0次进行判断先
*/
class MySolution {
public:
    bool check(vector<int>& nums) {
        int num = 0,maxInt = 0,size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (maxInt > nums.at(i))
            {
                num++;
            }
            maxInt = nums.at(i);
        }
        return num == 1;
    }
};

/**
 * 看了下一个题解做法挺牛的，
 * 如果是翻转确实是只允许一个数，他前一个数比他大
 * 将数组看组一个环形数组，通过使用 % 来进行环形
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};
// @lc code=end

