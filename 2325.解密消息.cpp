#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        string result = "";
        int count = 0;
        vector<int> nums(26, -1);
        for (auto c : key)
        {
            if (c == ' ')
                continue;
            int index = c - 'a';
            printf("index : %d,char : %c,count : %d\n", index, c, count);
            if (nums.at(index) == -1)
                nums.at(index) = count++;
        }
        for (auto c : message)
        {
            char resultChar = c == ' ' ? ' ' : nums.at(c - 'a') + 'a';
            result.push_back(resultChar);
        }
        return result;
    }
};
// @lc code=end
