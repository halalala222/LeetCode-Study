#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */
/**
 * 有点牛，位运算用得很熟练，我没有想到还能这样子，还能避免到当个数组中的重复
*/
// @lc code=start
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto& i : nums1) {
            //001
            mp[i] = 1;
        }
        for (auto& i : nums2) {
            //* 1 * 逻辑与，如果又 1 则为1
            mp[i] |= 2;
        }
        for (auto& i : nums3) {
            //* 1 * 逻辑与，如果又 1 则为1
            mp[i] |= 4;
        }
        vector<int> res;
        for (auto& [k, v] : mp) {
            //如果 v = 1 为 false，如果 v > 1 为 true
            if (v & (v - 1)) {
                res.push_back(k);
            }
        }
        return res;
    }
};
// @lc code=end
