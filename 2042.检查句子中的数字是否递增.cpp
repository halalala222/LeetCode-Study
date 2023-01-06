#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2042 lang=cpp
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int last = 0, i = 0;
        while (i < s.length())
        {
            int cur = 0;
            if (isdigit(s.at(i)))
            {
                while (i < s.length() && isdigit(s.at(i)))
                {
                    cur += cur * 10 + s.at(i) - '0';
                    i++;
                }
                if (last >= cur)
                {
                    return false;
                }
                last = cur;
            }
            else
            {
                i++;
            }
        }
        return true;
    }
};
// @lc code=end
