#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int size = nums.size(), low = -1, high = size;
        for (int i = 0; i < size; i++)
        {
            if (nums.at(i) == 0)
            {
                swap(nums.at(++low), nums.at(i));
            }
            if (nums.at(i) == 2 && i < high)
            {
                swap(nums.at(--high), nums.at(i));
                /**
                 * 这里没有想到，i 回退，因为如果把 0 换出来的话，就会导致换出来的 0 无法回到对应的位置上
                 * Testcase [1,2,0]
                 * Answer [1,0,2]
                 * Expecter Answer [0,1,2]
                 * 怎么就没有想到要重排一次 0 ，只要 i-- 即可了呢
                 */
                if (nums.at(i) != 1)
                    i--;
            }
        }
    }
};
// @lc code=end
