#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution
{
public:
    int countEven(int num)
    {
        int result = 0;
        for (int i = 1; i < num + 1; i++)
        {
            int cur = i, sum;
            printf("i : %d\n", i);
            while (cur)
            {
                printf("cur : %d\n", cur);
                sum += (cur % 10);
                cur /= 10;
            }
            if (sum % 2 == 0)
            {
                result++;
            }
            sum = 0;
        }
        return result;
    }
};

/**
 * 高雅的数学解法
*/
class Solution {
public:
    int countEven(int num) {
        int y = num / 10, x = num % 10;
        int res = y * 5, ySum = 0;
        while (y) {
            ySum += y % 10;
            y /= 10;
        }
        //例子：12x 如果和为偶数的话，需要 x 为奇数，那么在[0,x] 中奇数的个数为
        // x / 2,
        //同理可得：11x 如果和为偶数的话，需要 x 为偶数，那么在 [0,x] 中的偶数的个数为
        // x / 2 + 1
        if (ySum % 2 == 0) {
            res += x / 2 + 1;
        } else {
            res += (x + 1) / 2;
        }
        //因为 0 也是偶数，所以要把 0 排除
        return res - 1;
    }
};
// @lc code=end
