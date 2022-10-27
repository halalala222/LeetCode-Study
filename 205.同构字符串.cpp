/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <algorithm>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charToChar;
        unordered_map<char,bool> countChar;
        if (s == t)
        {
            return true;
        }
        if (s.length() != t.length())
        {
            return false;
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            if (!charToChar.count(s[i]))
            {
                if (countChar[t[i]])
                {
                    return false;
                }
                charToChar[s[i]] = t[i];
                countChar[t[i]] = true;
            }
            else
            {
                if (charToChar[s[i]] != t[i])
                {
                    return false;
                }
                
            }
        }
        return true;
    }
};
// @lc code=end

