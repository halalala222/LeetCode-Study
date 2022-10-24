/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <string> 
#include <algorithm>
// @lc code=start
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        string stringStd = to_string(x);
        string reverseString = stringStd;
        reverse(reverseString.begin(),reverseString.end());
        if(stringStd != reverseString)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
