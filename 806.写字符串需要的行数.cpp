#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result{1,0};
        int curOccupied = 0;
        for (int i = 0; i < s.length(); i++)
        {
            printf("i : %d\n",i);
            int width = widths[s.at(i) - 97];
            curOccupied += width;
            if (curOccupied > 100)
            {
                result.at(0)++;
                curOccupied = width;
            }
        }
        result.at(1) = curOccupied;
        return result;
    }
};
// @lc code=end

