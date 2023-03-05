#include <vector>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
// class Solution
// {
// public:
//     int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
//     {
//         // if (boardingCost * 4 <= runningCost)
//         //     return -1;
//         // int waitingCustomer = 0, count = 0, size = customers.size(), i = 0, sumCustomer = 0;
//         // for (int customerNum : customers)
//         // {
//         //     sumCustomer += customerNum;
//         // }
//         /**
//          * 不行还是需要循环，因为如果其中轮到了不足 4 个人的话，是否需要继续进行营业
//          */
//         // for (int customerNum : customers)
//         // {
//         //     waitingCustomer += customerNum;
//         // }
//         // count += waitingCustomer / 4;
//         // if ((waitingCustomer % 4) * boardingCost > runningCost)
//         // {
//         //     count++;
//         // }

//         // for (int i = 0; i < customers.size(); i++)
//         // {
//         //     waitingCustomer += customers.at(i);
//         //     printf("waitingCustomer : %d\n",waitingCustomer);
//         //     if (waitingCustomer >= 4)
//         //     {
//         //         printf("11111111111111111111\n");
//         //         waitingCustomer -= 4;
//         //         count++;
//         //     }
//         //     else
//         //     {
//         //         if (waitingCustomer * boardingCost >= runningCost)
//         //         {
//         //             printf("22222222222222222222\n");
//         //             count++;
//         //         }
//         //     }
//         // }
//         // /**
//         //  * 如何判定是否需要继续继续下去
//         //  * 如果当前 waitingCustomer >= 4即可
//         //  * 如果当前 waitingCusotmer < 4 && customers[i + 1] > 4 即可
//         //  */
//         // for (int i = 0; i < size; i++)
//         // {
//         //     waitingCustomer += customers.at(i);
//         //     while (waitingCustomer >= 4)
//         //     {
//         //         count++;
//         //         waitingCustomer -= 4;
//         //         sumCustomer -= 4;
//         //     }
//         //     if (sumCustomer * boardingCost <= runningCost)
//         //     {
//         //         break;
//         //     }
//         // }
//         // if (waitingCustomer * boardingCost > runningCost)
//         // {
//         //     count++;
//         // }

//     }
// };
/**
 * 真奇怪，我是真理解不来了这个玩意儿………………………………，有病
*/
class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        int max_val = 0;           // 利润初始为0
        int steps = -1;            // 步数为-1
        int ground = 0, board = 0; // 地上0人，上过车的人总数
        for (int i = 0; i < customers.size() or ground > 0; ++i)
        {
            if (i < customers.size())
                ground += customers[i]; // 新一批游客到来
            if (ground >= 4)
            {                // 地上游客多于4
                ground -= 4; // 4人上车
                board += 4;  // 坐过车的人 + 4
            }
            else
            {
                board += ground; // 地上人都上车
                ground = 0;      // 地上没人
            }
            if (board * boardingCost - runningCost * (i + 1) > max_val)
            { // 更新答案，上过车的人 * 上车费 - 当前转过的次数 * 转车费
                steps = i + 1;
                max_val = board * boardingCost - runningCost * (i + 1);
            }
        }
        return steps;
    }
};
// @lc code=end
