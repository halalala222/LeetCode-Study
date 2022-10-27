/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int maxIndex = 0;
        if (s.length() > t.length())
        {
            return false;
        }
        if (s == t)
        {
            return true;
        }
        for (int i = 0; i < s.length(); i++)
        {
            int index;
            if (maxIndex != 0)
            {
                index = t.find(s[i],maxIndex+1);
            }
            else
            {
                index = t.find(s[i]);
            }
            if (index == 0 || index > maxIndex)
            {
                maxIndex = index;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

