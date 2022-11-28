#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */

// @lc code=start
/**
 * 第一想法，分组将所有的最大值进行分组，剩余最小的分一组，平均总会导致值少，所以最少的那些进行平均是
 * 被平均最少的
 * 不行有问题这个得是相邻的，不能不是相邻的所以这个想法有问题
*/
// class Solution {
// public:
//     double largestSumOfAverages(vector<int>& nums, int k) {
//         double result;
//         int size = nums.size();
//         int temp = 0;
//         int count = size - k + 1;
//         printf("count : %d\n",count);
//         sort(nums.begin(),nums.end());
//         for (int i = 0; i < size; i++)
//         {
//             if (i < count)
//             {
//                 printf("%d\n",nums.at(i));
//                 temp += nums.at(i);
//             }
//             else
//             {
//                 result += nums.at(i);
//                 printf("%f\n",result);
//             }
//         }
//         printf("temp : %d\n",temp);
//         result += double(temp) / count;
//         return result;
//     }
// };
/**
 * 动态规划一道数学题目
 * 就像在做数学题一样，md
 * 大概懂了什么意思了
 * dp[i][j]表示数组范围 0 ~ i - 1 这个区间被分成 j 分的最大平均值的和
 * 当 j = 1，的时候表示将 0 ~ i - 1 这个区间的范围的值分成一份，最大平均值的和为所有值之和加起来除以总数
 * 当 j ? 1，的时时候，这个时候就有很多种分配情况。
 * 例子：j = 3,int size = nums.size(),size = 5;
 * nums = [2,6,7,8,9]
 * 将 nums 分成三份可以有很多种情况 
 * 为了求得最大值，将其中合并同类项
 * 1. [2] [6] [7,8,9]
 * // dp[2][2] + (7,8,9) / 3
 * 2. [2] [6,7] [8,9]
 * 3. [2,6] [7] [8,9]
 * // dp[3][2] + (8,9) / 2
 * // 求解 dp[3][2]
 * // [2] [6,7]
 * // dp[1][1] + (6 + 7) / 2
 * // [2,6] [7]
 * // dp[2][1] + 7
 * // max = dp[3][2]
 * 4. [2,6] [7,8] [9]
 * 5. [2] [6,7,8] [9]
 * 6. [2,6,7] [8] [9]
 * 7. [2] [6,7,8] [9]
 * // dp[4][2] + 9 / 1
 * 其中 dp[4][2] dp[2][2] dp[3][2] 都需要根据对应方程进行求解到其中最大值。以保证 dp[5][3] 是最大值
 * 则 dp[5][3] = max(上述条件的所有值)
 * 好难啊，这个玩意纯纯数学题 md 
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {
                for (int x = j - 1; x < i; x++) {
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};

// @lc code=end

