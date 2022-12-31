#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2037 lang=cpp
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

// @lc code=start
class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int size = seats.size(), result = 0;
        for (int i = 0; i < size; i++)
        {
            //需要注意绝对值
            result += abs(students.at(i) - seats.at(i));
        }
        return result;
    }
};
// @lc code=end
