#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 * 84/84 cases passed (396 ms)
 * Your runtime beats 5.95 % of cpp submissions
 * Your memory usage beats 5.41 % of cpp submissions (87.5 MB)
 */

// @lc code=start
class Solution
{
public:
    int countHomogenous(string s)
    {
        int maxLength = 1e5;
        int dividend = 1e9 + 7;
        int size = s.length();
        long long lastSum = 0;
        long long result = 0;
        vector<long long> numsResult(maxLength + 1, 0);
        vector<int> lengthInt;
        for (int i = 1; i <= maxLength; i++)
        {
            lastSum += i;
            numsResult.at(i) = lastSum;
        }
        for (int i = 0; i < size; i++)
        {
            string temp = "";
            char c = s.at(i);
            printf("temp : %c\n", c);
            temp.push_back(s.at(i));
            for (int j = i + 1; j < size; j++)
            {
                if (s.at(j) == c)
                {
                    printf("s.at(j) : %c\n", s.at(j));
                    temp.push_back(c);
                    if (j == size - 1)
                    {
                        i = size;
                    }
                }
                else
                {
                    i = j - 1;
                    break;
                }
            }
            lengthInt.push_back(temp.size());
        }
        int lengthSize = lengthInt.size();
        for (int i = 0; i < lengthSize; i++)
        {
            printf("%d\n", lengthInt.at(i));
            result += numsResult.at(lengthInt.at(i));
        }
        return result % dividend;
    }
};

/**
 * 题解有点牛
 * 计算数据就是一个等差数列求和，直接使用等差数列求和公式就可以了 md
 * 以及一次遍历即可，通过一个函数内的变量表示当前第一个字符是什么，如果不同的话
 * 则进行更新，以及计算获取值，相等话就增加次数
*/
class Solution {
public:
    int countHomogenous(string s) {
        long long res = 0;
        long long mod = 1e9 + 7;
        int prev = s[0];
        int cnt = 0;
        for (auto c : s) {
            if (c == prev) {
                cnt++;
            } else {
                res += (long long)(cnt + 1) * cnt / 2;
                cnt = 1;
                prev = c;
            }
        }
        res += (long long)(cnt + 1) * cnt / 2;
        return res % mod;
    }
};

// @lc code=end
