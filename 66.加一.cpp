/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 写之前想到的需要注意的点，逢十进一
*/
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        digits.push_back(0);
        for (int i = 0; i < digits.size() - 1; i++)
        {
            if (i == 0)
            {
                digits[0] += 1;
            }
            if (digits[i] == 10)
            {
                digits[i] = 0;
                digits[i + 1] += 1;
            }
        }
        reverse(digits.begin(),digits.end());
        if (digits[0] == 0)
        {
            vector<int>::iterator begin = digits.begin();
            digits.erase(begin);
        }
        return digits;
    }
};
/*
 * 官方题解的做法是根据其中会出现的情况进行处理。
 * 总的情况分俩种要不要返回长度+1的数组
 * 1. 如果有存在不为 9 的，将该数 + 1；该数之后的数据置为0
 * 2. 如果存在都为 9 的，直接返回一个长度+1的数组，第一位为1
*/
class StandardSolution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};

// @lc code=end

