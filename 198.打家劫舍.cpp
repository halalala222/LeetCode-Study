#include <vector>
#include <stdio.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

/**
 * easy
 * 第二次修改，是因为发现到一个测试数据
 * 2 1 1 2 最大值为 4
 * 所以想到的是因为最后一位 2 的最大值取决于 2 1 的最大值决定的，因为不能相邻，所以
 * 其位置 -1 之前的位置都可以，则取其中最大值即可
 * 查看了一下官方的想法，我发现比我想得更加细致一点
 * 在当前位置 k 有俩种情况：
 * 1. 选当前位置 k ，即此时的金额为 k - 2 + nums.at(k) 
 * 2. 不选当前位置 k，即此时的金额为 dp[k - 1] ,即在 k - 1 时最大值
 * 只需要一次时间复杂度即可
*/ 
// @lc code=start
class MySolution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> money(size+1);
        if (size == 1)
        {
            return nums.at(0);
        }
        money.at(0) = nums.at(0);
        money.at(1) = nums.at(1);
        for (int i = 2; i < size; i++)
        {
            int maxMoney = 0;
            for (int j = 0; j < i - 1; j++)
            {
                maxMoney = max(money[j],maxMoney);
            }
            money[i] = maxMoney + nums.at(i);
        }
        return max(money.at(size - 1),money.at(size - 2));
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> money(size+1);
        if (size == 0)
        {
            return size;
        }
        
        if (size == 1)
        {
            return nums.at(0);
        }
        money.at(0) = nums.at(0);
        // 这里也需要按照上面的思想进行处理一下
        // 改成
        money.at(1) = max(nums.at(0),nums.at(1));
        for (int i = 2; i < size; i++)
        {
            money.at(i) = max((money.at(i - 2) + nums.at(i)),money.at(i - 1));
        }
        return money.at(size - 1);
    }
};
// @lc code=end

