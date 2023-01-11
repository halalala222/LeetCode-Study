#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

// @lc code=start
class Solution
{
public:
    bool digitCount(string num)
    {
        vector<int> count(10, 0);
        for (char c : num)
        {
            printf("num : %d\n", c - '0');
            count[c - '0']++;
        }
        printf("size : %d\n", num.size());
        for (int i = 0; i < num.size(); i++)
        {
            printf("num.at(i) : %d,count[i] : %d\n", num.at(i), count[i]);
            if (num.at(i) - '0' != count[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
