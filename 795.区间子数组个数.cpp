#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

/**
 * 知道哪里有问题了
 * 对于测试案例
 * [73,55,36,5,55,14,9,7,72,52]
 * 我写的东西无法涵盖 [5.55] [5,55,14] [5,55,14,9] [5,55,14,9,7]
 * 
*/
// @lc code=start
class MySolution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int size = nums.size();
        int result = 0;
        int maxInt = -1;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                int num = nums.at(j);
                maxInt = max(maxInt,num);
                printf("all : i : %d,j : %d\n",i,j);
                if (left <= maxInt  && maxInt <= right)
                {
                    printf("in : i : %d,j : %d\n",i,j);
                    result++;
                }
                else
                {
                    break;
                }
            }
            maxInt = -1;
        }
        return result;
    }
};

/**
 * 对于题解的来说，即通过固定右端点，找到符合条件的左端点，左端点到右端点之间的子数组
 * 就是所求的答案，进行统计每个右端点有多少个符合条件的左端点即可
 * 左端点的范围是 last1 - last2
 * 在这个区间内中能够满足条件的个数，只要有 last1 - last2 中的元素就是所求的结果
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, last2 = -1, last1 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= left && nums[i] <= right) {
                last1 = i;
            } else if (nums[i] > right) {
                last2 = i;
                last1 = -1;
            }
            if (last1 != -1) {
                printf("last1 : %d\n",last1);
                printf("last2 : %d\n",last2);
                printf("res += : %d\n",last1-last2);
                res += last1 - last2;
            }
        }
        return res;
    }
};

// @lc code=end

