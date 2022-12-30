#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2027 lang=cpp
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minimumMoves(string s)
    {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) == 'X')
            {
                for (int j = 0; j < 3 && (i + j) < s.length(); j++)
                {
                    s.at(i + j) = 'O';
                }
                result++;
            }
        }
        return result;
    }
};

class Solution {
public:
    int minimumMoves(string s) {
        int covered = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X' && i > covered) {
                res += 1;
                covered = i + 2;
            }
        }
        return res;
    }
};

// @lc code=end
