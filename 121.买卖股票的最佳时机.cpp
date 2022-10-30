/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
/*
 * 暴力循环，在10w+测试例子上超时了。第 199 案例
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int pricesSize = prices.size();
//         int biggestProfit = 0;
//         for (int i = 0; i < pricesSize; i++)
//         {
//             for (int j = i + 1; j < pricesSize; j++)
//             {
//                 if (prices[j] - prices[i] > biggestProfit)
//                 {
//                     biggestProfit = prices[j] - prices[i];
//                 }
//             }
//         }
//         return biggestProfit;
//     }
// };
/*
 * 焯，官方题解超时了……………………相似
*/
class StandardArangeSolution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

/*
 * 单循环
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e5;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice,prices[i]);
            maxProfit = max(maxProfit,prices[i] - minPrice);
        }
        return maxProfit;
    }
};

class StandardSimpleSolution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};


// @lc code=end

