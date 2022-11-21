#include <vector>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
/**
 * 在 44 这里超时了
 * 针对这一版我感觉可以优化的地方在于，可以将每次的数据都存储起来，就不用再次递归调用
 * 进行重新获取
 * 45/45 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 14.42 % of cpp submissions (6.1 MB)
 * 我超，吊
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n + 1);
        result.at(0) = 1;
        result.at(1) = 1;
        for (int i = 2; i <= n; i++)
        {
            result.at(i) = result.at(i - 1) + result.at(i - 2);
        }
        return result.at(n);
    }
};
/**
 * 看了下官方题解给出来的动态规划
 * 
*/

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
// @lc code=end

