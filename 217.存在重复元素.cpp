#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
/**
 * 第一个暴力搜索
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> isExit;
        for (int i = 0; i < size; i++)
        {
            isExit[nums.at(i)]++;
        }
        for (int i = 0; i < size; i++)
        {
            if (isExit[nums.at(i)] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
/**
 * 使用 set 通过 set 判断长度直接解决，🐂
*/

class StandarSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
};
// @lc code=end

