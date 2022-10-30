/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <string>
#include <algorithm>
using namespace std;
/*
 * 和题解想法一样
*/
// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> countAppear;
        int length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            countAppear[s[i]] += 1;
            if (countAppear[s[i]] % 2 == 0)
            {
                length += 2;
            }
        }
        unordered_map<char, int>::iterator iter;
        for (iter=countAppear.begin(); iter!=countAppear.end(); iter++)
        {
            if (iter->second % 2 == 1)
            {
                length += 1;
                break;
            }
        }
        return length;
    }
};
// @lc code=end

