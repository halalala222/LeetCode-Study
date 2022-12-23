#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int result = 0, size = operations.size();
        for (int i = 0; i < size; i++)
        {
            string str = operations.at(i);
            if ((str.at(0) == '+') || (str.at(2) == '+'))
            {
                result++;
            }
            else
            {
                result--;
            }
        }
        return result;
    }
};
// @lc code=end
