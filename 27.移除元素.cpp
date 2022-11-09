#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
/** woc,最吊的一次
 * 113/113 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 82.46 % of cpp submissions (8.4 MB)
*/
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int beginIndex = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                if (count == 0)
                {
                    beginIndex = i;
                }
                
                count++;
            }
        }
        for (int i = beginIndex + count; i < nums.size(); i++)
        {
            nums[i - count] = nums[i]; 
        }
        return nums.size() - count;
    }
};
// @lc code=end

