
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()-1; i++)
        {
            auto t = target - nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] == t)
                {
                    return{i,j};
                }
            }
            
        }
        return {};
    }
};
// @lc code=end
