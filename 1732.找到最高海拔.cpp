#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

/**
 * 80/80 cases passed (8 ms)
 * Your runtime beats 3.99 % of cpp submissions
 * Your memory usage beats 9.31 % of cpp submissions (7.9 MB)
*/
/**
 * woc, 这么低效，看看题解
 * 看了下题解，发现确实可以不用每一个都算，维持一个当前海拔和一个最大海拔俩个参数
*/
// @lc code=start
class MySolution {
public:
    int largestAltitude(vector<int>& gain) {
        int size = gain.size();
        vector<int> altitude(size+1,0);
        for (int i = 0; i < size; i++)
        {
            altitude.at(i+1) = altitude.at(i) + gain.at(i);
        }
        sort(altitude.begin(),altitude.end());
        return altitude.at(size);
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0;
        int cur_alt = 0;
        int size = gain.size();
        for (int i = 0; i < size; i++)
        {
            cur_alt = cur_alt + gain.at(i);
            max_alt = max(cur_alt,max_alt);
        }
        return max_alt;
    }
};
// @lc code=end

