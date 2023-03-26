#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
/**
 * 如果都是 0 怎么处理呢？如果 0 作为一个分界线的话
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int size = nums.size();
        if (size < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums.at(0) >= 0 && nums.at(size - 1) > 0)
        {
            return result;
        }
        
    }
};
// @lc code=end
