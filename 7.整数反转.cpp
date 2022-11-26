#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
/**
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 * 漏了一句话，如果超过限制的话就返回
*/
// @lc code=start
/**
 * 官方题解中把除和乘放在一个循环里面，我觉得很有道理，因为没有
 * 说要换顺序
*/
class MySolution {
public:
    int reverse(int x) {
        vector<int> nums;
        int result = 0;
        bool isNegative = x < 0 ? true : false;
        x = isNegative ? -x : x;
        while (x)
        {
            int temp = x % 10;
            nums.push_back(temp);
            x /= 10;
        }
        // std::reverse(nums.begin(),nums.end());
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            result = result * 10 + nums.at(i);
        }
        return isNegative ? -result : result;
    }
};
/**
 * 比我的优雅，以及能够处理到超过限制，而我没有处理好
*/
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};
// @lc code=end

