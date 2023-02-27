#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

/**
 * 没有想到什么好做法的题目，尝试一次遍历求出俩个结果的值
 * 理解错题目了
 */
// @lc code=start
class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int size = nums.size(), station1 = 0, station2 = 0;
        vector<int> numsCopy(0);
        for (int num : nums)
        {
            numsCopy.push_back(num);
        }
        for (int i = 0; i < size; i++)
        {
            if (i % 2)
            {
                if (i != size - 1 && nums.at(i + 1) >= nums.at(i))
                {
                    int temp = nums.at(i + 1) - nums.at(i) + 1;
                    nums.at(i + 1) -= temp;
                    station1 += temp;
                }
                if (nums.at(i - 1) >= nums.at(i))
                {
                    int temp = nums.at(i - 1) - nums.at(i) + 1;
                    nums.at(i - 1) -= temp;
                    station1 += temp;
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (!(i % 2))
            {

                if (i != size - 1 && numsCopy.at(i + 1) >= numsCopy.at(i))
                {
                    printf("i : %d,pre : %d,current : %d        ", i, numsCopy.at(i + 1), numsCopy.at(i));
                    int temp = numsCopy.at(i + 1) - numsCopy.at(i) + 1;
                    numsCopy.at(i + 1) -= temp;
                    station2 += temp;
                }
                if (i != 0 && numsCopy.at(i - 1) >= numsCopy.at(i))
                {
                    printf("i : %d,last : %d,current : %d        ", i, numsCopy.at(i - 1), numsCopy.at(i));
                    int temp = numsCopy.at(i - 1) - numsCopy.at(i) + 1;
                    numsCopy.at(i - 1) -= temp;
                    station2 += temp;
                }
            }
        }

        // for (int i = 0; i < size; i++)
        // {
        //     int tempCount = 0, current = nums.at(i);
        //     if ((i == 0) && (nums.at(i + 1) > current))
        //     {
        //         printf("1");
        //         tempCount += nums.at(i + 1) - current + 1;
        //         nums.at(i + 1) -= tempCount;
        //     }

        //     if ((i == size - 1) && (nums.at(i - 1) > current))
        //     {
        //         printf("2");
        //         tempCount += nums.at(i - 1) - current + 1;
        //         nums.at(i - 1) -= tempCount;
        //     }
        //     if (i < size - 1 && i > 0)
        //     {
        //         printf("3");
        //         int last = nums.at(i - 1), pre = nums.at(i + 1);
        //         if (last > current)
        //         {
        //             tempCount += last - current + 1;
        //             nums.at(i - 1) -= tempCount;
        //         }

        //         if (pre > current)
        //         {
        //             tempCount += pre - current + 1;
        //             nums.at(i + 1) -= tempCount;
        //         }
        //     }
        //     (i % 2) ? station1 += tempCount : station2 += tempCount;
        /**
         * 这样子会导致有的无法遍历到
         */
        // if (i != size - 1)
        // {
        //     printf("1");
        //     if (nums.at(i - 1) - nums.at(i))
        //         station1 += (nums.at(i - 1) - nums.at(i) + 1);
        //     if ((nums.at(i + 1) - nums.at(i)))
        //         station1 += (nums.at(i + 1) - nums.at(i) + 1);
        // }
        // else
        // {
        //     printf("2");
        //     if ((nums.at(i - 1) - nums.at(i)))
        //         station1 += (nums.at(i - 1) - nums.at(i) + 1);
        // }
        // if (i - 1 != 0)
        // {
        //     printf("3");
        //     if (nums.at(i) - nums.at(i - 1))
        //         station2 += (nums.at(i) - nums.at(i - 1) + 1);
        //     if (nums.at(i - 2) - nums.at(i - 1))
        //         station2 += (nums.at(i - 2) - nums.at(i - 1) + 1);
        // }
        // else
        // {
        //     printf("4");
        //     if (nums.at(i) - nums.at(i - 1))
        //         station2 += (nums.at(i) - nums.at(i - 1) + 1);
        // }
        /**
         * 边界处理比我好太多了
        */
        class Solution
        {
        public:
            int help(vector<int> &nums, int pos)
            {
                int res = 0;
                for (int i = pos; i < nums.size(); i += 2)
                {
                    int a = 0;
                    if (i - 1 >= 0)
                    {
                        a = max(a, nums[i] - nums[i - 1] + 1);
                    }
                    if (i + 1 < nums.size())
                    {
                        a = max(a, nums[i] - nums[i + 1] + 1);
                    }
                    res += a;
                }
                return res;
            }

            int movesToMakeZigzag(vector<int> &nums)
            {
                return min(help(nums, 0), help(nums, 1));
            }
        };

        printf("station1 : %d,station2 : %d\n", station1, station2);
        return min(station1, station2);
    }
};
// @lc code=end
