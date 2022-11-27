#include <string>
#include <queue>
#include <unordered_map>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
/**
 * 打算用队列做,队列有问题
*/
// @lc code=start
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         queue<char> result;
//         unordered_map<char,int> counts;
//         for (int i = 0; i < s.length(); i++)
//         {
//             printf("%c\n",s.at(i));
//             counts[s.at(i)]++;
//             int count = counts[result.front()];
//             if (count > 1)
//             {
//                 result.pop();
//             }
//             else if (count == 0)
//             {
//                 result.push(s.at(i));
//             }
//         }
//         return s.find_first_of(result.front());
//     }
// };
/**
 * s 只包含小写字母，可以用一个定长的数组来存储出现的次数
 * 问题在于如何拿到第一个不重复
 * 直接再次循环吧
 * 官方题解也是双循环
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        int size = s.length();
        for (int i = 0; i < size; i++)
        {
            count[s.at(i)]++;
        }
        for (int i = 0; i < size; i++)
        {
            if (count[s.at(i)] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

