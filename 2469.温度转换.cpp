#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 *
 * [2469] 温度转换
 */

// @lc code=start
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        // vector<double> result;
        // result.push_back(celsius + 273.15);
        // result.push_back(celsius * 1.8 + 32);
        // return result;

        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
// @lc code=end
