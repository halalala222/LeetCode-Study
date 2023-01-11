#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int size = pref.size();
        int result = 0;
        for (string word : words)
        {
            int isPref = true;
            if (word.size() < size)
            {
                continue;
            }
            for (int i = 0; i < size; i++)
            {
                if (word.at(i) != pref.at(i))
                {
                    isPref = false;
                    break;
                }
            }
            if (isPref)
                result++;
        }
        return result;
    }
};
/**
 * compare 之前好像见过但是忘记了，可以自动进行比较，不用自己比较
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string & word : words) {
            if (word.compare(0, pref.size(), pref) == 0) {
                res++;
            }
        }
        return res;
    }
};

// @lc code=end
