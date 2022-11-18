#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2165 lang=cpp
 *
 * [2165] 重排数字的最小值
 */

/*
 * 如果对于负数的话，取数的最大值只有返回其相反数
 * 如果对于正数的话，取数的最小值直接返回即可
 * 看了下题解，感觉挺对的，因为我没有处理好前置0的问题，他是通过循环找到一个最小的非零数进行对调
*/
// @lc code=start
class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> nums;
        long long result = 0;
        bool isPositive = num > 0 ? true : false;
        long long positiveNum = isPositive ? num : -num;
        while (positiveNum)
        {
            nums.push_back(positiveNum%10);
            positiveNum /= 10;     
        }
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            printf("%d\n",nums.at(i));
        }
        if (isPositive)
        {
            if (!nums.at(0))
            {
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums.at(i))
                    {
                        swap(nums[0],nums[i]);
                        break;
                    }
                }
                
            }
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
        for (int i = 0; i < nums.size(); i++)
        {
            result = result * 10 + nums.at(i);
        }
            
        return isPositive ? result : -result;
    }
};
// @lc code=end

