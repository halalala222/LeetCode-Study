#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
/**
 * 暴力失败
 */
// class Solution
// {
// public:
//     int countTriplets(vector<int> &nums)
//     {
//         int count = 0, size = nums.size();
//         for (int i = 0; i < size; i++)
//         {
//             for (int j = 0; j < size; j++)
//             {
//                 for (int k = 0; k < size; k++)
//                 {
//                     if ((nums.at(i) & nums.at(j) & nums.at(k)) == 0)
//                         count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int size = nums.size();
        unordered_map<int, int> code;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                code[nums.at(i) & nums.at(j)] += 1;
            }
        }
        int result = 0;
        for (int num : nums)
        {
            for (auto &i : code)
            {
                if ((i.first & num) == 0)
                {
                    result += i.second;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int countTriplets(vector<int> &nums) {
        int cnt[1 << 16]{};
        for (int x : nums)
            for (int y : nums)
                ++cnt[x & y];
        int ans = 0;
        for (int m : nums) {
            m ^= 0xffff;
            int s = m;
            do { // 枚举 m 的子集（包括空集）
                ans += cnt[s];
                s = (s - 1) & m;
            } while (s != m);
        }
        return ans;
    }
};

// @lc code=end
