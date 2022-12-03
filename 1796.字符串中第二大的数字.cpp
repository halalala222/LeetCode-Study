#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class MySolution
{
public:
    int secondHighest(string s)
    {
        int length = s.length();
        vector<int> isAppeared(10, 0);
        vector<int> nums;
        for (int i = 0; i < length; i++)
        {
            if ('0' <= s.at(i) && s.at(i) <= '9' && isAppeared.at(s.at(i) - 48) == 0)
            {
                nums.push_back(s.at(i) - 48);
                isAppeared.at(s.at(i) - 48) = 1;
            }
        }
        int size = nums.size();
        if (size <= 1)
        {
            return -1;
        }
        sort(nums.begin(),nums.end());
        return nums.at(size - 2);
    }
};

/**
 * 维护俩个常量
 * largest 表示最大的数
 * secondeLargest 表示第二大的数
 * 如果有一个数比 largest 还大的话
 * largest = num
 * secondeLargest = largest
*/
class Solution
{
public:
    int secondHighest(string s)
    {
        int length = s.length();
        int largest = -1,secondLargest = -1;
        for (int i = 0; i < length; i++)
        {
            char curChar = s.at(i);
            if ('0' <= curChar && curChar <= '9')
            {
                int num = curChar - 48;
                // 测试数据中还是会有问题出现："sjhtz8344" 按照这个条件控制的话，就会导致，secondLargest 一直无法更新，所以需要判断条件一下
                if (largest < num)
                {
                    printf("num : %d,largest : %d,secondLargest : %d\n",num,largest,secondLargest);
                    secondLargest = largest;
                    largest = num;
                }
                // 避免导致，largest 已经是最大值了，导致后续 secondlargest 无法被更新
                else if (num < largest && secondLargest < num)
                {
                    secondLargest = num;
                }
                
            }
        }
        return secondLargest;
    }
};
// @lc code=end
