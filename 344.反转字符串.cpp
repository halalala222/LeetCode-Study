#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0,j = n - 1; i <= j; i++,j--)
        {
            char tmep = s[i];
            s[i] = s[j];
            s[j] = tmep;
        }
    }
};
// @lc code=end
/*
 * 题解的 swap 函数没见过没用过，估计是一个交换的函数。以后可以用一下
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left < right; ++left, --right) {
            swap(s[left], s[right]);
        }
    }
};
